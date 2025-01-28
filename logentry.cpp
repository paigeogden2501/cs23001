//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//
 
#include "string.hpp"
#include "logentry.hpp"
#include <iostream>
#include <vector>

// *************************************************************

// date constructor
Date::Date(const String& line) {
    day   = line.substr(1,2);
    month = line.substr(4,6);
    year  = line.substr(8,11);
}

Time::Time(const String& line) {
    hour   = line.substr(13,14);
    minute = line.substr(16,17);
    second = line.substr(19,20);
}


// *************************************************************

// REQUIRES: a line of 10 strings 
// ENSURES: host, date, time, request, status, and bytes are assigned a value
LogEntry::LogEntry(const String& line) {
    //Use split to create LogEntry
    std::vector<String> logEntryParts = line.split(' ');

    // takes care of requirement (must be 10 strings long)
    if (logEntryParts.size() != 10) {
        return;
    }

    // assigning the strings in the vector to the member variables
    host    = logEntryParts[0];
    date    = logEntryParts[3];
    time    = logEntryParts[3];
    request = logEntryParts[5] + logEntryParts[6] + logEntryParts[7];
    status  = logEntryParts[8];

    String numBytes = logEntryParts[9];
    int temp = numBytes.length() - 1;
    int num = 0;
    int t = 1;
    if (numBytes != '-') {
        //number_of_bytes = numBytes.toInt();
        while (temp >= 0) {
            num = numBytes[temp] - '0';
            number_of_bytes += (num * t);
            temp -= 1;
            t *= 10;
        }
        t = 1;
    }
    else {
        number_of_bytes = 0;
    }
}

// REQUIRES: something to read
// ENSURES: a line is read in as a vector
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
    char ch;
    while(!in.eof()) {
        String temp("");
        while(in.get(ch)) {
            if (ch == '\n') {
                result.push_back(LogEntry(temp));
                break;
            }
            temp += ch;
        }
        if (in.eof()) {
            if (temp.length() > 0) {
                result.push_back(LogEntry(temp));
            }
            break;
        }
    }

    return result;
}

// REQUIRES:
// ENSURES:
void output_all(std::ostream& out, const std::vector<LogEntry>& entry) {
    for (int i = 0; i < int(entry.size()); ++i) {
        out << entry[i] << "\n";
    }
}

// REQUIRES:
// ENSURES:
void by_host(std::ostream& out, const std::vector<LogEntry>& entry) {
    int i = 0;
    while (i < int(entry.size())) {
        out << entry[i].getHost() << "\n";
        ++i;
    }
    
}

// REQUIRES:
// ENSURES:
int byte_count(const std::vector<LogEntry>& entry) {
    
    int total = 0;

    for (size_t i = 0; i < entry.size(); ++i) {
        if (entry[i].getNumberOfBytes() != 0) {
            total += entry[i].getNumberOfBytes();
        }
    }
    return total;
}

// **************output operators*************

std::ostream& operator<<(std::ostream& out, const Date& entry) {
    out << entry.month << " " << entry.day << ", " << entry.year;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Time& entry) {
    out << entry.hour << ":" << entry.minute << ":" << entry.second;
    return out;
}

std::ostream& operator<<(std::ostream& out, const LogEntry& entry) {
    out << "Host: "    << entry.getHost() << "\n" 
        << "Date: "    << entry.getDate() << "\n"
        << "Time: "    << entry.getTime() << "\n"
        << "Request: " << entry.getRequest() << "\n"
        << "Status: "  << entry.getStatus() << "\n"
        << "Bytes: "   <<entry.getNumberOfBytes() << "\n" 
        << "\n";
    
    return out;
}

