/**
 * @file earthquake.c
 * @brief Implementation of earthquake functions.
 * 
 * Functions to read and create earthquake data.
 * 
 * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt)
 * @bug No known bugs.
 */

#include "earthquake.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "input.h"
#include "earthquake.h"
#include "list.h"

Earthquake earthquakeCreate(int id, char countryCode[3], Date date, Time time, float latitude, float longitude, char type[20], float depth, float magnitude, char magnitudeType[3])
{
    Earthquake earthquake;
    earthquake.id = id;
    strcpy(earthquake.countryCode, countryCode);
    earthquake.date = date;
    earthquake.time = time;
    earthquake.latitude = latitude;
    earthquake.longitude = longitude;
    strcpy(earthquake.type, type);
    earthquake.depth = depth;
    earthquake.magnitude = magnitude;
    strcpy(earthquake.magnitudeType, magnitudeType);
    return earthquake;
}

char *calculateCountryCode(float latitude, float longitude)
{
    // Open the "countryLocations.csv" file
    FILE *stream = fopen("dataset/world_country_locations.csv", "r");

    // If file does not exist, abort
    if (stream == NULL)
        return NULL;

    char line[1024];
    fgets(line, 1024, stream);
    while (fgets(line, 1024, stream))
    {
        char *tmp = strdup(line);

        //  creates tokens[11] array, with tokens read from the file line
        char **tokens = splitString(tmp, 9, ";");

        float lat = atof(tokens[1]);
        float lon = atof(tokens[2]);

        if (calculateDistance(latitude, longitude, lat, lon) < 100)
        {
            return tokens[0];
        }

        free(tokens);
        free(tmp);
    }

    fclose(stream);

    return NULL;
}

double calculateDistance(float lat1, float lon1, float lat2, float lon2)
{
    double latDiff = lat2 - lat1;
    double lonDiff = lon2 - lon1;
    return sqrt(latDiff * latDiff + lonDiff * lonDiff);
}