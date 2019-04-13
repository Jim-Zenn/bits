/*
 * main.c
 * Copyright (C) 2019 Jim Zenn <zenn@ucla.edu>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>   // printf, fprintf
#include <ctype.h>   // isdigit
#include <stdlib.h>  // atoi
#include <limits.h>  // INT_MAX, INT_MIN

void printRepr(int x) {
  /* prints out the actual binary representation of int x (two's complement) */
  // casting type int to unsigned int preserves the bit pattern
  unsigned int ux = (unsigned int) x;
  char bits[32];
  for (unsigned short i = 0; i < 32; i ++) {
    bits[31 - i] = ux % 2 + '0';
    ux >>= 1;
  }
  printf("%s\n", bits);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: checkbits [INTEGER_LITERAL]\n");
    return 1;
  }
  char* xs = argv[1];
  for (int i = 0; xs[i] != '\0'; i++) {
    if (!isdigit(xs[i]) && !(xs[i] == '-')) {
      fprintf(stderr, "Usage: checkbits [INTEGER_LITERAL]\n");
      return 1;
    }
  }
  int x = atoi(xs);
  printRepr(x);
  return 0;
}

