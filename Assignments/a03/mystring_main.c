/*
--------------------------------------------------
Project: CP264oc-a3q1
File:    mystring_main.c, a test driver
Author:  HBF
Version: 2021-05-11 (update)
--------------------------------------------------
*/
#include <stdio.h>
#include "mystring.h"

int main(int argc, char* args[]) {
  setbuf(stdout, NULL);
  char str[100] = "     This Is    a Test   ";
  printf("str:\"%s\"\n", str);
  printf("str_length(str):%d\n", str_length(str));  
  printf("word_count(str):%d\n", word_count(str)); 
  trim(str);
  lower_case(str);
  printf("trim(str):\"%s\"\n", str);
  printf("str_length(trim(str)):%d\n", str_length(str));
  return 0;
}
