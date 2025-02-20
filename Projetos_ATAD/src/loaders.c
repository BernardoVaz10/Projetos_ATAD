/**
 * @file loaders.c
 * @brief Implementation of loaders functions.
 * 
 * Functions to read data.
 * 
 * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt)
 * @bug No known bugs.
 */

#include "loaders.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "input.h"
#include "earthquake.h"
#include "list.h"
#include "stringWrap.h"
#include "map.h"

int readEarthquakes(PtList list) // PtList list
{
    // Open the "earthquakes.csv" file
    FILE *file_path = fopen("dataset/earthquakes.csv", "r");

    // If file does not exist, abort
    if (file_path == NULL)
    {
        printf("File not found\n");
        return -1;
    }

    int count = 0;
    char line[1024];

    fgets(line, 1024, file_path);
    while (fgets(line, 1024, file_path))
    {
        char *tmp = strdup(line);

        //  creates tokens[11] array, with tokens read from the file line
        char **tokens = splitString(tmp, 9, ";");

        int id = atoi(tokens[0]);

        Date date = convertDate(tokens[1]);
        Time time = convertIntToTime(atoi(tokens[2]));

        float latitude = atof(tokens[3]);
        float longitude = atof(tokens[4]);

        // calculates the country code
        char countryCode[3];
        strcpy(countryCode, calculateCountryCode(latitude, longitude));

        char type[20];
        strcpy(type, tokens[5]);

        float depth = atof(tokens[6]);
        float magnitude = atof(tokens[7]);

        char magnitudeType[3];
        strcpy(magnitudeType, tokens[8]);

        // criação do earthquake para posteriormente adicionar à lista
        Earthquake earthquake = earthquakeCreate(id, countryCode, date, time, latitude, longitude, type, depth, magnitude, magnitudeType);
        listAdd(list, count, earthquake);
        count++;
        free(tokens);
        free(tmp);
    }

    fclose(file_path);

    return count;
}

int readCountryStatistics(PtMap map) // PtMap map
{
    // Open the "countryStatistics.csv" file
    FILE *file_path = fopen("dataset/world_country_statistics.csv", "r");
    StringWrap code;

    // If file does not exist, abort
    if (file_path == NULL)
    {
        printf("File not found\n");
        return -1;
    }

    int count = 0;
    char line[1024];

    fgets(line, 1024, file_path);
    while (fgets(line, 1024, file_path))
    {
        char *tmp = strdup(line);

        //  creates tokens[11] array, with tokens read from the file line
        char **tokens = splitString(tmp, 9, ";");

        code = stringWrapCreate(tokens[0]);

        char name[40];
        strcpy(name, tokens[1]);

        char region[30];
        strcpy(region, tokens[2]);

        long population = atol(tokens[3]);
        long area = atol(tokens[4]);
        long gdp_capita = atol(tokens[5]);

        float literacy = atof(tokens[6]);
        float birthrate = atof(tokens[7]);
        float deathrate = atof(tokens[8]);

        // criação do countryStatistics para posteriormente adicionar ao map
        CountryStatistcs countryStatistics = countryStatisticsCreate(tokens[0], name, region, population, area, gdp_capita, literacy, birthrate, deathrate);
        mapPut(map, code, countryStatistics);
        count++;
        free(tokens);
        free(tmp);
    }

    fclose(file_path);
    return count;
}