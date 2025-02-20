/**
 * @file earthquake.h
 * @brief Provides an implementation of earthquake.h.
 * 
 * 
 * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt)
 * @bug No known bugs.
 */

#pragma once

#include "time.h"
#include "date.h"

typedef struct earthquake
{
    int id;
    // Código de 2 letras do país ou território mais próximo (countryLocation) 
    char countryCode[3]; // Calculado a partir das localizações durante importação 
    Date date;
    Time time;
    float latitude;
    float longitude;
    char type[20]; // Earthquake | Explosion | Nuclear Explosion | Rock Burst 
    float depth;
    float magnitude;
    char magnitudeType[3]; // MB | MD | MH | ML | MS | MW
} Earthquake;

/**
 * @brief Creates an earthquake.
 *
 * @param id The id of the earthquake.
 * @param countryCode The country code of the earthquake.
 * @param date The date of the earthquake.
 * @param time The time of the earthquake.
 * @param latitude The latitude of the earthquake.
 * @param longitude The longitude of the earthquake.
 * @param type The type of the earthquake.
 * @param depth The depth of the earthquake.
 * @param magnitude The magnitude of the earthquake.
 * @param magnitudeType The magnitude type of the earthquake.
 * @return Earthquake The created earthquake.
 */
Earthquake earthquakeCreate(int id, char countryCode[3], Date date, Time time, float latitude, float longitude, char type[20], float depth, float magnitude, char magnitudeType[3]);

/**
 * @brief Gets the country code of the country where the earthquake happened.
 *
 * @param latitude The latitude of the earthquake.
 * @param longitude The longitude of the earthquake.
 * @return char* The country code.
 */
char *calculateCountryCode(float latitude, float longitude);

/**
 * @brief Calculates the distance between two points.
 *
 * @param lat1 The latitude of the first point.
 * @param lon1 The longitude of the first point.
 * @param lat2 The latitude of the second point.
 * @param lon2 The longitude of the second point.
 * @return double The distance between the two points.
 */
double calculateDistance(float lat1, float lon1, float lat2, float lon2);