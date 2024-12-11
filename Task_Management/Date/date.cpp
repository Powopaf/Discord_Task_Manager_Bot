#include "date.h"
#include <ctime>
#include "help.cpp"

Date::Date(std::string date) 
{
    // TODO
}

bool Date::IsValidDate() {
    time_t t;
    time(&t);
    struct tm* time = localtime(&t);

    if (month < 1 || month > 12)
        return false;

    if (year < time->tm_year + 1900)
        return false;

    if (day < 0 || day > 31)
        return false;

    if (year > time->tm_year) {
        if (time->tm_mon == 2) {
            bool f = february(year);
            return f ? day <= 29 : day <= 28;
        }
        return true;
    }

    if (month < time->tm_mon)
        return false;

    if (month == time->tm_mon && day < time->tm_mday)
        return false;

    return true;
}
