#include "medianFilter.h"

//unsigned char* medianFilter(unsigned char* image, int rows, int columns,int windowSize)
void medianFilter(unsigned char* image,unsigned char* filteredImage, int rows, int columns,int windowSize)

{
    if (0 == (windowSize % 2))
    {
        printf("%s","Need odd window length.");
        return;
    }
    if ((NULL != image) & (NULL != filteredImage))
    {
        //assuming square window with odd length
        int guardSize = windowSize/(int)2;
        const int numPixels2Sort = windowSize*windowSize;
        
        //make temporary copy
        //unsigned char filteredImage[rows][cols];
    
        
        memcpy(filteredImage, image, sizeof(unsigned char));
        
        //copy original image data
        //for (int r = 0; r < rows; ++r)
        //{
         //   for (int c = 0; c < cols; ++c)
           // {
             //   filteredImage[r][c] = image[r][c];
            //}
        //}
    
        //apply median filter
        unsigned char pixelValues[numPixels2Sort];
    
        for (int r = guardSize; r < (rows - guardSize); ++r)
        {
            for (int c = guardSize; c < (columns - guardSize); ++c)
            {
                //fill array with pixels in current window
                int numValues = 0;
                for (int idx = r - guardSize; idx <= r + guardSize; idx++)
                {
                    for (int jdx = c - guardSize; idx <= c + guardSize; jdx++)
                    {
                        if (numValues >= numPixels2Sort)
                        {
                            printf("%s","Accessing invalid array space. ");
                            break;
                        }
                        pixelValues[numValues] = image[idx][jdx];
                        numValues++;
                    }
                }
                //sort values and find median
                qsort(pixelValues, numPixels2Sort, sizeof(unsigned char), cmpfunc);
            
                unsigned char median = pixelValues[numPixels2Sort/2];
                filteredImage[r][c] = median;
            
            }
        }
        
      //  image = filteredImage;
    }
    
    //return image;
}

int cmpfunc (const void * a, const void * b)
{
    return ( *(unsigned char*)a - *(unsigned char*)b );
}