#include "applyFilter.h"


// The function signature becomes much easier to read:
void applyFilter(const size_t rows, const size_t cols,unsigned char *image,
		const size_t windowSize, FilterFunc operation) {

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
    	memcpy(filteredImage, image, rows * cols * sizeof(unsigned char));

    	//assuming square window with odd length
        int guardSize = windowSize/(int)2;

        int numPixels = windowSize * windowSize;
        unsigned char *pixelValues = malloc(numPixels*sizeof(unsigned char));
        if (pixelValues == NULL)
        {
            free(filteredImage);
            return;
        }

        //apply average filter
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

							if (numValues < numPixels)
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

					unsigned char value = operation(pixelValues, numPixels);

					filteredImage[row*cols + c] = value;

				}//end if
            } //c
        } // r

        //copy temp back into original
    	memcpy(image, filteredImage, rows * cols * sizeof(unsigned char));

    	free(pixelValues);
        free(filteredImage);
    } //end if
}
