#pragma once

#include <stdio.h>
#include <time.h>

#ifdef _WIN32
    #define UPDATE_TIME(to, from) localtime_s(&to, &from)
    #define OPEN_FILE(file, path) fopen_s(&file, path.c_str(), "w")
    #define MEMORY_COPY(dst, dst_size, src, src_size) memcpy_s(dst, dst_size, src, src_size)
    #define STACK_ALLOC(size) _malloca(size)
#else
    #define UPDATE_TIME(to, from) localtime_r(&from, &to)
    #define OPEN_FILE(file, path) file = fopen(path.c_str(), "w")
    #define MEMORY_COPY(dst, dst_size, src, src_size) memcpy(dst, src, src_size)
    #define STACK_ALLOC(size) alloca(size)
#endif
