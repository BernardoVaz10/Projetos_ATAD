/**
 * @file countstaticShow.h
 * @brief Shows functions.
 * 
 * Functions to show data.
 * 
 * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt)
 * @bug No known bugs.
 */

#pragma once

#include "countstaticShow.h"
#include <stdbool.h>
#include "map.h"


/**
 * @brief Shows all earthquakes.
 * 
 * @param list [in] pointer to the list
 * @param ptEarthquakeListCount [in] pointer to the earthquake list count
 * @param ptPageCount [in] pointer to the page count
 */
void ascendingSortByLiteracy(PtMap map);

/**
 * @brief Gets the earthquake count by year.
 * 
 * @param list [in] pointer to the list
 * @param year [in] year
 * @param count [in] pointer to the count
 */
void descendingSortByLiteracy(PtMap map);

/**
 * @brief Shows the earthquakes by year.
 * 
 * @param list [in] pointer to the list
 * @param year [in] year
 */
void ascendingSortByGdp(PtMap map);

/**
 * @brief Gets the earthquake count by country.
 * 
 * @param list [in] pointer to the list
 * @param countryCode [in] country code
 * @param count [in] pointer to the count
 */
void descendingSortByGdp(PtMap map);