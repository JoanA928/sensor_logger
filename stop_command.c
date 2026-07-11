/***********************************************************************
 * Class:: N/A
 * Name::  Joan Aponte
 * Student ID:: 924074746
 * Github-Name:: JoanA928
 * Project:: Firmware - Data Logger
 * File:: stop_command.c
 *
 * Description:: This file is responible for processing the stop command.
 *
 **********************************************************************/

#include "generate_data.h"
#include <pthread>

void stopCommand(void *args) {

  pthread_mutex_lock(&commandLock);
  sentinelValue = STOP_THREAD;
  pthread_mutex_unlock(&commandLock);
  return NULL;
}
