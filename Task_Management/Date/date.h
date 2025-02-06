//
// Created by paf on 2/5/25.
//

#ifndef DATE_H
#define DATE_H

/**
 * \brief Structure to represent a date.
 *
 * This structure holds the day, month, and year values of a date.
 */

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

/**
 * \brief Parses a date string into a Date structure.
 *
 * This function takes a date string in the format "YYYY-MM-DD" and parses it into a Date structure.
 *
 * \param date The date string to be parsed.
 * \param d Pointer to the Date structure where the parsed date will be stored.
 * \return 0 if the date was successfully parsed, 1 otherwise.
 */

char parserDate(const char* date, struct Date* d);char parserDate(const char* date, struct Date* d);

#endif //DATE_H
