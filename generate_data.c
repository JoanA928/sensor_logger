/***********************************************************************
 * Class:: N/A
 * Name::  Joan Aponte
 * Student ID:: 924074746
 * Github-Name:: JoanA928
 * Project:: Firmware - Data Logger
 * File:: generate_data.c
 *
 * Description:: This file defines functions for generating random data for the
 * firmware to read.
 *
 **********************************************************************/

#include "generate_data.h"
#include "info_logger_macro.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

packet data;

void *genereteData(void *arg) {
  /**
   * We need to generate data while our firmware is running to simulate an
   * envoriment where the sensors are constantly collecting data, this way our
   * firmware can access that data whenever it wasnts.
   */
  if (arg) {
    arg = NULL;
  }
  pthread_mutex_lock(&sentinelLock);
  if (sentinelValue != STOP_THREAD) {
    pthread_mutex_unlock(&sentinelLock);
    srand((unsigned int)time(NULL));
    arg = NULL;
    struct timespec delay = {.tv_sec = 0, .tv_nsec = ONE_HUNDRED_MS_NS};

    while (1) {
      pthread_mutex_lock(&sentinelLock);
      if (sentinelValue == STOP_THREAD) {
        pthread_mutex_unlock(&sentinelLock);
        break;
      }
      pthread_mutex_unlock(&sentinelLock);
      pthread_mutex_lock(&dataLock);
      data.value = randomDouble(0.0, 1000.0);
      pthread_mutex_unlock(&dataLock);
      nanosleep(&delay, NULL);
    }
  }
  pthread_mutex_unlock(&sentinelLock);
  LOG_INFO("Stopping thread, sentinelValue: %d", sentinelValue);
  return NULL;
}

double randomDouble(double min, double max) {
  return min + ((double)rand() / RAND_MAX) * (max - min);
}
