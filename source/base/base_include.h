#ifndef BASE_INCLUDE_H
#define BASE_INCLUDE_H

#include <dirent.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <fcntl.h>
//- needed for random
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

#include <arm_neon.h>

#include <stdio.h>

#include "base_core.h"
#include "base_arena.h"
#include "base_stack.h"
#include "base_string.h"
#include "base_math.h"
#include "base_os.h"
#include "base_error.h"
#include "base_rand.h"

#endif
