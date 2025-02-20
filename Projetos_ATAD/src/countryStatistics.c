/**
 * @file countryStatistics.c
 * @brief Implementation of countryStatistics functions.
 * 
 * Functions to read and create countryStatistics data.
 * 
 * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt)
 * @bug No known bugs.
 */

#include "countryStatistics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "input.h"


CountryStatistcs countryStatisticsCreate(char code[3], char name[40], char region[30],
                                          long population, long area, long gdp_capita, float literacy, float birthrate,
                                          float deathrate)
{
    CountryStatistcs countryStatistics;
    strcpy(countryStatistics.code, code);
    strcpy(countryStatistics.name, name);
    strcpy(countryStatistics.region, region);
    countryStatistics.population = population;
    countryStatistics.area = area;
    countryStatistics.gdp_capita = gdp_capita;
    countryStatistics.literacy = literacy;
    countryStatistics.birthrate = birthrate;
    countryStatistics.deathrate = deathrate;
    return countryStatistics;
}

void countryStatisticsPrint(CountryStatistcs country) {
    printf("%s\t%s\t%ld\t%ld\t%ld\t%f\t%f\t%f\n", /*country.code*/ country.name, country.region, country.population, country.area, country.gdp_capita, country.literacy, country.birthrate, country.deathrate);
}



