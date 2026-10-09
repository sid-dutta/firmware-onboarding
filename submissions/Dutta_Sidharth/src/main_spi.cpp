#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

static uint32_t last_read_ms = 0;

void setup()
{
    Serial.begin(BMEConstants::SERIAL_BAUD);
    pinMode(BMEConstants::LED_PIN, OUTPUT);

    BMESPIInterfaceInstance::create();
    LEDControllerInstance::create(BMEConstants::MIN_TEMP_C,
                                  BMEConstants::MAX_TEMP_C,
                                  BMEConstants::SLOW_TOGGLE_INTERVAL_MS,
                                  BMEConstants::FAST_TOGGLE_INTERVAL_MS);

    if (!BMESPIInterfaceInstance::instance().begin())
    {
        Serial.println(F("BME280 not found over SPI - check wiring"));
    }
}

void loop()
{
    const uint32_t now_ms = millis();

    if (now_ms - last_read_ms >= BMEConstants::SENSOR_READ_PERIOD_MS)
    {
        last_read_ms = now_ms;
        BMESPIInterfaceInstance::instance().update();

        if (BMESPIInterfaceInstance::instance().is_connected())
        {
            const float temperature_c = BMESPIInterfaceInstance::instance().get_temperature_c();
            LEDControllerInstance::instance().update_temperature(temperature_c);

            Serial.print(F("Temp (C): "));
            Serial.print(temperature_c);
            Serial.print(F("  Toggle interval (ms): "));
            Serial.println(LEDControllerInstance::instance().get_toggle_interval_ms());
        }
    }

    digitalWrite(BMEConstants::LED_PIN, LEDControllerInstance::instance().update(now_ms) ? HIGH : LOW);
}
