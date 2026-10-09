#include "BMESPIInterface.h"

bool BMESPIInterface::begin()
{
    _connected = _bme.begin();
    return _connected;
}

void BMESPIInterface::update()
{
    if (!_connected)
    {
        return;
    }

    _temperature_c = _bme.readTemperature();
    _humidity_percent = _bme.readHumidity();
    _pressure_hpa = _bme.readPressure() / 100.0f;
}
