/**
 * @file countryEarthquake.h
 * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt)
 * @brief Provides a CountryEarthquakeData type.
 *
 * Functions to calculate and print the country earthquake data.
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include "list.h"

typedef struct countryEarthquakeData
{
    char code[3];
    char territoryName[100];
    int numberOfEarthquakes;
    double averageDepth;
    double averageMagnitude;
} CountryEarthquakeData;

/**
 * @brief Calculates the country earthquake data.
 *
 * @param earthquakeList The list of earthquakes.
 * @param countryEarthquakeDataArray The array of country earthquake data.
 */
void calculateCountryEarthquakeData(PtList earthquakeList, CountryEarthquakeData countryEarthquakeDataArray[]);

/**
 * @brief Prints the country earthquake data.
 *
 * @param countryEarthquakeData The country earthquake data.
 */
void printCountryEarthquakeData(CountryEarthquakeData countryEarthquakeData);

/**
 * @brief Creates a CountryEarthquakeData.
 *
 * @param code The country code.
 * @param territoryName The territory name.
 * @param numberOfEarthquakes The number of earthquakes.
 * @param averageDepth The average depth.
 * @param averageMagnitude The average magnitude.
 * @return CountryEarthquakeData The created CountryEarthquakeData.
 */
CountryEarthquakeData countryEarthquakeDataCreate(char code[3], char territoryName[100], int numberOfEarthquakes, double averageDepth, double averageMagnitude);

/**
 * @brief Gets the top N countries.
 *
 * @param countryEarthquakeDataArray The array of country earthquake data.
 * @param N The number of countries to get.
 */
void getTopNCountries(CountryEarthquakeData countryEarthquakeDataArray[], int N);