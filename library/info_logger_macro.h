/***********************************************************************
 * Class:: N/A
 * Name::  Joan Aponte
 * Student ID:: 924074746
 * Github-Name:: JoanA928
 * Project:: Firmware - Data Logger
 * File:: info_logger_macrco.h
 *
 * Description:: This file makes it easy to write consistent, and informative
 * debug, error, info messages to the approrpiate file stream.
 *
 **********************************************************************/

#ifndef INFO_LOGGER_MACRO_H
#define INFO_LOGGER_MACRO_H

#include <stdio.h>

#define LOG_DEBUG(fmt, ...)                                                    \
  fprintf(stderr, "[DEBUG] %s:%d: " fmt "\n", __FILE__,                        \
          __LINE__ __VA_OPT__(, ) __VA_ARGS__) // fmt -> first macro parameter
#define LOG_INFO(fmt, ...)                                                     \
  fprintf(stderr, "[INFO] " fmt "\n" __VA_OPT__(, ) __VA_ARGS__)

#define LOG_ERROR(fmt, ...)                                                    \
  fprintf(stderr, "[ERROR] %s:%d: " fmt "\n", __FILE__,                        \
          __LINE__ __VA_OPT__(, ) __VA_ARGS__)

#endif // !INFO_LOGGER_MACRO_H
