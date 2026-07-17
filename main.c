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
#include "app_state.h"
#include "check_queue.h"
#include "collect_commands.h"
#include "generate_data.h"
#include "info_logger_macro.h"
#include "verification.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

// TODO: Figure out if this lives in .bss or .data.
char buffer[LOG_BUFFER_SIZE]; // TODO: Consolidate all global variables into the
                              // buffer
pthread_mutex_t sensorLock = PTHREAD_MUTEX_INITIALIZER; // TODO: can be moved?
pthread_mutex_t sentinelLock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t queueLock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dataLock = PTHREAD_MUTEX_INITIALIZER;

// TODO: I'm unsure if commandLock is neccessary or not
// pthread_mutex_t commandLock = PTHREAD_MUTEX_INITIALIZER;
int sentinelValue;
bool isNewCommand;
int queue[MAX_QUEUE_SIZE]; // TODO: Figure out if this lives in .bss or .data
int queueSize;             // TODO: Figure out if this lives in .bss or .data

int main(int argc, char *argv[]) {
  LOG_DEBUG("argc: %d / argv: %s", argc, argv[0]);
  // TODO: Check 'argv' for parameters passed to the program i.e. --benchmark
  printf("Sensor Data Logger\n"); // TODO: Format program name to have a nice
                                  // presentation
  /**
   * The program needs a way to halt execution when told to but when it's not
   * told to halt it's to provide an enviroment in which the user can enter
   * commands and the program can execute those commands.
   */
  pthread_t collectCommandsThread;
  pthread_create(&collectCommandsThread, NULL, collectCommands, NULL);

  checkQueue();
  pthread_join(collectCommandsThread, NULL);
  return 0;

  /*  pthread_t sensorThread; // TODO: Sensor thread shouldn't start till valid
                            // command is found
    pthread_create(
        &sensorThread, NULL, genereteData,
        NULL); // TODO: Sensor thread shouldn't start till valid command is
    found pthread_mutex_lock(&sentinelLock); if (sentinelValue == STOP_THREAD) {
      pthread_mutex_t_unlock(&sentinelLock);
      pthread_join(sensorThread, NULL); // TODO: I should have an array to keep
                                        // track of which threads I need to join
      pthread_join(collectCommandsThread, NULL);
      LOG_INFO("good bye");
      return EXIT_SUCCESS;
      //    pthread_mutex_t_lock(&collectCommands);
    } else if (!queue) {
      pthread_mutex_t_unlock(&sentinelLock);
      LOG_INFO("Here I would start run commands");
      //   pthread_mutex_t_unlock(&collectCommands);
      pthread_t collectCommandsThread;
      pthread_create(&collectCommands, NULL, collecCommands, NULL);
      pthread_create(&sensorThread, NULL, genereteData, NULL);
      if (sentinelValue == STOP_THREAD) {
        pthread_join(sensorThread, NULL);
        LOG_INFO("good bye");
        return EXIT_SUCCESS;
      }
    }
  */
}
