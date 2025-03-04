/**
 * @file util.c
 * @brief Implementation of util functions.
 * 
 * Functions to util data.
 * 
 * @author Bernardo Vaz(202200278@estudantes.ips.pt), Tiago Ramada(202200354@estudantes.ips.pt), Daniel Pais(202200286@estudantes.ips.pt), Tomás Alves(202200285@estudantes.ips.pt)
 * @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#include "util.h"
#include "input.h"


int equalsStringIgnoreCase(char str1[], char str2[]) {
	/* Apenas faz uma comparacao utilizando o strcmp.
	* Necessita de tansformar primeiro as strings em maiusculas */
	char str1Up[256], str2Up[256];
	strToUpper(str1,str1Up);
	strToUpper(str2,str2Up);
	return (strcmp(str1Up, str2Up) == 0);
}

void strToUpper(const char *orig, char *dest) {
  int len = strlen(orig);
  for(int i=0; i<len; i++) {
    dest[i] = toupper(orig[i]);
  } 
  dest[len] = '\0';
}