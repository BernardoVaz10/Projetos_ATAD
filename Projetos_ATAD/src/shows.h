/**
 * @file shows.h
 * @brief Shows functions.
 * 
 * Functions to show data.
 * 
 * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt)
 * @bug No known bugs.
 */

#pragma once

#include "earthquake.h"
#include "countryStatistics.h"
#include "list.h"

/**
 * @brief Shows all earthquakes.
 * 
 * @param list [in] pointer to the list
 * @param ptEarthquakeListCount [in] pointer to the earthquake list count
 * @param ptPageCount [in] pointer to the page count
 */
void earthquakeListShowAll(PtList list, int *ptEarthquakeListCount, int *ptPageCount);

/**
 * @brief Gets the earthquake count by year.
 * 
 * @param list [in] pointer to the list
 * @param year [in] year
 * @param count [in] pointer to the count
 */
void earthquakeListGetYearCount(PtList list, int year, int *count);

/**
 * @brief Shows the earthquakes by year.
 * 
 * @param list [in] pointer to the list
 * @param year [in] year
 */
void earthquakeListShowYear(PtList earthquakeList,int year);

/**
 * @brief Gets the earthquake count by country.
 * 
 * @param list [in] pointer to the list
 * @param countryCode [in] country code
 * @param count [in] pointer to the count
 */
void earthquakeListGetCountryCount(PtList earthquakeList,char countryCode,int *count);

/**
 * @brief Shows the earthquakes by country.
 * 
 * @param list [in] pointer to the list
 * @param countryCode [in] country code
 */
void earthquakeListShowCountry(PtList earthquakeList,char countryCode);

/**
 * @brief Gets the earthquake count by country and year.
 * 
 * @param list [in] pointer to the list
 * @param countryCode [in] country code
 * @param year [in] year
 * @param count [in] pointer to the count
 */
void earthquakeListGetCountryYearCount(PtList earthquakeList,char countryCode,int year,int *count);

/**
 * @brief Shows the earthquakes by country and year.
 * 
 * @param list [in] pointer to the list
 * @param countryCode [in] country code
 * @param year [in] year
 */
void earthquakeListShowCountryYear(PtList earthquakeList, char countryCode,int year);

/**
 * @brief Gets the earthquake count by country and magnitude.
 * 
 * @param list [in] pointer to the list
 * @param countryCode [in] country code
 * @param min [in] minimum magnitude
 * @param max [in] maximum magnitude
 * @param count [in] pointer to the count
 */
void earthquakeUniqueCountryCodePrint(PtList earthquakeList, int *count);

/**
 * @brief Gets the earthquake count by country and magnitude.
 * 
 * @param list [in] pointer to the list
 * @param countryCode [in] country code
 * @param min [in] minimum magnitude
 * @param max [in] maximum magnitude
 * @param count [in] pointer to the count
 */
void earthquakeListGetCountryMagnitudeCount(PtList earthquakeList,char *countryCode,double min,double max,int *count);

/**
 * @brief Shows the earthquakes by country and magnitude.
 * 
 * @param list [in] pointer to the list
 * @param countryCode [in] country code
 * @param min [in] minimum magnitude
 * @param max [in] maximum magnitude
 */
void earthquakeListShowCountryMagnitude(PtList earthquakeList,char *countryCode,double min,double max);