/***********************************************************************
 * Class:: N/A
 * Name::  Joan Aponte
 * Student ID:: 924074746
 * Github-Name:: JoanA928
 * Project:: Firmware - Data Logger
 * File:: logger.h
 *
 * Description:: TODO: Fill me in.
 *
 **********************************************************************/

#ifndef LOGGER_H
#define LOGGER_H

#include "generate_data.h"
#include <pthread.h>

extern pthread_mutex_t dataLock;
extern packet data;

void *logger(void *args);
#endif // !LOGGER_H
