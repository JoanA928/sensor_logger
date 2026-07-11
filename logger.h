/***********************************************************************
 * Class:: N/A
 * Name::  Joan Aponte
 * Student ID:: 924074746
 * Github-Name:: JoanA928
 * Project:: Firmware - Data Logger
 * File:: main.c
 *
 * Description:: This file is responible for loggng sensor data to the console.
 *
 **********************************************************************/

#ifndef LOGGER_H
#define LOGGER_H

#include "generate_data.h"
#include <pthread>

extern packet data;
extern pthread_mutex_t dataLock;

void *logger(void *args);

#endif // !Logger
