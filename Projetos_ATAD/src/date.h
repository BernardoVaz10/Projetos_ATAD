/**
 * @file date.h
 * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt)
 * @brief Provides a Date type.
 *
 * @version 1
 * @date 2023-06-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

/**
 * @brief Date data type.
 *
 */
typedef struct date
{
    int day, month, year;
} Date;

/**
 * @brief Creates a Date.
 *
 * @param day The day.
 * @param month The month.
 * @param year The year.
 * @return Date The created date.
 */
Date createDate(int day, int month, int year);


/**
 * @brief Converts a string to a Date.
 *
 * @param date The string to convert.
 * @return Date The converted date.
 */
Date convertDate(char date[11]);