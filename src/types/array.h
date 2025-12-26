#pragma once

// Arrays with their size and max size. Might be used later
typedef struct {
    void* ptr;
    int max_size;
    int size;
} Array;