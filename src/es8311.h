/*
 * SPDX-FileCopyrightText: 2015-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief ES8311 driver
 */

#pragma once


/* ES8311 address: CE pin low - 0x18, CE pin high - 0x19 */
#define ES8311_ADDRRES_0 0x18u
#define ES8311_ADDRESS_1 0x19u

typedef enum {
    ES8311_MIC_GAIN_MIN = -1,
    ES8311_MIC_GAIN_0DB,
    ES8311_MIC_GAIN_6DB,
    ES8311_MIC_GAIN_12DB,
    ES8311_MIC_GAIN_18DB,
    ES8311_MIC_GAIN_24DB,
    ES8311_MIC_GAIN_30DB,
    ES8311_MIC_GAIN_36DB,
    ES8311_MIC_GAIN_42DB,
    ES8311_MIC_GAIN_MAX
} es8311_mic_gain_t;

typedef enum {
    ES8311_FADE_OFF = 0,
    ES8311_FADE_4LRCK, // 4LRCK means ramp 0.25dB/4LRCK
    ES8311_FADE_8LRCK,
    ES8311_FADE_16LRCK,
    ES8311_FADE_32LRCK,
    ES8311_FADE_64LRCK,
    ES8311_FADE_128LRCK,
    ES8311_FADE_256LRCK,
    ES8311_FADE_512LRCK,
    ES8311_FADE_1024LRCK,
    ES8311_FADE_2048LRCK,
    ES8311_FADE_4096LRCK,
    ES8311_FADE_8192LRCK,
    ES8311_FADE_16384LRCK,
    ES8311_FADE_32768LRCK,
    ES8311_FADE_65536LRCK
} es8311_fade_t;

typedef enum es8311_resolution_t {
    ES8311_RESOLUTION_16 = 16,
    ES8311_RESOLUTION_18 = 18,
    ES8311_RESOLUTION_20 = 20,
    ES8311_RESOLUTION_24 = 24,
    ES8311_RESOLUTION_32 = 32
} es8311_resolution_t;

typedef struct es8311_clock_config_t {
    bool mclk_inverted;
    bool sclk_inverted;
    bool mclk_from_mclk_pin; // true: from MCLK pin (pin no. 2), false: from SCLK pin (pin no. 6)
    int  mclk_frequency;     // This parameter is ignored if MCLK is taken from SCLK pin
    int  sample_frequency;   // in Hz
} es8311_clock_config_t;

void es8311_init(const std::uint32_t sample_rate, es8311_resolution_t res);
void es8311_voice_volume_set(int volume, int *volume_set);
void es8311_microphone_config(bool digital_mic);

void pi4ioe_init();
void pi4ioe_setMute(bool mute);
