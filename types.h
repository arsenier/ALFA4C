#pragma once

#include "updatable.h"
#include "service.h"

template <typename T>
class Timer : public Updatable
{
private:
    T transition_time_ms = 0;
public:
    operator bool() { return current_real_time_ms > transition_time_ms; }
    void trigger(T time) { transition_time_ms = current_real_time_ms + time; }
};

template <typename T>
class Assertion : public Updatable
{
    T assert_time_ms = 0;
    operator T() { return current_real_time_ms - assert_time_ms; }
    void assert() { assert_time_ms = current_real_time_ms; }
};
