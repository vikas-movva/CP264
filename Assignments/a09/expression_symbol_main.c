/*--------------------------------------------------
Project: cp264oc-a6q2
File:    expression_symbol_main.c
Description: public testing driveer
Author:  HBF
Version: 2021-05-11
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "expression_symbol.h"

int htsize = 10;

int main(int argc, char *args[])
{
  char infilename[40] = "expression.txt";
  if (argc > 1)
    strcpy(infilename, args[1]);

  if (argc > 2)
    htsize = atoi(args[2]);

  HASHTABLE *ht = new_hashtable(htsize);

  char line[100];
  char delimiters[] = ";\n";
  char *st;

  FILE *fp = fopen(infilename, "r");
  if (fp == NULL)
  {
    perror("Error while opening the file.\n");
    return 0;
  }

  printf("Symbolic expressions:\n");
  while (fgets(line, sizeof(line), fp) != NULL)
  {
    st = strtok(line, delimiters);
    printf("%s\n", st);
    while (st != NULL)
    {
      resolve_symbol(st, ht);
      st = strtok(NULL, delimiters);
    }
  }
  fclose(fp);

  printf("\nSymbolic expression evaluation:\n");
  display_hashtable(ht, 1);

  clean_hash(&ht);

  return 0;
}
