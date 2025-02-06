//
// Created by paf on 2/6/25.
//

#ifndef UTILSDATE_H
#define UTILSDATE_H

#include "../../../Date/date.h"

/**
 * \brief Checks if the given date matches the specified day, month, and year.
 *
 * \param date The date to check.
 * \param d The day to check against.
 * \param m The month to check against.
 * \param y The year to check against.
 * \return 0 if correct, 1 otherwise.
 */

char checkDate(struct Date date, int d, int m, int y);

#endif //UTILSDATE_H
