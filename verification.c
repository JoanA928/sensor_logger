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
#include "info_logger_macro.h"
#include <stdio.h>
#include <string.h>

int parseCommands() {

  const char *delimiter = " \n";
  /*
   *  Breaking up the verification process into pieces makes implmentation
   *  easier.
   */
  char *token;
  token = strtok(buffer, delimiter);
  if (!token) {
    LOG_ERROR("parsing command");
    return 1;
  }

  while (token) {
    if (isCommand(token) != 0) {
      LOG_ERROR("'%s' is not a command", token);
      return 1;
    }
    token = strtok(NULL, delimiter);
  }
  return 0;
}
int isCommand(const char *token) {
  // printf("I MADE IT HERE\n");
  const char *commands[] = {"start", "stop", "read", "dump",
                            "stats", "mem",  "help"};
  int size = 7; // FIX: don't hardcode values!

  for (int index = 0; index < size; index++) {
    if (strcmp(token, commands[index]) == 0) {
      LOG_INFO("command: %s", token);
      queue[index] = token;
      return 0;
    }
  }
  return 1;
}
