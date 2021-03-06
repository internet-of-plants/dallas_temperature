#ifndef IOP_LIB_SENSORS_DALLAS_TEMP_HPP
#define IOP_LIB_SENSORS_DALLAS_TEMP_HPP

#include <iop-hal/io.hpp>

namespace dallas {
class TemperatureCollection {
    void *sensor;
public:
    TemperatureCollection(iop_hal::PinRaw pin) noexcept;
    auto begin() noexcept -> void;
    auto measure() noexcept -> float;

    auto operator=(TemperatureCollection && other) noexcept -> TemperatureCollection &;
    ~TemperatureCollection() noexcept;

    TemperatureCollection(TemperatureCollection && other) noexcept: sensor(other.sensor) {
        other.sensor = nullptr;
    }
    TemperatureCollection(const TemperatureCollection & other) noexcept = delete;
    auto operator=(const TemperatureCollection & other) noexcept = delete;
};
}

#endif