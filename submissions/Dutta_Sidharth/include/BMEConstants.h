#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    constexpr uint32_t SERIAL_BAUD = 115200;

    constexpr uint8_t I2C_ADDRESS_PRIMARY = 0x77;
    constexpr uint8_t I2C_ADDRESS_SECONDARY = 0x76;

    constexpr uint8_t SPI_CS_PIN = 10;

    constexpr uint8_t LED_PIN = 8;

    constexpr float MIN_TEMP_C = 20.0f;
    constexpr float MAX_TEMP_C = 40.0f;

    constexpr uint32_t SLOW_TOGGLE_INTERVAL_MS = 1000;
    constexpr uint32_t FAST_TOGGLE_INTERVAL_MS = 100;

    constexpr uint32_t SENSOR_READ_PERIOD_MS = 250;
}
