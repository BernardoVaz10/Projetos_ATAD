/**
 * @file countryEarthquake.c
 * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt)
 * @brief Provides an implementation of countryEarthquake.h.
 *
 * Functions to calculate and print the country earthquake data.
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "countryEarthquake.h"
#include "earthquake.h"
#include <string.h>
#include <stdio.h>
#include "list.h"

void calculateCountryEarthquakeData(PtList earthquakeList, CountryEarthquakeData countryEarthquakeDataArray[])
{
    int earthquakeListSize;
    listSize(earthquakeList, &earthquakeListSize);
    printf("%d", earthquakeListSize);

    PtList countryCodeList = listCreate();
    int countryIndex = 0;

    for (int i = 0; i < earthquakeListSize; i++)
    {
        ListElem elem;
        listGet(earthquakeList, i, &elem);

        bool alreadyChecked = false;

        // Check if country was already checked
        int countryListSize;
        listSize(countryCodeList, &countryListSize);

        for (int j = 0; j < countryListSize; j++)
        {
            ListElem oldElem;
            listGet(countryCodeList, j, &oldElem);
            if (strcmp(elem.countryCode, oldElem.countryCode) == 0)
            {
                alreadyChecked = true;
                break;
            }
        }

        // Skip the loop if the country has already been found
        if (alreadyChecked)
        {
            continue;
        }

        listAdd(countryCodeList, countryListSize, elem);

        CountryEarthquakeData countryEarthquakeData;
        strcpy(countryEarthquakeData.code, elem.countryCode);
        // earthquakeList does not have the name of the territory
        // strcpy(countryEarthquakeData.territoryName, earthQuakeList[i].territoryName);
        countryEarthquakeData.numberOfEarthquakes = 0;
        countryEarthquakeData.averageDepth = 0.0;
        countryEarthquakeData.averageMagnitude = 0.0;

        int count = 0;
        double totalDepth = 0.0;
        double totalMagnitude = 0.0;

        // Iterate through the earthquake list
        for (int j = 0; j < earthquakeListSize; j++)
        {
            ListElem elem;
            listGet(earthquakeList, j, &elem);

            // Check if the country code matches
            if (strcasecmp(elem.countryCode, countryEarthquakeData.code) == 0)
            {
                // Update the count and sum of depth and magnitude
                count++;
                totalDepth += elem.depth;
                totalMagnitude += elem.magnitude;
            }
        }

        // Calculate the average depth and magnitude
        if (count > 0)
        {
            countryEarthquakeData.numberOfEarthquakes = count;
            countryEarthquakeData.averageDepth = totalDepth / count;
            countryEarthquakeData.averageMagnitude = totalMagnitude / count;
        }

        // Store the country earthquake data in the array
        countryEarthquakeDataArray[countryIndex] = countryEarthquakeData;
        countryIndex++;
    }
}

void printCountryEarthquakeData(CountryEarthquakeData countryEarthquakeData)
{

    printf("Nome do Território: %s \n", countryEarthquakeData.territoryName);
    printf("Código do país: %s \n", countryEarthquakeData.code);
    printf("Número de terramotos no país %d \n", countryEarthquakeData.numberOfEarthquakes);
    printf("Média de profundidade %f \n", countryEarthquakeData.averageDepth);
    printf("Média de Magnitude %f \n", countryEarthquakeData.averageMagnitude);
}

void getTopNCountries(CountryEarthquakeData countryEarthquakeDataArray[], int N)
{
    // Sort the countryDataArray in descending order based on the number of earthquakes
    int countryDataSize;
    countryDataSize = 23409;
    for (int i = 0; i < countryDataSize - 1; i++)
    {
        for (int j = 0; j < countryDataSize - i - 1; j++)
        {
            if (countryEarthquakeDataArray[j].numberOfEarthquakes < countryEarthquakeDataArray[j + 1].numberOfEarthquakes)
            {
                CountryEarthquakeData temp = countryEarthquakeDataArray[j];
                countryEarthquakeDataArray[j] = countryEarthquakeDataArray[j + 1];
                countryEarthquakeDataArray[j + 1] = temp;
            }
        }
    }

    // Display the top N countries
    printf("Top %d countries with the most earthquakes:\n", N);
    for (int i = 0; i < N; i++)
    {
        printf("Country Code: %s\n", countryEarthquakeDataArray[i].code);
        printf("Territory Name: %s\n", countryEarthquakeDataArray[i].territoryName);
        printf("Number of Earthquakes: %d\n", countryEarthquakeDataArray[i].numberOfEarthquakes);
        printf("Average Depth: %.2f\n", countryEarthquakeDataArray[i].averageDepth);
        printf("Average Magnitude: %.2f\n", countryEarthquakeDataArray[i].averageMagnitude);
        printf("\n");
    }
}

CountryEarthquakeData countryEarthquakeDataCreate(char code[3], char territoryName[100], int numberOfEarthquakes, double averageDepth, double averageMagnitude)
{
    CountryEarthquakeData countryEarthquakeData;
    strcpy(countryEarthquakeData.territoryName, territoryName);
    strcpy(countryEarthquakeData.code, code);
    countryEarthquakeData.numberOfEarthquakes = numberOfEarthquakes;
    countryEarthquakeData.averageDepth = averageDepth;
    countryEarthquakeData.averageMagnitude = averageMagnitude;
    return countryEarthquakeData;
}