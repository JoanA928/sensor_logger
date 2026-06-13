/***********************************************************************
 * Class:: N/A
 * Name::  Joan Aponte
 * Student ID:: 924074746
 * Github-Name:: JoanA928
 * Project:: Firmware - Data Logger
 * File:: generate_data.h
 *
 * Description:: This file declares functions for generating random data for the
 * firmware to read.
 *
 **********************************************************************/

#ifndef GENERATE_DATA_H
#define GENERATE_DATA_H

#include <pthread.h>

extern pthread_mutex_t lock;

void *genereteData();

#endif // !GENERATE_DATA_H
