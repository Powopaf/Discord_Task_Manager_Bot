//
// Created by paf on 2/5/25.
//

#ifndef DATE_H
#define DATE_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct Date {
    int day;
    int month;
    int year;
};
/**
 * \brief Checks if the given date is valid.
 *
 * This function verifies if the provided date is valid by checking the year, month, and day values.
 * It also considers leap years for the month of February.
 *
 * \param date The date to be validated.
 * \return 0 if the date is valid, 1 otherwise.
 */
char isValidDate(struct Date date);

/**
 * \brief Checks if the given date has passed.
 *
 * This function compares the provided date with the current date to determine if it has already passed.
 *
 * \param date The date to be checked.
 * \return 1 if the date has passed, 0 otherwise.
 */

char isDatePassed(struct Date date);

#endif //DATE_H
