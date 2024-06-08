#pragma once

#include "channel.h"
#include "math.h"
#include "updatable.h"

class Module : public Updatable
{
public:

    Module(void (*upd)())
    {
        this->upd = upd;
    }

    void update() override
    {
        (*upd)();
    }

private:
    void (*upd)();
};

#define MODULE(name, methods) \
Module name( \
    []() -> void { \
        methods \
    } \
);

#define DRIVE(channel_name, expression) \
    { \
        channel_name.drive(expression); \
    }
#define BLOCK(...) \
    { \
        __VA_ARGS__ \
    }
#define LET(var_declaration) \
    const auto var_declaration;
#define SLET(var_declaration) \
    static auto var_declaration;
