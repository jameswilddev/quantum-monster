#include <stdbool.h>
#include <windows.h>
#include "window.h"
#include "main.h"
#include "display.h"
#include "../display.h"
#include "sleep.h"

HWND qm_windows_window_hwnd = NULL;

// TODO
#define PIXEL_ASPECT_RATIO_NUMERATOR 5
#define PIXEL_ASPECT_RATIO_DENOMINATOR 4

static LRESULT CALLBACK qm_windows_window_procedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg) {
    case WM_PAINT:
      qm_windows_display_blit(true);
      return 0;

    case WM_SIZE:
      // TODO more here to handle resizing?
      // TODO disallow maximise

      InvalidateRect(hwnd, NULL, FALSE);
      return 0;

    case WM_TIMER:
      if (qm_windows_sleep_timer != 0) {
        // TODO return value
        KillTimer(hwnd, qm_windows_sleep_timer);
        qm_windows_sleep_timer = 0;
      }
      return 0;

    case WM_GETMINMAXINFO: {
      LPMINMAXINFO lpMMI = (LPMINMAXINFO)lParam;
      lpMMI->ptMinTrackSize.x = QM_DISPLAY_WIDTH * PIXEL_ASPECT_RATIO_NUMERATOR;
      lpMMI->ptMinTrackSize.y = QM_DISPLAY_HEIGHT * PIXEL_ASPECT_RATIO_DENOMINATOR;

      float maximum_x_scale = (float)GetSystemMetrics(SM_CXMAXTRACK) / QM_DISPLAY_WIDTH / ((float)PIXEL_ASPECT_RATIO_NUMERATOR / PIXEL_ASPECT_RATIO_DENOMINATOR);
      float maximum_y_scale = (float)GetSystemMetrics(SM_CYMAXTRACK) / QM_DISPLAY_HEIGHT;
      float maximum_scale = min(maximum_x_scale, maximum_y_scale);

      lpMMI->ptMaxTrackSize.x = maximum_scale * QM_DISPLAY_WIDTH * PIXEL_ASPECT_RATIO_NUMERATOR / PIXEL_ASPECT_RATIO_DENOMINATOR;
      lpMMI->ptMaxTrackSize.y = maximum_scale * QM_DISPLAY_HEIGHT;

      return 0;
    }

    case WM_SIZING: {
      PRECT outer = (PRECT)lParam;

      RECT insets = {
        GetSystemMetrics(SM_CXSIZEFRAME),
        GetSystemMetrics(SM_CYCAPTION),
        GetSystemMetrics(SM_CXSIZEFRAME),
        GetSystemMetrics(SM_CYSIZEFRAME)
      };

      RECT inner = {
        outer->left + insets.left,
        outer->top + insets.top,
        outer->right - insets.right,
        outer->bottom - insets.bottom
      };

      int inner_width = inner.right - inner.left;
      int inner_height = inner.bottom - inner.top;

      switch (wParam) {
        case WMSZ_TOP:
        case WMSZ_BOTTOM: {
          int scaled_inner_width = inner_height * QM_DISPLAY_WIDTH * PIXEL_ASPECT_RATIO_NUMERATOR / QM_DISPLAY_HEIGHT / PIXEL_ASPECT_RATIO_DENOMINATOR;

          int width_change = scaled_inner_width - inner_width;

          outer->left -= width_change / 2;
          outer->right += width_change / 2;
          break;
        }

        case WMSZ_LEFT:
        case WMSZ_RIGHT: {
          int scaled_inner_height = inner_width * QM_DISPLAY_HEIGHT * PIXEL_ASPECT_RATIO_DENOMINATOR / QM_DISPLAY_WIDTH / PIXEL_ASPECT_RATIO_NUMERATOR;

          int height_change = scaled_inner_height - inner_height;

          outer->top -= height_change / 2;
          outer->bottom += height_change / 2;
          break;
        }

        case WMSZ_BOTTOMLEFT:
        case WMSZ_BOTTOMRIGHT:
        case WMSZ_TOPLEFT:
        case WMSZ_TOPRIGHT: {
          float x_scale_factor = (float)inner_width / ((float)QM_DISPLAY_WIDTH * ((float)PIXEL_ASPECT_RATIO_NUMERATOR / PIXEL_ASPECT_RATIO_DENOMINATOR));
          float y_scale_factor = (float)inner_height / QM_DISPLAY_HEIGHT;

          float scale_factor = max(x_scale_factor, y_scale_factor);

          int scaled_inner_width = scale_factor * QM_DISPLAY_WIDTH * PIXEL_ASPECT_RATIO_NUMERATOR / PIXEL_ASPECT_RATIO_DENOMINATOR;
          int scaled_inner_height = scale_factor * QM_DISPLAY_HEIGHT;

          int width_change = scaled_inner_width - inner_width;
          int height_change = scaled_inner_height - inner_height;

          switch (wParam) {
            case WMSZ_BOTTOMLEFT:
              outer->bottom += height_change;
              outer->left -= width_change;
              break;

            case WMSZ_BOTTOMRIGHT:
              outer->bottom += height_change;
              outer->right += width_change;
              break;

            case WMSZ_TOPLEFT:
              outer->top -= height_change;
              outer->left -= width_change;
              break;

            case WMSZ_TOPRIGHT:
              outer->top -= height_change;
              outer->right += width_change;
              break;
          }

          break;
        }
      }

      return 0;
    }

    case WM_DESTROY:
      exit(0);

    default:
      return DefWindowProc(hwnd, uMsg, wParam, lParam);
  }
}

void qm_windows_window_initialize()
{
  WNDCLASS wc = { };

  wc.lpfnWndProc = qm_windows_window_procedure;
  wc.hInstance = qm_windows_main_hinstance;
  wc.lpszClassName = "Quantum Monster";

  RegisterClass(&wc);

  qm_windows_window_hwnd = CreateWindowEx(
    0,
    "Quantum Monster",
    "Quantum Monster",
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    QM_DISPLAY_WIDTH * PIXEL_ASPECT_RATIO_NUMERATOR,
    QM_DISPLAY_WIDTH * PIXEL_ASPECT_RATIO_DENOMINATOR,
    NULL,
    NULL,
    qm_windows_main_hinstance,
    NULL
  );

  ShowWindow(qm_windows_window_hwnd, qm_windows_main_ncmdshow);
}
