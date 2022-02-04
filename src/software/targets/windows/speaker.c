#include <stdint.h>
#include <windows.h>
#include "../speaker.h"
#include "../error.h"

static uint32_t qm_windows_speaker_current_sample_rate = 0;

// TODO http://www.topherlee.com/software/pcm-tut-wavformat.html
static uint8_t qm_windows_speaker_wave[] = {
  'R', 'I', 'F', 'F',
  52, 0, 0, 0,        // Overall size - 8.
  'W', 'A', 'V', 'E',
  'f', 'm', 't', 32,
  16, 0, 0, 0,        // Length of format data.
  1, 0,               // PCM format.
  1, 0,               // Number of channels.
  0, 0, 0, 0,         // Sample rate.
  0, 0, 0, 0,         // Bytes per second.
  1, 0,               // Bytes per sample.
  8, 0,               // Bits per sample per channel.
  'd', 'a', 't', 'a',
  16, 0, 0, 0,         // Data length.

  // Data content.
  112, 112, 112, 112, 112, 112, 112, 112, 144, 144, 144, 144, 144, 144, 144, 144,
};

void qm_speaker_mute()
{
  if (qm_windows_speaker_current_sample_rate != 0) {
    if (PlaySound(NULL, NULL, 0)) {
      qm_windows_speaker_current_sample_rate = 0;
    } else {
      qm_error("Failed to mute the speaker.");
    }
  }
}

void qm_speaker_play(qm_frequency_t frequency)
{
  uint32_t sample_rate = frequency * 16;

  if (sample_rate != qm_windows_speaker_current_sample_rate) {
    qm_windows_speaker_wave[24] = sample_rate & 255;
    qm_windows_speaker_wave[25] = (sample_rate >> 8) & 255;
    qm_windows_speaker_wave[26] = (sample_rate >> 16) & 255;
    qm_windows_speaker_wave[27] = (sample_rate >> 24) & 255;
    qm_windows_speaker_wave[28] = sample_rate & 255;
    qm_windows_speaker_wave[29] = (sample_rate >> 8) & 255;
    qm_windows_speaker_wave[30] = (sample_rate >> 16) & 255;
    qm_windows_speaker_wave[31] = (sample_rate >> 24) & 255;

    if (PlaySound(qm_windows_speaker_wave, NULL, SND_ASYNC | SND_LOOP | SND_MEMORY)) {
      qm_windows_speaker_current_sample_rate = sample_rate;
    } else {
      qm_error("Failed to play sound.");
    }
  }
}
