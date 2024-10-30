#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <string>

void formatTime(std::string &timeString, int hour, int minute, int second) {
    // check for single digit hours
    if (hour < 10) {
        timeString.append("0" + std::to_string(hour) + ":");
    } else {
        timeString.append(std::to_string(hour) + ":");
    }
    // check for single digit minutes
    if (minute < 10) {
        timeString.append("0" + std::to_string(minute) + ":");
    } else {
        timeString.append(std::to_string(minute) + ":");
    }
    // check for single digit seconds
    if (second < 10) {
        timeString.append("0" + std::to_string(second));
    } else {
        timeString.append(std::to_string(second));
    }
}

void formatDate(std::string &dateString, int month, int day, int year) {
    // determine month
    switch (month) {
        case 1:
            dateString.append("January ");
            break;
        case 2:
            dateString.append("February ");
            break;
        case 3:
            dateString.append("March ");
            break;
        case 4:
            dateString.append("April ");
            break;
        case 5:
            dateString.append("May ");
            break;
        case 6:
            dateString.append("June ");
            break;
        case 7:
            dateString.append("July ");
            break;
        case 8:
            dateString.append("August ");
            break;
        case 9:
            dateString.append("September ");
            break;
        case 10:
            dateString.append("October ");
            break;
        case 11:
            dateString.append("November ");
            break;
        case 12:
            dateString.append("December ");
            break;
        default:
            dateString.append("Unknown ");
    }
    // determine day ordinal indicator
    std::string dayString = std::to_string(day);
    switch(dayString.back()) {
        case '1':
            dateString.append(dayString + "st, ");
        case '2':
            dateString.append(dayString + "nd, ");
            break;
        case '3':
            dateString.append(dayString + "rd, ");
            break;
        default:
            dateString.append(dayString + "th, ");
    }
    // append the year
    year = 1900 + year;
    dateString.append(std::to_string(year));
}

int main(int argc, char **argv) {
    std::time_t now;
    std::tm *localTime;
    std::string formattedTime = "";
    std::string formattedDate = "";

    std::cout << "clock" << std::endl;
    while (true) {
        // sleep for 1 sec
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        // update timestamp
        now = std::time(nullptr);
        localTime = std::localtime(&now);
        // format the date
        formatDate(formattedDate, localTime->tm_mon + 1, localTime->tm_mday, localTime->tm_year);
        // format the time
        formatTime(formattedTime, localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
        std::cout << "\r" << formattedDate << " " << formattedTime << std::flush; 
        // clear the strings
        formattedTime.clear();
        formattedDate.clear();
    }
    return 0;
}