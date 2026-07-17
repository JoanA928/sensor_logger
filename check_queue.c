/***********************************************************************
 * Class:: N/A
 * Name::  Joan Aponte
 * Student ID:: 924074746
 * Github-Name:: JoanA928
 * Project:: Firmware - Data Logger
 * File:: check_queue.c
 *
 * Description:: // TODO: Fill me in.
 *
 **********************************************************************/

#include "check_queue.h"
#include "generate_data.h"
#include "info_logger_macro.h"
#include "verification.h"

void checkQueue() {
  pthread_mutex_lock(&sentinelLock);
  while (sentinelValue != STOP_THREAD) {
    pthread_mutex_unlock(&sentinelLock);
    pthread_mutex_lock(&queueLock);
    if (isNewCommand) {
      for (int index = 0; index < queueSize; index++) {
        switch (queue[index]) {
        case CMD_START:
          LOG_DEBUG("Start command '%d' thread", CMD_START);
          isNewCommand = false;
          break;
        case CMD_STOP:
          LOG_DEBUG("Start command '%d' thread", CMD_STOP);
          isNewCommand = false;
          break;
        case CMD_READ:
          LOG_DEBUG("Start command '%d' thread", CMD_READ);
          isNewCommand = false;
          break;
        case CMD_DUMP:
          LOG_DEBUG("Start command '%d' thread", CMD_DUMP);
          isNewCommand = false;
          break;
        case CMD_STATS:
          LOG_DEBUG("Start command '%d' thread", CMD_STATS);
          isNewCommand = false;
          break;
        case CMD_MEM:
          LOG_DEBUG("Start command '%d' thread", CMD_MEM);
          isNewCommand = false;
          break;
        case CMD_HELP:
          LOG_DEBUG("Start command '%d' thread", CMD_HELP);
          isNewCommand = false;
          break;
        default:
          LOG_ERROR("'queue is non NULL, but queue[%d] is not a command",
                    index);
          break;
        }
      }
    }
    pthread_mutex_unlock(&queueLock);
  }
}
