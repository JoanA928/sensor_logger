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
#include "app_state.h"
#include "info_logger_macro.h"
#include <pthread.h>
#include <string.h>

void parseCommands() {

  const char *delimiter = " \n";
  int commandValue = CMD_NONE;
  /*
   *  Breaking up the verification process into pieces makes implmentation
   *  easier.
   */
  char *token = NULL;
  token = strtok(buffer, delimiter);
  if (!token) {
    LOG_ERROR("parsing command");
    return;
  }

  while (token) {
    commandValue = isCommand(token);
    LOG_DEBUG("the value of 'commandValue' is %d", commandValue);
    if (commandValue < 0) {
      LOG_ERROR("'%s' is not a command", token);
      return;
    }

    pthread_mutex_lock(&queueLock);
    if (queueSize <= MAX_QUEUE_SIZE && commandValue > CMD_NONE) {
      queue[queueSize] = commandValue;
      queueSize++;
      pthread_mutex_unlock(&queueLock);
      token = strtok(NULL, delimiter);
    }
    pthread_mutex_unlock(&queueLock);
  }
  return;
}

int isCommand(const char *token) {

  if (strcmp(token, "start") == 0) {
    LOG_DEBUG("'start' command detected");
    return CMD_START;
  } else if (strcmp(token, "stop") == 0) {
    LOG_DEBUG("'stop' command detected");
    return CMD_STOP;
  } else if (strcmp(token, "read") == 0) {
    LOG_DEBUG("'read' command detected");
    return CMD_READ;
  } else if (strcmp(token, "dump") == 0) {
    LOG_DEBUG("'dump' command detected");
    return CMD_DUMP;
  } else if (strcmp(token, "mem") == 0) {
    LOG_DEBUG("'mem' command detected");
    return CMD_MEM;
  } else if (strcmp(token, "help") == 0) {
    LOG_DEBUG("'help' command detected");
    return CMD_HELP;
  } else {
    LOG_DEBUG("Invalid command detected");
    return -1;
  }
}
