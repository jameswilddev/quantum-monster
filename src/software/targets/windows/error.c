#include <windows.h>
#include "../error.h"
#include "window.h"

void qm_error(const char * message)
{
  MessageBox(qm_windows_window_hwnd, message, "Quantum Monster", MB_OK | MB_ICONERROR);
  exit(1);
}
