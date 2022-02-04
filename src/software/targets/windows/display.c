#include <stdbool.h>
#include <stdint.h>
#include <windows.h>
#include "../display.h"
#include "../error.h"
#include "window.h"
#include "../../library/math.h"

static HDC qm_windows_display_hdc;
static BITMAPINFO * qm_windows_display_bitmapinfo;
static uint8_t qm_windows_display_framebuffer[QM_MATH_ROUND_UP(QM_DISPLAY_WIDTH / 8, 4) * QM_DISPLAY_HEIGHT];
static bool qm_windows_display_invalidated = true;

void qm_windows_display_initialize()
{
  qm_windows_display_bitmapinfo = malloc(sizeof(BITMAPINFO) + sizeof(RGBQUAD) * 2);

  if (qm_windows_display_bitmapinfo) {
    qm_windows_display_bitmapinfo->bmiHeader.biSize = sizeof(BITMAPINFO);
    qm_windows_display_bitmapinfo->bmiHeader.biWidth = QM_DISPLAY_WIDTH;
    qm_windows_display_bitmapinfo->bmiHeader.biHeight = -QM_DISPLAY_HEIGHT;
    qm_windows_display_bitmapinfo->bmiHeader.biPlanes = 1;
    qm_windows_display_bitmapinfo->bmiHeader.biBitCount = 1;
    qm_windows_display_bitmapinfo->bmiHeader.biCompression = BI_RGB;
    qm_windows_display_bitmapinfo->bmiHeader.biSizeImage = 0;
    qm_windows_display_bitmapinfo->bmiHeader.biXPelsPerMeter = 0;
    qm_windows_display_bitmapinfo->bmiHeader.biYPelsPerMeter = 0;
    qm_windows_display_bitmapinfo->bmiHeader.biClrUsed = 2;
    qm_windows_display_bitmapinfo->bmiHeader.biClrImportant = 0;

    // TODO: I expected this to be indices 0 and 1 - why is it 1 and 2?
    qm_windows_display_bitmapinfo->bmiColors[1].rgbBlue = 0;
    qm_windows_display_bitmapinfo->bmiColors[1].rgbGreen = 0;
    qm_windows_display_bitmapinfo->bmiColors[1].rgbRed = 0;
    qm_windows_display_bitmapinfo->bmiColors[1].rgbReserved = 0;
    qm_windows_display_bitmapinfo->bmiColors[2].rgbBlue = 255;
    qm_windows_display_bitmapinfo->bmiColors[2].rgbGreen = 255;
    qm_windows_display_bitmapinfo->bmiColors[2].rgbRed = 255;
    qm_windows_display_bitmapinfo->bmiColors[2].rgbReserved = 0;

  // TODO not needed
    qm_windows_display_hdc = GetDC(qm_windows_window_hwnd);

    if (qm_windows_display_hdc == NULL) {
      qm_error("Failed to retrieve a handle to the window's device context.");
    }
  } else {
    qm_error("Failed to allocate memory for a display bitmap.");
  }
}

void qm_windows_display_blit(bool force)
{
  if (qm_windows_display_invalidated || force) {
    // TODO error handling
    PAINTSTRUCT paint;
    HDC hdc = BeginPaint(qm_windows_window_hwnd, &paint);

    RECT client_rect;
    GetClientRect(qm_windows_window_hwnd, &client_rect);

    if (StretchDIBits(
      hdc,
      0,
      0,
      client_rect.right - client_rect.left,
      client_rect.bottom - client_rect.top,
      0,
      0,
      QM_DISPLAY_WIDTH,
      QM_DISPLAY_HEIGHT,
      qm_windows_display_framebuffer,
      qm_windows_display_bitmapinfo,
      DIB_RGB_COLORS,
      SRCCOPY
    ) == 0) {
      qm_error("Failed to blit the framebuffer.");
    } else {
      EndPaint(qm_windows_window_hwnd, &paint);

      qm_windows_display_invalidated = false;
    }
  }
}

void qm_display(const uint8_t pixels[QM_DISPLAY_WIDTH * QM_DISPLAY_HEIGHT / 8])
{
  // TODO: display off

  for (int y = 0; y < QM_DISPLAY_HEIGHT; y++) {
    memcpy(
      &qm_windows_display_framebuffer[QM_MATH_ROUND_UP(QM_DISPLAY_WIDTH / 8, 4) * y],
      &pixels[QM_DISPLAY_WIDTH / 8 * y],
      QM_DISPLAY_WIDTH / 8
    );
  }

  qm_windows_display_invalidated = true;

  InvalidateRect(qm_windows_window_hwnd, NULL, FALSE);
}
