/**
 * @file date.c
 * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt)
 * @brief Provides an implementation of date.h.
 * 
 * @version 1
 * @date 2023-06-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "date.h"

Date createDate(int day, int month, int year)
{
    Date date;
    date.day = day;
    date.month = month;
    date.year = year;
    return date;
}

Date convertDate(char date[11]) {
    Date convertedDate;
    convertedDate.day = (date[0] - '0') * 10 + (date[1] - '0');
    convertedDate.month = (date[3] - '0') * 10 + (date[4] - '0');
    convertedDate.year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
    return convertedDate;
}
