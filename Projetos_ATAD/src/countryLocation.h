/**
 * @file countryLocation.h
 * @brief CountryLocation functions.
 *
 * Functions to read and create countryLocation data.
 *
 * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt)
 * @bug No known bugs.
 */

#pragma once

typedef struct countryLocation
{
    char code[3]; // Igual a countryStatistics se país mas diferente se for dependente
    float latitude;
    float longitude;
    char territoryName[45];   // Nome do território
    char countryName[45];     // Nome do país associado se território dependente, se não N.A.
    char territoryRegion[30]; // Nome da região se for território dependente, se não N.A
    // Existem duas novas regiões INDIAN OCEAN e SOUTH ATLANTIC
} CountryLocation;

/**
 * @brief Reads the countryLocation data from a file.
 *
 * @return int The number of countryLocations read.
 */
int readCountryLocations(CountryLocation arr[], int howMany);

/**
 * @brief Creates a new countryLocation.
 *
 * @param code The countryLocation code.
 * @param latitude The countryLocation latitude.
 * @param longitude The countryLocation longitude.
 * @param territoryName The countryLocation territoryName.
 * @param countryName The countryLocation countryName.
 * @param territoryRegion The countryLocation territoryRegion.
 * @return CountryLocation The new countryLocation.
 */
CountryLocation countryLocationCreate(char code[3], float latitude, float longitude, char territoryName[45], char countryName[45], char territoryRegion[30]);