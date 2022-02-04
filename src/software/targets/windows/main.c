#include <stdbool.h>
#include <windows.h>
#include "../../applications/loop.h"
#include "window.h"
#include "display.h"

HINSTANCE qm_windows_main_hinstance;
int qm_windows_main_ncmdshow;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
  qm_windows_main_hinstance = hInstance;
  qm_windows_main_ncmdshow = nCmdShow;

  qm_windows_window_initialize();
  qm_windows_display_initialize();

  while (true) {
    qm_loop();
  }
}
