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

#include <pthread.h>
#include <stdbool.h>

void *collectCommands(void *args);

extern int queue[];
extern int queueSize;
extern bool isNewCommand;
// TODO: I'm unsure if commandLock is neccessary or not
// extern pthread_mutex_t commandLock;
extern pthread_mutex_t sentinelLock;
extern pthread_mutex_t queueLock;
#endif // !COLLECT_COMMANDS_H
