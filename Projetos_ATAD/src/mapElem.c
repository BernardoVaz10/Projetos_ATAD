/**
 * @file mapElem.c
 * @brief Implements operations for types MapKey and MapValue.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "mapElem.h"
#include <stdio.h>
#include <string.h>

void mapKeyPrint(MapKey key) {
	stringWrapPrint(key);
}

void mapValuePrint(MapValue value) {
	countryStatisticsPrint(value);
}

int mapKeyCompare(MapKey key1, MapKey key2) {
	// in case of integer keys:
	return (strcmp(key1.text,key2.text)==0); 
}