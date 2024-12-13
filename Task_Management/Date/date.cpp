#include "date.h"
#include <ctime>
#include <cstdlib>
#include <stdexcept>

Date::Date() {
    throw std::invalid_argument("No date given");
}

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

    if (!IsValidDate(day, month, year))
        throw std::invalid_argument("Date is passed");
}

static bool february(int year) {
    /*
     * check leap year
     */

    if (year % 100 == 0 && year % 400 == 0)
        return true;

    if (year % 100 != 0 && year % 4 == 0)
        return true;

    else
        return false;
}

bool IsValidDate(int d, int m, int y) {
    time_t t;
    time(&t);
    struct tm* time = localtime(&t);

    if (m < 1 || m > 12)
        return false;

    if (y < time->tm_year + 1900)
        return false;

    if (d < 0 || d > 31)
        return false;

    if (y > time->tm_year) {
        if (time->tm_mon == 2) {
            bool f = february(y);
            return f ? d <= 29 : d <= 28;
        }
        return true;
    }

    if (m < time->tm_mon)
        return false;

    if (m == time->tm_mon && d < time->tm_mday)
        return false;

    return true;
}

void Date::UpdateDate(int d, int m, int y) {
    
}
