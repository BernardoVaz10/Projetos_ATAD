/**
 * @file time.h
 * @author --- * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt) * @brief Provides a Time struct to store time in hours, minutes and seconds.
 *
 * @version 1
 * @date 2023-06-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

 typedef struct time {
    int hour, min, sec;
} Time;

/**
 * @brief Creates a Time struct.
 *
 * @param hour The hour.
 * @param min The minute.
 * @param sec The second.
 * @return Time The Time struct.
 */
Time createTime(int hours, int minutes, int seconds);

/**
 * @brief Creates a Time struct.
 *
 * @param hour The hour.
 * @param min The minute.
 * @param sec The second.
 * @return Time The Time struct.
 */
Time convertIntToTime(int time);