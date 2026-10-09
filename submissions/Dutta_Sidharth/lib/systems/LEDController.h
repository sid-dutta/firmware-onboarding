#pragma once
#include <stdint.h>
#include <etl/singleton.h>

class LEDController
{
public:
    LEDController(float min_temp_c, float max_temp_c, uint32_t slow_interval_ms, uint32_t fast_interval_ms);

    void update_temperature(float temperature_c);

    uint32_t get_toggle_interval_ms() const { return _toggle_interval_ms; }

    bool update(uint32_t now_ms);

private:
    float _min_temp_c;
    float _max_temp_c;
    uint32_t _slow_interval_ms;
    uint32_t _fast_interval_ms;
    uint32_t _toggle_interval_ms;
    uint32_t _last_toggle_ms = 0;
    bool _led_on = false;
};

using LEDControllerInstance = etl::singleton<LEDController>;
