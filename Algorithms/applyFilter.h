#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create an alias named 'FilterFunc' for any function taking (const unsigned char*, const int) and returning unsigned char
typedef unsigned char (*FilterFunc)(const unsigned char*, const int);

void applyFilter(const size_t rows, const size_t cols,unsigned char *image,
		const size_t windowSize, FilterFunc operation);
