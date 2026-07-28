#include "averageFilter.h"

unsigned char averageFilter(const unsigned char* pixelValues, const int numPixels)
{
	//compute average value over pixels
	unsigned int averageSum = 0;
	unsigned char average = 0;
	for(int element = 0; element < numPixels; element++)
	{
		averageSum += pixelValues[element];
	}
	average = averageSum / numPixels;

	return average;

} //end of function
