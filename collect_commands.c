/***********************************************************************
 * Class:: N/A
 * Name::  Joan Aponte
 * Student ID:: 924074746
 * Github-Name:: JoanA928
 * Project:: Firmware - Data Logger
 * File:: collect_commands.c
 *
 * Description:: This file is meant to serve as a seperate thread for allowing
 * the user to input commands while another command is executing.
 *
 **********************************************************************/

#include "collect_commands.h"
#include "genearte_data.h"
#include "info_logger_macro.h"
#include "verification.h"
#include <pthread.h>
#include <stdbool.h>

void *collectCommands(void *args) {
  /*
   * The user needs a way to interface with the firmware, in order to control
   * it.
   */
  LOG_INFO("hello I'm supposed to collect commands");
  printf("Enter 'help' to see a list of available commands\n");
  while (true) {
    pthread_mutex_lock(&sentinelLock);
    if (sentinelValue == STOP_THREAD) {
      pthread_mutex_unlock(&sentinelLock);
      break;
    }
    pthread_mutex_unlock(&sentinelLock);
    /*
     * The user can enter as many commands as they want at once, however, to
     * prevent abuse we have to ignore some input to prevent crashes.
     */
    if (fgets(buffer, LOG_BUFFER_SIZE, stdin) == NULL) {
      LOG_ERROR("something went wrong processing commands");
    }
    if (parseCommands() == 0) {
      pthread_mutex_lock(&commandLock);
      isCommand = true;

      pthread_mutex_unlock(&commandLock);
    }
  }
  return NULL;
}
