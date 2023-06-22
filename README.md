# TinyWatchdog
Simple Arduino-style library for handling watchdog timer on ATTiny414 (and similar, probably works for every tinyAVR series-1)

## Usage:
Without window function, 128ms timeout:
```c++
void setup() {
  Watchdog.begin(watchdogTimeout::timeout128ms);
  Watchdog.enable();
}

void loop() {
  // Other code probably

  Watchdog.reset();
}

```


With window function, 1024ms timeout, 256ms window:
```c++
void setup() {
  Watchdog.begin(watchdogTimeout::timeout128ms);
  Watchdog.enable();
}

void loop() {
  // Other code probably
  delay(500); // Watchdog must not be reset twice within 256ms
  Watchdog.reset();
}

```