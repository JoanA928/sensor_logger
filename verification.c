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

  while (token) {
    if (isCommand(token) != 0) {
      printf("Error: '%s' is not a command, type help to see a list of "
             "available commands\n",
             token);
      return 1;
    }
    token = strtok(NULL, &delimiter);
  }
  return 0;
}
int isCommand(const char *token) {
  // printf("I MADE IT HERE\n");
  char *commands[] = {"start\n", "stop\n", "read\n", "dump\n",
                      "stats\n", "mem\n",  "help\n"};
  int size = 7; // FIX: don't hardcode values!

  for (int index = 0; index < size; index++) {
    if (strcmp(token, commands[index]) == 0) {
      return 0;
    }
  }
  return 1;
}
