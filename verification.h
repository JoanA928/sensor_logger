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

#define LOG_BUFFER_SIZE 1024 // TODO: Figure out why this number comes up a lot.

extern char buffer[LOG_BUFFER_SIZE];

int parseCommands();              // Goes command by command verifying it.
int isCommand(const char *token); // Determines what is & is
                                  // not a command.

#endif // !VERIFICATION_H
