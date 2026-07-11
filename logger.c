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

void logger(void *args) {

  time_t start = time(NULL);
  while (time(NULL) - start < 10) {
    printf("sensor value: %d\n", data.value);
    usleep(ONE_HUNDRED_MS_US);
  }

  return NULL;
}
