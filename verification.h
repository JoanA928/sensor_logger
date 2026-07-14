/***********************************************************************
 * Class:: N/A
 * Name::  Joan Aponte
 * Student ID:: 924074746
 * Github-Name:: JoanA928
 * Project:: Firmware - Data Logger
 * File:: verification.h
 *
 * Description:: This file declares helper functions for verifying if commands
 * from CLI are valid or not.
 *
 **********************************************************************/

#ifndef VERIFICATION_H
#define VERIFICATION_H

#include <pthread.h>

#define LOG_BUFFER_SIZE 1024 // TODO: Figure out why this number comes up a lot.

typedef enum {
  CMD_START,
  CMD_STOP,
  CMD_READ,
  CMD_DUMP,
  CMD_STATS,
  CMD_MEM,
  CMD_HELP
} command;

extern pthread_mutex_t queueLock;
extern char buffer[LOG_BUFFER_SIZE];
extern int queue[];
extern int queueSize;

void parseCommands();             // Goes command by command verifying it.
int isCommand(const char *token); // Determines what is & is
                                  // not a command.

#endif // !VERIFICATION_H
