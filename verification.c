/***********************************************************************
 * Class:: N/A
 * Name::  Joan Aponte
 * Student ID:: 924074746
 * Github-Name:: JoanA928
 * Project:: Firmware - Data Logger
 * File:: verification.c
 *
 * Description:: This file defines helper functions for verifying if commands
 * from CLI are valid or not.
 *
 **********************************************************************/

#include "verification.h"
#include <stdio.h>
#include <string.h>

int parseCommands() {
  printf("I made it here\n");
  const char delimiter = ' ';
  /*
   *  Breaking up the verification process into pieces makes implmentation
   *  easier.
   */
  char *token;
  token = strtok(buffer, &delimiter);
  if (!token) {
    printf("Error: failed to read token\n");
    return 1;
  }
  printf("We got your input: %s\n", token);
  return 0;
}
int isCommand(const char *token) { return 0; }
