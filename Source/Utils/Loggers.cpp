#include "Include/Utils/Loggers.h"

#include <stdexcept>

namespace sports {
    void info(const char *fmt, ...)
    {
        va_list va;
        va_start(va, fmt);
        vinfo(fmt, va);
        va_end(va);
    }

    void wran(const char *fmt, ...)
    {
        va_list va;
        va_start(va, fmt);
        vwran(fmt, va);
        va_end(va);
    }

    void debug(const char *fmt, ...)
    {
        va_list va;
        va_start(va, fmt);
        vdebug(fmt, va);
        va_end(va);
    }

    void error(const char *fmt, ...)
    {
        va_list va;
        va_start(va, fmt);
        verror(fmt, va);
        va_end(va);
    }

    void runtime_error(const char *fmt, ...)
    {
        va_list va;
        va_start(va, fmt);
        vruntime_error(fmt, va);
        va_end(va);
    }

    void vinfo(const char *fmt, va_list va)
    {
        vfprintf(stdout, fmt, va);
    }

    void vwran(const char *fmt, va_list va)
    {
        vfprintf(stdout, fmt, va);
    }

    void vdebug(const char *fmt, va_list va)
    {
        vfprintf(stdout, fmt, va);
    }

    void verror(const char *fmt, va_list va)
    {
        vfprintf(stderr, fmt, va);
    }

    void vruntime_error(const char *fmt, va_list va)
    {
        char pfmt[1024];
        vsprintf(pfmt, fmt, va);
        throw std::runtime_error(pfmt);
    }
}