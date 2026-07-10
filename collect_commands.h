/***********************************************************************
 * Class:: N/A
 * Name::  Joan Aponte
 * Student ID:: 924074746
 * Github-Name:: JoanA928
 * Project:: Firmware - Data Logger
 * File:: collect_commands.h
 *
 * Description:: // TODO: fill me in
 *
 **********************************************************************/

#ifndef COLLECT_COMMANDS_H
#define COLLECT_COMMANDS_H

#include <pthread>

void *collectCommands(void *args);

extern pthread_mutex_t commandLock;
extern int isCommand;
#endif // !COLLECT_COMMANDS_H
