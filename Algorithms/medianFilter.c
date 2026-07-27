#include "medianFilter.h"

void medianFilter(const size_t rows, const size_t cols, unsigned char* image,const size_t windowSize)
{

    if (0 == (windowSize % 2))
    {
        printf("%s","Need odd window length.");
        return;
    }
    if ((NULL != image))
    {
    	unsigned char *filteredImage = malloc(rows * cols * sizeof(unsigned char));
    	if (filteredImage == NULL)
    	{
    	    fprintf(stderr, "Allocation failed\n");
    	    return;
    	}
    	memcpy(filteredImage, image, rows * cols);

    	//assuming square window with odd length
        int guardSize = windowSize/(int)2;
        
        int numPixels2Sort = windowSize * windowSize;
        unsigned char *pixelValues = malloc(numPixels2Sort*sizeof(unsigned char));
        if (pixelValues == NULL)
        {
            free(filteredImage);
            return;
        }

        //apply median filter
        for (int r = 0; r < (int)rows; ++r)
        {
            for (int c = 0; c < (int)cols; ++c)
            {

                int row = (int)r;
                int col = (int)c;
            	if ( ((row - guardSize) >= 0) &&
            			((col - guardSize) >= 0) &&
						((row + guardSize) < (int)rows) &&
						((col + guardSize) < (int)cols) )
				{

					//fill array with pixels in current window
					int numValues = 0;
					for (int idx = (row - guardSize); idx <= (row + guardSize); idx++)
					{
						for (int jdx = (col - guardSize); jdx <= (col + guardSize); jdx++)
						{

							if (numValues < numPixels2Sort)
							{
								pixelValues[numValues] = image[idx*cols + jdx];
								numValues++;

							}
							else
							{
								printf("%s","Accessing invalid array space. ");
								break;
							}
						}
					}
					//sort values and find median
					qsort(pixelValues, numPixels2Sort, sizeof(unsigned char), cmpfunc);

					unsigned char median = pixelValues[numPixels2Sort/2];

					filteredImage[row*cols + c] = median;

				}//end if
            } //c
        } // r

        //copy temp back into original
    	memcpy(image, filteredImage, rows * cols);

    	free(pixelValues);
        free(filteredImage);
    } //end if
} //end of function

int cmpfunc (const void * a, const void * b)
{
    return ( *(unsigned char*)a - *(unsigned char*)b );
}
