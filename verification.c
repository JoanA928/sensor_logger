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
    if (isCommand(token) < 0) {
      LOG_ERROR("'%s' is not a command", token);
      return 1;
    }
    token = strtok(NULL, delimiter);
  }
  return 0;
}

int isCommand(const char *token) {

  if (strcmp(token, "start") == 0) {
    LOG_INFO("'start' command detected");
    return CMD_START;
  } else if (strcmp(token, "stop") == 0) {
    LOG_INFO("'stop' command detected");
    return CMD_STOP;
  } else if (strcmp(token, "read") == 0) {
    LOG_INFO("'read' command detected");
    return CMD_READ;
  } else if (strcmp(token, "dump") == 0) {
    LOG_INFO("'dump' command detected");
    return CMD_DUMP;
  } else if (strcmp(token, "mem") == 0) {
    LOG_INFO("'mem' command detected");
    return CMD_MEM;
  } else if (strcmp(token, "help") == 0) {
    LOG_INFO("'help' command detected");
    return CMD_HELP;
  } else {
    LOG_INFO("Invalid command detected");
    return -1;
  }
}
