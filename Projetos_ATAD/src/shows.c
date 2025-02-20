/**
 * @file shows.c
 * @brief Implementation of shows functions.
 * 
 * Functions to show data.
 * 
 * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt)
 * @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "earthquake.h"
#include "time.h"
#include "list.h"

void earthquakeListShowAll(PtList list, int *ptEarthquakeListCount, int *ptPageCount)
{
    ListElem elem;
    int eCount = *ptEarthquakeListCount;
    int pCount = *ptPageCount;
    for (int i = eCount; i < eCount + 50; i++)
    {
        listGet(list, i, &elem);
        // print elem
        printf("%d %s %d/%d/%d %d:%d:%d %f %f %s %f %f %s\n", elem.id, elem.countryCode, elem.date.day, elem.date.month, elem.date.year, elem.time.hour, elem.time.min, elem.time.sec, elem.latitude, elem.longitude, elem.type, elem.depth, elem.magnitude, elem.magnitudeType);
    }
    printf("------------------ Page %d ---------------------\n", pCount);
    printf("SHOWALL PAGINATED\n");
    printf("Press 1 to display next page or 2 to return.\n");
    *ptPageCount = pCount + 1;
    *ptEarthquakeListCount = eCount + 50;
}

void earthquakeListGetYearCount(PtList list, int year, int *count)
{
    ListElem elem;
    int size;
    int c = 0;
    listSize(list, &size);
    for (int i = 0; i < size; i++)
    {
        listGet(list, i, &elem);
        int test = elem.date.year;
        if (test == year)
        {
            c++;
        }
    }
    *count = c;
}

void earthquakeListShowYear(PtList list, int year)
{
    ListElem elem;
    int size;
    listSize(list, &size);
    for (int i = 0; i < size; i++)
    {
        listGet(list, i, &elem);
        if (elem.date.year == year)
        {
            // print elem
            printf("%d %s %d/%d/%d %d:%d:%d %f %f %s %f %f %s\n", elem.id, elem.countryCode, elem.date.day, elem.date.month, elem.date.year, elem.time.hour, elem.time.min, elem.time.sec, elem.latitude, elem.longitude, elem.type, elem.depth, elem.magnitude, elem.magnitudeType);
        }
    }
}

void earthquakeListGetCountryCount(PtList earthquakeList, char countryCode, int *count)
{
    ListElem elem;
    int size;
    int c = 0;
    listSize(earthquakeList, &size);
    for (int i = 0; i < size; i++)
    {
        listGet(earthquakeList, i, &elem);
        if (elem.countryCode[0] == countryCode)
        {
            c++;
        }
    }
    *count = c;
}

void earthquakeListShowCountry(PtList earthquakeList, char countryCode)
{
    ListElem elem;
    int size;
    listSize(earthquakeList, &size);

    for (int i = 0; i < size; i++)
    {
        listGet(earthquakeList, i, &elem);
        if (elem.countryCode[0] == countryCode)
        {
            // print elem
            printf("%d %s %d/%d/%d %d:%d:%d %f %f %s %f %f %s\n", elem.id, elem.countryCode, elem.date.day, elem.date.month, elem.date.year, elem.time.hour, elem.time.min, elem.time.sec, elem.latitude, elem.longitude, elem.type, elem.depth, elem.magnitude, elem.magnitudeType);
        }
    }
}

void earthquakeListGetCountryYearCount(PtList earthquakeList, char countryCode, int year, int *count)
{
    ListElem elem;
    int size;
    int c = 0;
    listSize(earthquakeList, &size);
    for (int i = 0; i < size; i++)
    {
        listGet(earthquakeList, i, &elem);
        if (elem.countryCode[0] == countryCode && elem.date.year == year)
        {
            c++;
        }
    }
    *count = c;
}

void earthquakeListShowCountryYear(PtList earthquakeList, char countryCode, int year)
{
    ListElem elem;
    int size;
    listSize(earthquakeList, &size);
    for (int i = 0; i < size; i++)
    {
        listGet(earthquakeList, i, &elem);
        if (elem.countryCode[0] == countryCode && elem.date.year == year)
        {
            // print elem
            printf("%d %s %d/%d/%d %d:%d:%d %f %f %s %f %f %s\n", elem.id, elem.countryCode, elem.date.day, elem.date.month, elem.date.year, elem.time.hour, elem.time.min, elem.time.sec, elem.latitude, elem.longitude, elem.type, elem.depth, elem.magnitude, elem.magnitudeType);
        }
    }
}

void earthquakeUniqueCountryCodePrint(PtList earthquakeList, int *count) // PtList earthquakeList
{
    // Mostra a lista de códigos de países/territórios que têm dados de terramotos, sem repetições de códigos
    ListElem elem;
    int size;
    int c = 0;
    // array to store unique country codes
    listSize(earthquakeList, &size);
    char uniqueCountryCodes[size][3];
    for (int i = 0; i < size; i++)
    {
        listGet(earthquakeList, i, &elem);
        // check if country code is already in array
        int found = 0;
        for (int j = 0; j < c; j++)
        {
            // print comparison
            if (elem.countryCode[0] == uniqueCountryCodes[j][0] && elem.countryCode[1] == uniqueCountryCodes[j][1])
            {
                found = 1;
            }
        }
        if (found == 0)
        {
            // add country code to array
            strcpy(uniqueCountryCodes[c], elem.countryCode);
            c++;
        }
    }
    // print array
    for (int i = 0; i < c; i++)
    {
        printf("%s\n", uniqueCountryCodes[i]);
    }

    *count = c;
}

void earthquakeListGetCountryMagnitudeCount(PtList earthquakeList,char *countryCode,double min,double max,int *count) {
    ListElem elem;
    int size;
    int c = 0;
    listSize(earthquakeList, &size);
    for (int i = 0; i < size; i++)
    {
        listGet(earthquakeList, i, &elem);
        if (elem.countryCode[0] == countryCode[0] && elem.countryCode[1] == countryCode[1] && elem.magnitude >= min && elem.magnitude <= max)
        {
            c++;
        }
    }
    *count = c;
}

void earthquakeListShowCountryMagnitude(PtList earthquakeList, char *countryCode, double min, double max) {
    ListElem elem;
    int size;
    int c = 0;
    int mw = 0;
    int mb = 0;
    int ms = 0;
    listSize(earthquakeList, &size);
    
    for (int i = 0; i < size; i++) {
        listGet(earthquakeList, i, &elem);
        if (elem.countryCode[0] == countryCode[0] && elem.countryCode[1] == countryCode[1] && elem.magnitude >= min && elem.magnitude <= max) {
            c++;
            if (strcmp(elem.type, "MW") == 0) {
                mw++;
            }
            else if (strcmp(elem.type, "MB") == 0) {
                mb++;
            }
            else if (strcmp(elem.type, "MS") == 0) {
                ms++;
            }
        }
    }
    
    printf("Earthquakes percentage per type:\n");
    printf("MW  |   MB  |   MS  |\n");
    printf("%.1f%% | %.1f%% | %.1f%% |\n", (double)mw / c * 100.0, (double)mb / c * 100.0, (double)ms / c * 100.0);
}
