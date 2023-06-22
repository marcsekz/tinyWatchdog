#include "tinyWatchdog.hpp"
#include <avr/io.h>
#include <util/atomic.h>

void tinyWatchdog::begin(watchdogTimeout period, watchdogTimeout window)
{
    _period = period;
    _window = window;
}

void tinyWatchdog::enable()
{
    if (_period != watchdogTimeout::timeoutDisabled)
    {
        uint8_t period = static_cast<uint8_t>(_period);
        uint8_t window = static_cast<uint8_t>(_window);

        uint8_t controlByte = (period & 0xf) | ((window & 0xf) << 4);

        reset();
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
        {
            CPU_CCP = 0xd8;          // Unlock watchdog configuration registers
            WDT_CTRLA = controlByte; // Configure and enable watchdog
        }

        _enabled = true;
    }
}

void tinyWatchdog::disable()
{
    reset();
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        CPU_CCP = 0xd8;   // Unlock watchdog configuration registers
        WDT_CTRLA = 0x00; // Disable watchdog
    }

    _enabled = false;
}

void tinyWatchdog::reset()
{
    asm volatile("WDR");
}

bool tinyWatchdog::isEnabled()
{
    return _enabled;
}

tinyWatchdog Watchdog;