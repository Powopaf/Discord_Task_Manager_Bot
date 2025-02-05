//
// Created by paf on 2/5/25.
//

#include "date.h"

/**
 * \brief Checks if a given date has passed.
 *
 * This function compares the provided date with the current local date and
 * determines if the given date has already passed.
 *
 * \param date A struct Date representing the date to be checked.
 * \return Returns 1 if the date has passed, 0 otherwise.
 */
char isDatePassed(struct Date date) {
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    if (date.year < local->tm_year + 1900) {
        return 1;
    }
    if (date.year == local->tm_year + 1900) {
        if (date.month < local->tm_mon + 1) {
            return 1;
        }
        if (date.month == local->tm_mon + 1) {
            if (date.day < local->tm_mday) {
                return 1;
            }
        }
    }
    return 0;
}