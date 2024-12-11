#include "date.h"
#include <ctime>
#include "help.cpp"
#include <cstdlib>
#include <stdexcept>

Date::Date(std::string date) {
    /*
     * format of the given string should be:
     * DD/MM/YYYY with 0 to complete if nessessary
     */
    day = atoi(date.substr(0, 2).data());
    if (day == 0)
        throw std::invalid_argument("Day is not a number");
    
    month = atoi(date.substr(3, 2).data());
    if (month == 0)
        throw std::invalid_argument("Month is not a number");

    year = atoi(date.substr(6, 4).data());
    if (year == 0)
        throw std::invalid_argument("Year not a number");

    if (!IsValidDate())
        throw std::invalid_argument("Date is passed");
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
