/**
 * @file countryLocation.c
 * @brief Implementation of countryLocation functions.
 *
 * Functions to read and create countryLocation data.
 *
  * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt@estudantes.ips.pt)
 *
 * @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "input.h"
#include "countryLocation.h"

CountryLocation countryLocationCreate(char code[3], float latitude, float longitude, char territoryName[45], char countryName[45], char territoryRegion[30])
{
    CountryLocation countryLocation;
    strcpy(countryLocation.code, code);
    countryLocation.latitude = latitude;
    countryLocation.longitude = longitude;
    strcpy(countryLocation.territoryName, territoryName);
    strcpy(countryLocation.countryName, countryName);
    strcpy(countryLocation.territoryRegion, territoryRegion);
    return countryLocation;
}

int readCountryLocations(CountryLocation arr[], int howMany)
{
    // Open the "world_country_locations.csv" file
    FILE *stream = fopen("dataset/world_country_locations.csv", "r");

    // If file does not exist, abort
    if (stream == NULL)
        return -1;

    int count = 0;
    char line[1024];
    fgets(line, 1024, stream);
    while (fgets(line, 1024, stream))
    {
        char *tmp = strdup(line);

        //  creates tokens[11] array, with tokens read from the file line
        char **tokens = splitString(tmp, 6, ";");

        char countryCode[3];
        strcpy(countryCode, tokens[0]);

        float latitude = atoi(tokens[1]);
        float longitude = atoi(tokens[2]);
        char territoryName[45];
        strcpy(territoryName, tokens[3]);

        char countryName[45];
        strcpy(countryName, tokens[4]);

        char territoryRegion[30];
        strcpy(territoryName, tokens[5]);

        // criação do countryLocation para posteriormente adicionar à lista
        arr[count++] = countryLocationCreate(countryCode, latitude, longitude, territoryName, countryName, territoryRegion);

        free(tokens);
        free(tmp);
    }

    fclose(stream);

    return count;
}