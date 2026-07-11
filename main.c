/***********************************************************************
 * Class:: N/A
 * Name::  Joan Aponte
 * Student ID:: 924074746
 * Github-Name:: JoanA928
 * Project:: Firmware - Data Logger
 * File:: main.c
 *
 * Description:: Create a firmware program that reads generated sensor data,
 * provides a CLI interface that communicates to the devices’ firmware over TCP
 * giving the user control over some of the firmware’s actions. Such as
 * stopping, starting, & performing data analysis to name a few. Build an
 * interface to allow the user to measure the firmware’s performance.
 *
 **********************************************************************/

// TODO: Find out if getting rid of 'stdbool.h' shrinks the binary size
#include "collect_commands.h"
#include "generate_data.h"
#include "info_logger_macro.h"
#include "verification.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// TODO: Figure out if this lives in .bss or .data.
char buffer[LOG_BUFFER_SIZE];
pthread_mutex_t sensorLock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t commandLock = PTHREAD_MUTEX_INITIALIZER;
int sentinelValue;
int isCommand;
char *queue[];

int main(int argc, char *argv[]) {
  LOG_INFO("argc: %d / argv: %s", argc, argv[0]);
  // TODO: Check 'argv' for parameters passed to the program i.e. --benchmark
  printf("Sensor Data Logger\n"); // TODO: Format program name to have a nice
                                  // presentation
  /**
   * In order to simulate sensors values we're going to generate them in a
   * seperate thread so that firmware has a source for where for logging.
   */
  pthread_t collectCommandsThread;
  pthread_t sensorThread;
  pthread_create(&collect_commands, NULL, collecCommands, NULL);
  pthread_create(&sensorThread, NULL, genereteData, NULL);
  pthread_mutex_lock(&commandLock);
  if (sentinelValue == STOP_THREAD) {
    pthread_mutex_t_lock(&commandLock);
    pthread_join(sensorThread, NULL);
    pthread_join(collectCommandsThread, NULL);
    LOG_INFO("good bye");
    return EXIT_SUCCESS;
    pthread_mutex_t_lock(&collect_commands);
  } else if (!queue) {
    LOG_INFO("Here I would start run commands");
    pthread_mutex_t_unlock(&collect_commands);
    pthread_t collectCommandsThread;
    pthread_create(&collect_commands, NULL, collecCommands, NULL);
    pthread_create(&sensorThread, NULL, genereteData, NULL);
    if (sentinelValue == STOP_THREAD) {
      pthread_join(sensorThread, NULL);
      LOG_INFO("good bye");
      return EXIT_SUCCESS;
    }
  }
