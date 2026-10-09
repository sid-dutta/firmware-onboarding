#include "LEDController.h"

LEDController::LEDController(float min_temp_c, float max_temp_c, uint32_t slow_interval_ms, uint32_t fast_interval_ms)
    : _min_temp_c(min_temp_c),
      _max_temp_c(max_temp_c),
      _slow_interval_ms(slow_interval_ms),
      _fast_interval_ms(fast_interval_ms),
      _toggle_interval_ms(slow_interval_ms)
{
}

void LEDController::update_temperature(float temperature_c)
{
    if (temperature_c != temperature_c || _max_temp_c <= _min_temp_c)
    {
        return;
    }

    if (temperature_c < _min_temp_c)
    {
        temperature_c = _min_temp_c;
    }
    else if (temperature_c > _max_temp_c)
    {
        temperature_c = _max_temp_c;
    }

    const float fraction = (temperature_c - _min_temp_c) / (_max_temp_c - _min_temp_c);
    const float span_ms = static_cast<float>(_slow_interval_ms) - static_cast<float>(_fast_interval_ms);
    _toggle_interval_ms = static_cast<uint32_t>(static_cast<float>(_slow_interval_ms) - fraction * span_ms);
}

bool LEDController::update(uint32_t now_ms)
{
    if (now_ms - _last_toggle_ms >= _toggle_interval_ms)
    {
        _led_on = !_led_on;
        _last_toggle_ms = now_ms;
    }
    return _led_on;
}
