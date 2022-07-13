#ifndef WALLY_COMMON_H
#define WALLY_COMMON_H

// HELPERS

#define UINT8_COUNT (UINT8_MAX + 1)
#include "sys/types.h"

// -------------- OPTIMIZATIONS -----------------

#define NAN_BOXING                // Makes values to be stored in unit64_t instead of a struct therefore saving memory
// #define NAN_EQUAL_NAN            // If NAN_BOXING is defined, makes NaN (Not a Number, like 0/0) equal to itself at a minor performance cost

// -------------- DEBUG OPTIONS ------------------

// #define DEBUG_TRACE_EXECUTION    // Print executed bytecode and value stack.
// #define DEBUG_PRINT_BYTECODE     // Print bytecode for each function (and the main script) generated by the emitter
// #define DEBUG_PRINT_TOKENS       // Print tokens generated by the scanner and exit

// #define DEBUG_PRINT_PREPROCESSOR // WIP

// #define DEBUG_STRESS_GC          // Trigger the Garbage Collector on each allocation (after bring turned on)
// #define DEBUG_LOG_GC             // Log all actions performed by the Garbage Collector
// #define DEBUG_LOG_ALLOCATION     // Log all memory allocations, reallocations and frees

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#endif