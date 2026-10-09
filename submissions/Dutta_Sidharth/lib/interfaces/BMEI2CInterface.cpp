#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin()
{
    _connected = _bme.begin(BMEConstants::I2C_ADDRESS_PRIMARY) ||
                 _bme.begin(BMEConstants::I2C_ADDRESS_SECONDARY);
    return _connected;
}

void BMEI2CInterface::update()
{
    if (!_connected)
    {
        return;
    }

    _temperature_c = _bme.readTemperature();
    _humidity_percent = _bme.readHumidity();
    _pressure_hpa = _bme.readPressure() / 100.0f;
}
