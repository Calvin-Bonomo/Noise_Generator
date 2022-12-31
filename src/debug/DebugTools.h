#include "DebugConsole.h"

#ifdef DEBUG
#define DLOG(message) DebugConsole::Debug()->Log(message)
#else
#define DLOG(message) {} while(false)
#endif

#ifdef DEBUG
#define KILLCONSOLE DebugConsole::Debug()->Kill()
#else
#define KILLCONSOLE {} while(false)
#endif