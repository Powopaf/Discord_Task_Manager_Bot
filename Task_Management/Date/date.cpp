#include "date.h"
#include <ctime>


Date::Date(std::string date) 
{
    // TODO
}

bool Date::IsValidDate() {
    if (day <= 0 || day > 31)
        return false;

    if (month < 1 || month > 12)
        return false;

    time_t t;
    time(&t);
    struct tm* time = localtime(&t);
    if (year < time->tm_year + 1900)
        return false

    return true;
}
