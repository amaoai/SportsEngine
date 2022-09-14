#pragma once

#include <stdarg.h>

namespace sports {
    void info(const char* fmt, ...);
    void wran(const char* fmt, ...);
    void debug(const char* fmt, ...);
    void error(const char* fmt, ...);
    void runtime_error(const char* fmt, ...);

    void vinfo(const char* fmt, va_list va);
    void vwran(const char* fmt, va_list va);
    void vdebug(const char* fmt, va_list va);
    void verror(const char* fmt, va_list va);
    void vruntime_error(const char* fmt, va_list va);
}