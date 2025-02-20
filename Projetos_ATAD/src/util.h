/**
 * @file util.h
 * @brief Implementation of util functions.
 * 
 * Functions to util data.
 * 
 * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt)
 * @bug No known bugs.
 */

#pragma once
#include <string.h>

/**
 *@brief match to String ignore case
 *
 *
 *
 *@param str1
 *@param str2
 *
 *@return return (time2.hour - time1.hour) * 60 + (time2.min - time1.min)
 */
int equalsStringIgnoreCase(char str1[], char str2[]);

/**
 *@brief string to upper
 *
 *
 *
 *@param orig
 *@param dest
 *
 */
void strToUpper(const char *orig, char *dest);