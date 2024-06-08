#pragma once

#include "Arduino.h"
#include "channel.h"

ChannelComputed<uint32_t> current_real_time_ms([](){ return millis(); } -> uint32_t);
