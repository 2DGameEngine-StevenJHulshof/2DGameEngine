#pragma once

#include <string>
#include <cstdint>

#include "game_config.h"

enum logState_t : std::uint8_t
{
    LOG_STATE_INFO,
    LOG_STATE_INVALID,
    LOG_STATE_WARNING,
    LOG_STATE_CRITICAL,
    LOG_STATE_TOTAL
};

const std::string logStateTypes[LOG_STATE_TOTAL] =
{
        "INFO    ",
        "INVALID ",
        "WARNING ",
        "CRITICAL"
};

const std::uint16_t LOG_PRINT_BUFFER_SIZE = 512;

/**
 * Log disabled = 0
 * Log enabled = 1.
 */
#ifndef LOG_CONFIG_ENABLED
#define LOG_CONFIG_ENABLED 1
#endif
/**
 * Critical only = 0
 * Critical/warnings only = 1
 * All log types = 2
 */
#ifndef LOG_CONFIG_LEVEL
#define LOG_CONFIG_LEVEL 2
#endif

#define	LOG_PLATFORM_DEFAULT 	0
#define	LOG_PLATFORM_PARTICLE 	1
/**
 * Defines platform. Supported platforms: Particle, Windows.
 */
#ifndef LOG_CONFIG_PLATFORM
#define LOG_CONFIG_PLATFORM LOG_PLATFORM_DEFAULT
#endif