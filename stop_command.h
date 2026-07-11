/***********************************************************************
 * Class:: N/A
 * Name::  Joan Aponte
 * Student ID:: 924074746
 * Github-Name:: JoanA928
 * Project:: Firmware - Data Logger
 * File:: stop_command.h
 *
 * Description:: This file is responible for processing the stop command.
 *
 **********************************************************************/

#ifndef STOP_COMMAND_H
#define STOP_COMMAND_H

extern sentinelValue;
extern pthread_mutex_t commandLock;

void stopCommand(void *args);

#endif // !STOP_COMMAND_H
