#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

char * strDeepCopy(const char *str) {
  char *copy = (char *) malloc(sizeof(char) * (strlen(str)+1));
  strcpy(copy, str);
  return copy;
}
