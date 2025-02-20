#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

#include "stringWrap.h"
#include "input.h"
#include "util.h"
#include "list.h"
#include "map.h"
#include "shows.h"
#include "countryLocation.h"
#include "earthquake.h"
#include "loaders.h"
#include "countstaticShow.h"
#include "countryEarthquake.h"

/**
 * @brief Prints the command menu.
 */
void printMenu();
/**
 * @brief Waits for user to press a key.
 */
void waitForKeypress();

/**
 * @brief Program entry point.
 * @return int error code: EXIT_SUCCESS or EXIT_FAILURE
 */
int main()
{
	/* Feel free to change whatever you want. */

	// TODO: variables ?
	CountryLocation *countryLocation = (CountryLocation *)malloc(sizeof(CountryLocation) * 245);
	int countryLocationSize = 0;
	PtList earthquakeList = listCreate();
	PtMap countryStatisticsMap = mapCreate();

	/* Command interpreter. */
	char command[100];
	while (true)
	{

		printMenu();
		readString(command, 100);

		if (strcasecmp(command, "QUIT") == 0)
		{
			// Break loop, effectively leaving the command line
			break;
		}
		else if (strcasecmp(command, "LOADCL") == 0)
		{
			int importedNumber = readCountryLocations(countryLocation, 245);
			countryLocationSize = importedNumber;
			printf("<%d> country location records imported", importedNumber);
		}
		else if (strcasecmp(command, "LOADEA") == 0)
		{
			int importedNumber = readEarthquakes(earthquakeList);
			printf("<%d> country location records imported", importedNumber);
		}
		else if (strcasecmp(command, "LOADST") == 0)
		{
			int importedNumber = readCountryStatistics(countryStatisticsMap);
			printf("<%d> country location records imported", importedNumber);
		}
		else if (strcasecmp(command, "CLEAR") == 0)
		{
			int earthquakeListSize;
			int countryStatisticsMapSize;
			listSize(earthquakeList, &earthquakeListSize);
			mapSize(countryStatisticsMap, &countryStatisticsMapSize);

			mapClear(countryStatisticsMap);
			listClear(earthquakeList);

			int totalRecords = earthquakeListSize + countryStatisticsMapSize + countryLocationSize;
			printf("%d records deleted from <Earthquake | CountryStatistics | CountryLocation>", totalRecords);
		}
		else if (strcasecmp(command, "SHOWALL") == 0)
		{
			// Insert call for function here ...
			int earthquakeListSize;
			listSize(earthquakeList, &earthquakeListSize);
			printf("Total of earthquakes: %d\n\n", earthquakeListSize);

			bool continueFunction = true;
			while (continueFunction)
			{
				int actuallistcount;
				int actualpage;
				earthquakeListShowAll(earthquakeList, &actuallistcount, &actualpage);
				fgets(command, sizeof(command), stdin);
				command[strlen(command) - 1] = '\0';
				if (equalsStringIgnoreCase(command, "1"))
				{
					int ptInt = 1;
					int ptPage = 1;
					earthquakeListShowAll(earthquakeList, &ptInt, &ptPage);
					fgets(command, sizeof(command), stdin);
					command[strlen(command) - 1] = '\0';
					while (!equalsStringIgnoreCase(command, "2"))
					{
						earthquakeListShowAll(earthquakeList, &ptInt, &ptPage);
						fgets(command, sizeof(command), stdin);
						command[strlen(command) - 1] = '\0';
					}
					continueFunction = false;
				}
				else if (equalsStringIgnoreCase(command, "2"))
				{
					continueFunction = false;
				}
				else
				{
					printf("Command not found! Command must be 1 or 2\n");
					waitForKeypress();
				}
			}
		}

		// TODO: Other commands checking through else if's
		else if (strcasecmp(command, "SHOW_Y") == 0)
		{
			int year;
			printf("Year: ");
			scanf("%d", &year);
			int count;
			earthquakeListGetYearCount(earthquakeList, year, &count);
			if (count == 0)
			{
				printf("Earthquake data not available for year %d", year);
			}
			else // ele chega aqui o count e diferente de 0 mas não mostra, deduzo que seja o metodo do showlistyear
			{
				printf("Number of earthquakes in %d: %d\n\n", year, count);
				earthquakeListShowYear(earthquakeList, year);
			}
		}
		else if (strcasecmp(command, "SHOW_T") == 0)
		{
			char countryCode[3];
			printf("Country Code: ");
			scanf("%s", countryCode);
			int count;
			earthquakeListGetCountryCount(earthquakeList, *countryCode, &count);
			if (count == 0)
			{
				printf("Earthquake data not available for %s", countryCode);
			}
			else
			{
				printf("Number of earthquakes in %s: %d\n\n", countryCode, count);
				earthquakeListShowCountry(earthquakeList, *countryCode);
			}
		}
		else if (strcasecmp(command, "SHOW_YT") == 0)
		{
			// SO COMPARA A PRIMEIRA LETRA
			char countryCode[3];
			printf("Country Code: ");
			scanf("%s", countryCode);
			int year;
			printf("Year: ");
			scanf("%d", &year);
			int count;
			earthquakeListGetCountryYearCount(earthquakeList, *countryCode, year, &count);
			if (count == 0)
			{
				printf("Earthquake data not available for %s in %d", countryCode, year);
			}
			else
			{
				printf("Number of earthquakes in %s in %d: %d", countryCode, year, count);
				earthquakeListShowCountryYear(earthquakeList, *countryCode, year);
			}
		}
		else if (strcasecmp(command, "LIST_T") == 0)
		{
			// Mostra a lista de códigos de países/territórios que têm dados de terramotos, sem repetições de códigos. Antes de apresentar a listagem deve apresentar o número de países/territórios encontrados.
			int count;
			earthquakeUniqueCountryCodePrint(earthquakeList, &count);
			if (count == 0)
			{
				printf("Earthquake data not available.");
			}
			else
			{
				printf("%d countries with earthquake data", count);
			}
		}
		else if (strcasecmp(command, "COUNT") == 0)
		{
			double min;
			double max;
			char countryCode[3];
			printf("Minimum magnitude: ");
			scanf("%lf", &min);
			printf("Maximum magnitude: ");
			scanf("%lf", &max);
			printf("Country Code: ");
			scanf("%s", countryCode);

			int count;
			earthquakeListGetCountryMagnitudeCount(earthquakeList, countryCode, min, max, &count);
			if (count == 0)
			{
				printf("Earthquake data not available for magnitude between [%.1lf,%.1lf]", min, max);
			}
			else
			{
				printf("Number of earthquakes in %s with magnitude between [%.1lf,%.1lf]: %d\n\n", countryCode, min, max, count);
				earthquakeListShowCountryMagnitude(earthquakeList, countryCode, min, max);
			}
		}
		else if (strcasecmp(command, "COUNTRY_S") == 0)
		{
			char decision[10];
			char sort[5];
			printf("Qual é o critério principal que vai utilizar para a ordenação?[LITERACY][GDP]");
			scanf("%s", decision);
			printf("Qual é a ordem de ordenação?[ASC][DESC]");
			scanf("%s", sort);
			if (strcasecmp(decision, "LITERACY") == 0)
			{
				if (strcasecmp(sort, "ASC") == 0)
				{
					ascendingSortByLiteracy(countryStatisticsMap);
				}
				else if (strcasecmp(sort, "DESC") == 0)
				{
					descendingSortByLiteracy(countryStatisticsMap);
				}
				else
				{
					printf("Command not found! Command must be ASC or DESC\n");
					waitForKeypress();
				}
			}
			else if (strcasecmp(decision, "GDP") == 0)
			{
				if (strcasecmp(sort, "ASC") == 0)
				{
					ascendingSortByGdp(countryStatisticsMap);
				}
				else if (strcasecmp(sort, "DESC") == 0)
				{
					descendingSortByGdp(countryStatisticsMap);
				}
				else
				{
					printf("Command not found! Command must be ASC or DESC\n");
					waitForKeypress();
				}
			}
			else
			{
				printf("Command not found! Command must be LITERACY or GDP\n");
				waitForKeypress();
			}
		}
		else if (strcasecmp(command, "TOPN") == 0)
		{
			int rankSize;
			printf("Size of the ranking: ");
			scanf("%d", &rankSize);

			CountryEarthquakeData countryDataArray[23409];
			calculateCountryEarthquakeData(earthquakeList, countryDataArray);
			getTopNCountries(countryDataArray, rankSize);
		}

		else
		{
			printf("Command not found.");
		}

		waitForKeypress();
	}

	// TODO: Any memory cleanup before end of program?
	listDestroy(&earthquakeList);
	mapDestroy(&countryStatisticsMap);
	free(countryLocation);

	return EXIT_SUCCESS;
}

void printMenu()
{
	printf("\n===================================================================================");
	printf("\n                          EarthQuake Data Analysis ");
	printf("\n===================================================================================");
	printf("\nA. Base commands (LOADCL, LOADEA, LOADST, CLEAR).");
	printf("\nB. Aggregated info about earthquakes (SHOWALL, SHOW_Y, SHOW_T, SHOW_YT, LIST_T, COUNT, HISTOGRAM");
	printf("\nC. Aggregated info about countries and regions (COUNTRY_S, REGION_AVG).");
	printf("\nD. Complex indicators; require earthquake and country data (TOPN).");
	printf("\n\nExit (QUIT)\n\n");
	printf("COMMAND?> ");
}

void waitForKeypress()
{
	printf("\n\nPress any key to continue ...");
	getchar();
}
