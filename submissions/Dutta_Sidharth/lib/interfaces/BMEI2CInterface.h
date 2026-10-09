#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface
{
public:
    BMEI2CInterface() = default;

    bool begin();

    void update();

    bool is_connected() const { return _connected; }
    float get_temperature_c() const { return _temperature_c; }
    float get_humidity_percent() const { return _humidity_percent; }
    float get_pressure_hpa() const { return _pressure_hpa; }

private:
    Adafruit_BME280 _bme;
    bool _connected = false;
    float _temperature_c = 0.0f;
    float _humidity_percent = 0.0f;
    float _pressure_hpa = 0.0f;
};

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;
