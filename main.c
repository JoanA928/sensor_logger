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
#include "generate_data.h"
#include "verification.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// TODO: Figure out if this lives in .bss or .data.
char buffer[LOG_BUFFER_SIZE];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int sentinelValue;

int main(int argc, char *argv[]) {
  printf("argc: %d / argv: %s ", argc, argv[0]);
  /*
   * The user needs a way to interface with the firmware, in order to control
   * it.
   */
  // TODO: Check 'argv' for parameters passed to the program i.e. --benchmark
  printf("Sensor Data Logger\n"
         "waiting for a command...\n"
         "enter 'help' to see a list of available commands\n");
  /*
   * The user can enter as many commands as they want at once, however, to
   * prevent abuse we have to ignore some input to prevent crashes.
   */
  if (fgets(buffer, LOG_BUFFER_SIZE, stdin) == NULL) {
    printf("Error: something went wrong\n");
    return EXIT_FAILURE;
  }
  if (parseCommands() != 0) {
    printf("Error: failed to parse command");
    return EXIT_FAILURE;
  }

  /**
   * In order to simulate sensors values we're going to generate them in a
   * seperate thread so that firmware has a source for where for logging.
   */
  pthread_t sensorThread;
  pthread_create(&sensorThread, NULL, genereteData, NULL);
  time_t start = time(NULL);

  while (time(NULL) - start < 10) {
    printf("sensor value: %d\n", data.value);
    usleep(ONE_HUNDRED_MS_US);
  }
  sentinelValue = STOP_THREAD;
  printf("good bye\n");
  return EXIT_SUCCESS;
}
