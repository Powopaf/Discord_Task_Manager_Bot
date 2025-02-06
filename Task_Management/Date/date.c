//
// Created by paf on 2/5/25.
//

#include "date.h"

char isValidDate(struct Date date) {
    if (date.year < 0) {
        return 1;
    }
    if (date.month < 1 || date.month > 12) {
        return 1;
    }
    if (date.day < 1 || date.day > 31) {
        return 1;
    }
    if (date.month == 2) {
        if (date.day > 29) {
            return 1;
        }
        if (date.day == 29) {
            if (date.year % 4 != 0) {
                return 1;
            }
            if (date.year % 100 == 0 && date.year % 400 != 0) {
                return 1;
            }
        }
    }
    if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) {
        if (date.day > 30) {
            return 1;
        }
    }
    return 0;
}

char isDatePassed(struct Date date) {
    time_t now;
    time(&now);
    struct tm* local = localtime(&now);
    if (date.year < local->tm_year + 1900) {
        return 1;
    }
    if (date.year == local->tm_year + 1900) {
        if (date.month < local->tm_mon) {
            return 1;
        }
        if (date.month == local->tm_mon) {
            if (date.day < local->tm_mday) {
                return 1;
            }
        }
    }
    return 0;
}

char parserDate(char* date, struct Date* d) {
    if (date == NULL || strlen(date) != 10) {
        return EXIT_FAILURE;
    }
    char copy[11];
    strcpy(copy, date);
	char* token = strtok(copy, "/");
    int j = 0;
    while (token != NULL) {
        switch (j) {
            case 0:
                d->day = atoi(token);
                break;
            case 1:
                d->month = atoi(token);
                break;
            case 2:
                d->year = atoi(token);
                break;
            default:
                return EXIT_FAILURE;
        }
        token = strtok(NULL, "/");
        j++;
    }
    return isValidDate(*d) == 0 && isDatePassed(*d) == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}