//
// File:        logentry.hpp
//
// Version:     1.0
// Date:
// Author:
//
// Description: Class definition for a log entry.
//
//
 
#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

#include "string.hpp"
#include <iostream>
#include <vector>

//
class Date {
public:
            Date() {};
            // constructor to read in a date, given a string
            Date(const String&);
        // accessors
        String getDay()   { return day; };
        String getMonth() { return month; };
        String getYear()  { return year; };

        friend std::ostream& operator<<(std::ostream&, const Date&);

private:
    String  day, month, year;
};

//
class Time {
public:
            Time() {};
            // constructor to assign the time, given a string
            Time(const String&);

            friend std::ostream& operator<<(std::ostream&, const Time&);

private:
    String  hour, minute, second;
};


// A single log entry
class LogEntry {
public:
            LogEntry() {};
            LogEntry(const String&);

    // accessor methods
    String getHost()          const { return host; };
    Date   getDate()          const { return date; };
    Time   getTime()          const { return time; };
    String getRequest()       const { return request; };
    String getStatus()        const { return status; };
    int    getNumberOfBytes() const { return number_of_bytes; };


    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);

private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry>&);
void                    by_host     (std::ostream&, const std::vector<LogEntry>&);
int                     byte_count  (const std::vector<LogEntry>&);

#endif
