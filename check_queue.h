/***********************************************************************
 * Class:: N/A
 * Name::  Joan Aponte
 * Student ID:: 924074746
 * Github-Name:: JoanA928
 * Project:: Firmware - Data Logger
 * File:: check_queue.h
 *
 * Description:: // TODO: Fill me in.
 *
 **********************************************************************/

#ifndef CHECK_QUEUE_H
#define CHECK_QUEUE_H

#include <pthread.h>
#include <stdbool.h>

extern pthread_mutex_t sentinelLock;
extern int sentinelValue;
extern bool isNewCommand;
extern int queue[];
extern int queueSize;

void checkQueue();

#endif // !CHECK_QUEUE_H
