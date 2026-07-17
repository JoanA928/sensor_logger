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
#include "check_queue.h"
#include "generate_data.h"
#include "info_logger_macro.h"
#include "verification.h"
#include <pthread.h>
#include <stdbool.h>

void *collectCommands(void *args) {
  /*
   * The user needs a way to interface with the firmware, in order to control
   * it.
   */
  (void)args;
  LOG_DEBUG("collect commands thread started");
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
    parseCommands();
    pthread_mutex_lock(&queueLock);
    if (!isNewCommand) {
      LOG_ERROR("Detected an invalid commad");
    }
    pthread_mutex_unlock(&queueLock);
  }
  return NULL;
}
