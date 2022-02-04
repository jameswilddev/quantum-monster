#include <stdbool.h>
#include <windows.h>
#include "../error.h"
#include "../sleep.h"
#include "../../library/delay.h"
#include "../../library/time_of_day.h"
#include "window.h"
#include "display.h"
#include "sleep.h"

UINT_PTR qm_windows_sleep_timer = 0;

qm_sleep_wake_reason_t qm_sleep(qm_sleep_wake_reason_t wake_reasons, qm_time_of_day_t time_of_day, qm_delay_t delay)
{
  if (wake_reasons == 0) {
    qm_error("Call to qm_sleep without any wake reasons.");
  } else if (wake_reasons & ~(QM_SLEEP_WAKE_REASON_DELAY | QM_SLEEP_WAKE_REASON_TIME_OF_DAY | QM_SLEEP_WAKE_REASON_A_BUTTON_DOWN | QM_SLEEP_WAKE_REASON_A_BUTTON_UP | QM_SLEEP_WAKE_REASON_B_BUTTON_DOWN | QM_SLEEP_WAKE_REASON_B_BUTTON_UP | QM_SLEEP_WAKE_REASON_C_BUTTON_DOWN | QM_SLEEP_WAKE_REASON_C_BUTTON_UP)) {
    qm_error("Call to qm_sleep with unsupported wake reason(s).");
  } else if (wake_reasons & QM_SLEEP_WAKE_REASON_DELAY && (delay < QM_DELAY_MIN || delay > QM_DELAY_MAX)) {
    qm_error("Call to qm_sleep with delays enabled but an out-of-range delay value.");
  } else if (wake_reasons & QM_SLEEP_WAKE_REASON_TIME_OF_DAY && (time_of_day < QM_TIME_OF_DAY_MIN || time_of_day > QM_TIME_OF_DAY_MAX)) {
    qm_error("Call to qm_sleep with time-of-day enabled but an out-of-range time-of-day value.");
  } else {
    DWORD sleep_started_at = GetTickCount();

    while (true) {
      DWORD now = GetTickCount();

      qm_sleep_wake_reason_t met_criteria = 0;

      // TODO: set bits

      met_criteria |= GetKeyState('Q') & 32768 ? QM_SLEEP_WAKE_REASON_A_BUTTON_DOWN : QM_SLEEP_WAKE_REASON_A_BUTTON_UP;
      met_criteria |= GetKeyState('A') & 32768 ? QM_SLEEP_WAKE_REASON_B_BUTTON_DOWN : QM_SLEEP_WAKE_REASON_B_BUTTON_UP;
      met_criteria |= GetKeyState('Z') & 32768 ? QM_SLEEP_WAKE_REASON_C_BUTTON_DOWN : QM_SLEEP_WAKE_REASON_C_BUTTON_UP;

      // todo handle rollover
      if (now >= sleep_started_at + delay) {
        met_criteria |= QM_SLEEP_WAKE_REASON_DELAY;
      }

      met_criteria &= wake_reasons;

      if (met_criteria) {
        return met_criteria;
      } else {
        if (wake_reasons & QM_SLEEP_WAKE_REASON_DELAY) {
          if (wake_reasons & QM_SLEEP_WAKE_REASON_TIME_OF_DAY) {
            // TODO
          } else {
            // TODO return
            // TODO handle rollover
            qm_windows_sleep_timer = SetTimer(qm_windows_window_hwnd, 1, sleep_started_at + delay - now, NULL);
          }
        } else {
          if (wake_reasons & QM_SLEEP_WAKE_REASON_TIME_OF_DAY) {
            // TODO
          }
        }

        // TODO: set up delay
        // TODO: set up time of day

        MSG msg = { };

        GetMessage(&msg, NULL, 0, 0);

        TranslateMessage(&msg);
        DispatchMessage(&msg);

        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
          TranslateMessage(&msg);
          DispatchMessage(&msg);
        }

        if (qm_windows_sleep_timer != 0) {
          // TODO
          KillTimer(qm_windows_window_hwnd, qm_windows_sleep_timer);
          qm_windows_sleep_timer = 0;
        }
      }
    }
  }
}
