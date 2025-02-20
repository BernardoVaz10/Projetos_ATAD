/**
 * @file countstaticShow.c
 * @brief Implementation of shows functions.
 * 
 * Functions to show data.
 * 
 * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt)
 * @bug No known bugs.
 */

#include "countryStatistics.h"
#include "map.h"
#include <string.h>
#include <stdio.h>

void ascendingSortByLiteracy(PtMap map)
{
    if (!mapIsEmpty(map))
    {
        int size;
        mapSize(map, &size);

        MapKey *keys = mapKeys(map);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                CountryStatistcs value1, value2;
                mapGet(map, keys[j], &value1);
                mapGet(map, keys[j + 1], &value2);
                if (value1.literacy > value2.literacy)
                {
                    MapKey aux = keys[j];
                    keys[j] = keys[j + 1];
                    keys[j + 1] = aux;
                }
                else if (value1.literacy == value2.literacy)
                {
                    if (value1.gdp_capita > value2.gdp_capita)
                    {
                        MapKey aux = keys[j];
                        keys[j] = keys[j + 1];
                        keys[j + 1] = aux;
                    }
                    else if (strcmp(keys[j].text, keys[j + 1].text) > 0)
                    {
                        MapKey aux = keys[j];
                        keys[j] = keys[j + 1];
                        keys[j + 1] = aux;
                    }
                }
            }
        }
        if (size < 50)
        {
            for (int i = 0; i < size; i++)
            {
                CountryStatistcs value1;
                mapGet(map, keys[i], &value1);
                countryStatisticsPrint(value1);
            }
        }
        else
        {
            for (int i = 0; i < 50; i++)
            {
                CountryStatistcs value1;
                mapGet(map, keys[i], &value1);
                countryStatisticsPrint(value1);
            }
        }
    }
    printf("O mapa fornecido está vazio!");
}

void descendingSortByLiteracy(PtMap map)
{
    if (!mapIsEmpty(map))
    {
        int size = 0;
        mapSize(map, &size);
        MapKey *keys = mapKeys(map);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                CountryStatistcs value1, value2;
                mapGet(map, keys[j], &value1);
                mapGet(map, keys[j + 1], &value2);
                if (value1.literacy < value2.literacy)
                {
                    MapKey aux = keys[j];
                    keys[j] = keys[j + 1];
                    keys[j + 1] = aux;
                }
                else if (value1.literacy == value2.literacy)
                {
                    if (value1.gdp_capita < value2.gdp_capita)
                    {
                        MapKey aux = keys[j];
                        keys[j] = keys[j + 1];
                        keys[j + 1] = aux;
                    }
                    else if (strcmp(keys[j].text, keys[j + 1].text) < 0)
                    {
                        MapKey aux = keys[j];
                        keys[j] = keys[j + 1];
                        keys[j + 1] = aux;
                    }
                }
            }
        }
        if (size < 50)
        {
            for (int i = 0; i < size; i++)
            {
                CountryStatistcs value1;
                mapGet(map, keys[i], &value1);
                countryStatisticsPrint(value1);
            }
        }
        else
        {
            for (int i = 0; i < 50; i++)
            {
                CountryStatistcs value1;
                mapGet(map, keys[i], &value1);
                countryStatisticsPrint(value1);
            }
        }
    }
    printf("O mapa fornecido está vazio!");
}

void ascendingSortByGdp(PtMap map)
{
    if (!mapIsEmpty(map))
    {
        int size = 0;
        mapSize(map, &size);
        MapKey *keys = mapKeys(map);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                CountryStatistcs value1, value2;
                mapGet(map, keys[j], &value1);
                mapGet(map, keys[j + 1], &value2);
                if (value1.gdp_capita > value2.gdp_capita)
                {
                    MapKey aux = keys[j];
                    keys[j] = keys[j + 1];
                    keys[j + 1] = aux;
                }
                else if (value1.gdp_capita == value2.gdp_capita)
                {
                    if (value1.literacy > value2.literacy)
                    {
                        MapKey aux = keys[j];
                        keys[j] = keys[j + 1];
                        keys[j + 1] = aux;
                    }
                    else if (strcmp(keys[j].text, keys[j + 1].text) > 0)
                    {
                        MapKey aux = keys[j];
                        keys[j] = keys[j + 1];
                        keys[j + 1] = aux;
                    }
                }
            }
        }
        if (size < 50)
        {
            for (int i = 0; i < size; i++)
            {
                CountryStatistcs value1;
                mapGet(map, keys[i], &value1);
                countryStatisticsPrint(value1);
            }
        }
        else
        {
            for (int i = 0; i < 50; i++)
            {
                CountryStatistcs value1;
                mapGet(map, keys[i], &value1);
                countryStatisticsPrint(value1);
            }
        }
    }
    printf("O mapa fornecido está vazio!");
}

void descendingSortByGdp(PtMap map)
{
    if (!mapIsEmpty(map))
    {
        int size = 0;
        mapSize(map, &size);
        MapKey *keys = mapKeys(map);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                CountryStatistcs value1, value2;
                mapGet(map, keys[j], &value1);
                mapGet(map, keys[j + 1], &value2);
                if (value1.gdp_capita < value2.gdp_capita)
                {
                    MapKey aux = keys[j];
                    keys[j] = keys[j + 1];
                    keys[j + 1] = aux;
                }
                else if (value1.gdp_capita == value2.gdp_capita)
                {
                    if (value1.literacy < value2.literacy)
                    {
                        MapKey aux = keys[j];
                        keys[j] = keys[j + 1];
                        keys[j + 1] = aux;
                    }
                    else if (strcmp(keys[j].text, keys[j + 1].text) < 0)
                    {
                        MapKey aux = keys[j];
                        keys[j] = keys[j + 1];
                        keys[j + 1] = aux;
                    }
                }
            }
        }
        if (size < 50)
        {
            for (int i = 0; i < size; i++)
            {
                CountryStatistcs value1;
                mapGet(map, keys[i], &value1);
                countryStatisticsPrint(value1);
            }
        }
        else
        {
            for (int i = 0; i < 50; i++)
            {
                CountryStatistcs value1;
                mapGet(map, keys[i], &value1);
                countryStatisticsPrint(value1);
            }
        }
    }
    printf("O mapa fornecido está vazio!");
}