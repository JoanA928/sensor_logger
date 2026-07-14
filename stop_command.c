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
#include "info_logger_macro.h"
#include <pthread.h>

void *stopCommand(void *args) {
  LOG_DEBUG("Entering 'stop' command thread");
  pthread_mutex_lock(&sentinelLock);
  sentinelValue = STOP_THREAD;
  LOG_DEBUG("Sentinel value: %d", sentinelValue);
  pthread_mutex_unlock(&sentinelLock);
  LOG_DEBUG("Exiting 'stop' command thread");
  return NULL;
}
