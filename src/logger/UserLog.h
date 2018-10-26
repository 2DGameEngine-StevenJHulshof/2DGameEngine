#pragma once

#include <stdarg.h>

#include "user_log_types.h"

#if LOG_CONFIG_PLATFORM == LOG_PLATFORM_PARTICLE
#include "application.h"
#include "SparkTime.h"
#endif

/**
 * Log class prototype.
 */
class UserLog
{
public:
    /**
     * Log class constructor.
     */
    UserLog();
    /**
     * Log class destructor.
     */
    ~UserLog();
    /**
     * Instantiate COM link with specified baudrate.
     * Must be called when using embedded UART communications.
     *
     * @param[in]	uint32_t	Baud rate of the COM link.
     */
    void begin(std::uint32_t baudRate);
    /**
     * Prints to console with the specified log state.
     *
     * @param[in]	logState_t		The specified log state.
     * @param[in]	const char*		A variable argument list containing
     * 								string logs and/or numeric values.
     */
    void print(logState_t logType, const char* fmt, ...);
    /**
     * Prints to console without the log type prefix and carriage return.
     *
     * @param[in]	const char*		A variable argument list containing
     * 								string logs and/or numeric values.
     */
    void printRaw(const char* fmt, ...);
};

/**
 * Global logger.
 */
extern UserLog userLog;

/**
 * Basic logging macro's.
 */
#if LOG_CONFIG_ENABLED == 1
#define LOG_BEGIN(b)			    userLog.begin(b)
#define LOG_CRITICAL(f_, ...) 	    userLog.print(LOG_STATE_CRITICAL, (f_), ## __VA_ARGS__)
#if LOG_CONFIG_LEVEL > 0
#define LOG_WARNING(f_, ...) 	    userLog.print(LOG_STATE_WARNING, (f_), ## __VA_ARGS__)
#endif
#if LOG_CONFIG_LEVEL > 1
#define LOG_INVALID(f_, ...)           userLog.print(LOG_STATE_INVALID, (f_), ## __VA_ARGS__)
#define LOG_INFO(f_, ...)		    userLog.print(LOG_STATE_INFO, (f_), ## __VA_ARGS__)
#define LOG_RAW(f_, ...)		    userLog.printRaw((f_), ## __VA_ARGS__);
#endif
#endif

/**
 * Catch unused basic macro's.
 */
#if LOG_CONFIG_PLATFORM == LOG_PLATFORM_PARTICLE
#ifndef LOG_BEGIN
#define LOG_BEGIN(b)
#endif
#endif
#ifndef LOG_RAW
#define LOG_RAW(f_, ...)
#endif
#ifndef LOG_INFO
#define LOG_INFO(f_, ...)
#endif
#ifndef LOG_INVALID
#define LOG_INVALID(f_, ...)
#endif
#ifndef LOG_WARNING
#define LOG_WARNING(f_, ...)
#endif
#ifndef LOG_CRITICAL
#define LOG_CRITICAL(f_, ...)
#endif

/**
 * Advanced macro's.
 */
#define LOG_ALLOC(ptr, fun) 	LOG_INFO("%p | %s", ptr, fun)
#define LOG_DEALLOC(ptr, fun) 	LOG_INFO("%p | %s", ptr, fun)