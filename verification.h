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

int parseCommands(char *buffer); // Goes command by command verifying it.
int isCommand(char *buffer, int startPos, int size); // Determines what is & is
                                                     // not a command.

#endif // !VERIFICATION_H
