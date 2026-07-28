#include "medianFilter.h"

unsigned char medianFilter(const unsigned char* pixelValues, const int numPixels2Sort)
{

	//sort values and find median
	qsort(pixelValues, numPixels2Sort, sizeof(unsigned char), cmpfunc);

	unsigned char median = pixelValues[numPixels2Sort/2];

	return median;

} //end of function

int cmpfunc (const void * a, const void * b)
{
    return ( *(unsigned char*)a - *(unsigned char*)b );
}
