/**
 * @file
 *
 * Application binary interface (ABI) for RELIC that generates function
 * entry points for items that are only macros. This enables, for instance,
 * Python to interface with RELIC.
 *
 * @ingroup relic
 */

#include "relic.h"
#include "relic_core.h"

typedef unsigned char byte;

#define VALUE_TO_STRING(x) #x
#define VALUE(x) VALUE_TO_STRING(x)
#define PRINTM(var) #var "="  VALUE(var)
#pragma message(PRINTM(BN_SIZE))
#pragma message(PRINTM(EPX_TABLE_LWNAF))
