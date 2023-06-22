#include <Arduino.h>

#include "tinyWatchdog.hpp"

int outputs[] = {PIN_PA3, PIN_PB0, PIN_PB1, PIN_PB2, PIN_PB3};

void setup() {
  // put your setup code here, to run once:
  for (size_t i = 0; i < 5; i++)
  {
    pinMode(outputs[i], OUTPUT);
  }

  Watchdog.begin(watchdogTimeout::timeout2048ms, watchdogTimeout::timeout512ms);
  Watchdog.enable();
}

void loop() {
  Watchdog.reset();

  // put your main code here, to run repeatedly:
  for (size_t i = 0; i < 5; i++)
  {
    digitalWrite(outputs[i], HIGH);
    delay(50);
  }
  delay(500);
  for (size_t i = 0; i < 5; i++)
  {
    digitalWrite(outputs[i], LOW);
    delay(50);
  }

  delay(500);
}