#include <stdio.h>

#include "UserLog.h"

UserLog::UserLog() = default;

UserLog::~UserLog() = default;

void UserLog::begin(std::uint32_t baudRate)
{
#if LOG_CONFIG_PLATFORM == LOG_PLATFORM_PARTICLE
    Serial.begin(baudRate);
	/** - Wait for user input. */
	while(!Serial.available()) {
		Particle.process();
	}
	Serial.read();
	LOG_INFO("Serial link established!");
#endif
}

void UserLog::print(logState_t logType, const char* fmt, ...)
{

#if LOG_CONFIG_PLATFORM == LOG_PLATFORM_DEFAULT
    printf("%s | ", logStateTypes[logType].c_str());
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
    printf("\n");
#elif LOG_CONFIG_PLATFORM == LOG_PLATFORM_PARTICLE

    WITH_LOCK(Serial) {
		Serial.print("[");
		Serial.print(rtc.ISODateUTCString(rtc.nowEpoch() + SPARKTIMEEPOCHSTART).c_str());
		Serial.print(" | RAM: ");
		Serial.print(System.freeMemory());
		Serial.print("] ");
		Serial.print(logStateTypes[logType].c_str());
		Serial.print(" | ");
	}
    char buffer[LOG_PRINT_BUFFER_SIZE];
    va_list args;
    va_start(args, fmt);
    /** - Print argument list into buffer. */
    vsnprintf(buffer, LOG_PRINT_BUFFER_SIZE, fmt, args);
    va_end(args);
	WITH_LOCK(Serial) {
		Serial.print(buffer);
		Serial.print("\n");
		Serial.flush();
	}
#endif
}

void UserLog::printRaw(const char* fmt, ...)
{
#if LOG_CONFIG_PLATFORM == LOG_PLATFORM_DEFAULT
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
#elif LOG_CONFIG_PLATFORM == LOG_PLATFORM_PARTICLE

    char buffer[LOG_PRINT_BUFFER_SIZE];
    va_list args;
    va_start(args, fmt);
    /** - Print argument list into buffer. */
    vsnprintf(buffer, LOG_PRINT_BUFFER_SIZE, fmt, args);
    va_end(args);
	WITH_LOCK(Serial) {
		Serial.print(buffer);
		Serial.flush();
	}
#endif
}

UserLog userLog;
