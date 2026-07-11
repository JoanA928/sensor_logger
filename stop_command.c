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
#include <pthread>

void stopCommand(void *args) {
  LOG_INFO("Entering 'stop' command thread");
  pthread_mutex_lock(&commandLock);
  sentinelValue = STOP_THREAD;
  DEBUG_INFO("Sentinel value: %d", sentinelValue);
  pthread_mutex_unlock(&commandLock);
  LOG_info("Exiting 'stop' command thread");
  return NULL;
}
