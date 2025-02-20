/**
 * @file time.c
 * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt)
 * @brief Provides an implementation of time.h.
 *
 * @version 1
 * @date 2023-06-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "time.h"

Time createTime(int hours, int minutes, int seconds)
{
    Time time;
    time.hour = hours;
    time.min = minutes;
    time.sec = seconds;
    return time;
}
Time convertIntToTime(int time)
{
    int hours = time / 10000;
    int minutes = (time % 10000) / 100;
    int seconds = time % 100;
    return createTime(hours, minutes, seconds);
}