#pragma once
#include <stdint.h>

enum class watchdogTimeout : uint8_t
{
    timeoutDisabled = 0,
    timeout8ms,
    timeout16ms,
    timeout32ms,
    timeout64ms,
    timeout128ms,
    timeout256ms,
    timeout512ms,
    timeout1024ms,
    timeout2048ms,
    timeout4096ms,
    timeout8192ms
};

class tinyWatchdog
{
private:
    watchdogTimeout _period = watchdogTimeout::timeoutDisabled;
    watchdogTimeout _window = watchdogTimeout::timeoutDisabled;

    bool _enabled = false;

public:
    void begin(watchdogTimeout period, watchdogTimeout window = watchdogTimeout::timeoutDisabled);
    void enable();
    void disable();
    void reset();

    bool isEnabled();
};

extern tinyWatchdog Watchdog;