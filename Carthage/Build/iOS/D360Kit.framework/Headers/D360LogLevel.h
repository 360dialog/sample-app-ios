#import <Foundation/Foundation.h>

/**
 `D360LogLevel` enum specifies different levels of logging that could be used to limit or display more messages in logs.

 @see `D360.+setLogLevel:`
 */
typedef NS_ENUM(NSUInteger, D360LogLevel) {
    /// No logs
    D360LogLevelNone    = 0,

    /// Log error messages only
    D360LogLevelError   = 1,

    /// Log warnings
    D360LogLevelWarning = 2,

    /// Log info messages
    D360LogLevelInfo    = 3,

    // Log debugging messages
    D360LogLevelDebug   = 4
};