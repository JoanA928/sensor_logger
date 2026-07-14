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
#include <stdint.h>
#include <time.h>

// TODO: 'STOP_THREAD' is used in multiple files, it should be moved to a header
// file that is meant to be shared amongst any file that needs it.
#define STOP_THREAD 1
#define ONE_HUNDRED_MS_NS 100000000L
#define ONE_HUNDRED_MS_US 100000

typedef struct {
  int value;   // Value read from the sensor.
  time_t time; // Time when sensor value was read.
} packet;

extern pthread_mutex_t dataLock;
extern pthread_mutex_t
    sensorLock; // TODO: I'm not sure that this variable is needed.
extern pthread_mutex_t sentinelLock;
extern int sentinelValue; // TODO: 'sentinelValue' is used in multiple files, it
                          // should be moved to a header file that is meant to
                          // be shared amongst any file that needs it.
// extern packet data;

void *genereteData(void *arg);
double randomDouble(double min, double max);

#endif // !GENERATE_DATA_H
