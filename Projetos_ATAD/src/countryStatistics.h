/**
 * @file countryStatistics.h
 * @brief CountryStatistics functions.
 * 
 * Functions to read and create countryStatistics data.
 * 
 * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt)
 * @bug No known bugs.
 */

#pragma once

// tirar code, porque o countryStatistis vai ser um map e o map é dividido em Key(StringWrap) e Value(CountryStatistics) como o code é a Key do Map
// não pode estar no value, ou seja, nao pode haver 2 atributos code em que um é o key e o outro também está presente no value

typedef struct countryStatistics
{
    char code[3]; // Código de 2 letras que representa o país
    char name[40];
    char region[30]; // UN Regions + ANTARCTICA + SOUTH ATLANTIC + INDIAN OCEAN
    long population;
    long area;
    long gdp_capita; // Produto interno bruto per capita. Contém valores N.A.
    float literacy;  // Percentagem de literacia. Contém valores N.A.
    float birthrate; // Número de nascimentos por 1000 pessoas por ano. Contém valores N.A. 
    float deathrate; // Número de mortes por 1000 pessoas por ano. Contém valores N.A.
} CountryStatistcs;

/**
 * @brief Creates a countryStatistics.
 *
 * @param code The code of the countryStatistics.
 * @param name The name of the countryStatistics.
 * @param region The region of the countryStatistics.
 * @param population The population of the countryStatistics.
 * @param area The area of the countryStatistics.
 * @param gdp_capita The gdp_capita of the countryStatistics.
 * @param literacy The literacy of the countryStatistics.
 * @param birthrate The birthrate of the countryStatistics.
 * @param deathrate The deathrate of the countryStatistics.
 * @return CountryStatistics The created countryStatistics.
 */
CountryStatistcs countryStatisticsCreate(char code[3], char name[40], char region[30],
                                          long population, long area, long gdp_capita, float literacy, float birthrate,
                                          float deathrate);

/**
 * @brief Prints a countryStatistics.
 * 
 * @param country The countryStatistics to print.
*/
void countryStatisticsPrint(CountryStatistcs country);

