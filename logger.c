/***********************************************************************
 * Class:: N/A
 * Name::  Joan Aponte
 * Student ID:: 924074746
 * Github-Name:: JoanA928
 * Project:: Firmware - Data Logger
 * File:: logger.c
 *
 * Description:: This file is responible for loggng sensor data to the console.
 *
 **********************************************************************/

#include "logger.h"
#include "generate_data.h"
#include "info_logger_macro.h"
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

void *logger(void *args) {
  (void)args;
  time_t start = time(NULL);
  while (time(NULL) - start < 10) {
    pthread_mutex_lock(&dataLock);
    printf("sensor value: %d\n", data.value);
    pthread_mutex_unlock(&dataLock);
    usleep(ONE_HUNDRED_MS_US);
  }
  LOG_INFO("Exiting logger thread");
  return NULL;
}
