/**
 * @file loaders.h
 * @brief Implementation of loaders functions.
 * 
 * Functions to read data.
 * 
 * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt)
 * @bug No known bugs.
 */

#pragma once

#include "earthquake.h"
#include "countryStatistics.h"
#include "list.h"
#include "map.h"

/**
 * @brief Reads the earthquakes from the file and stores them in a list.
 *
 * @param list The list where the earthquakes will be stored.
 * @return int The number of earthquakes read.
 */
int readEarthquakes(PtList list);

/**
 * @brief Reads the countryStatistics data from a file.
 *
 * @param filename The name of the file to read from.
 * @param countryStatistics The array to store the countryStatistics.
 * @param size The size of the array.
 * @return int The number of countryStatistics read.
 */
int readCountryStatistics(PtMap map);
