#include "noiseGen.h"

void saltAndPepper(const int rows, const int cols, unsigned char* image,const int N)

{
	srand(time(NULL));

    if ((NULL != image))
    {

    	//make matrix with random integers between 0 and N
    	int noiseMatrix[rows*cols];
    	memset( noiseMatrix, 0, rows*cols*sizeof(int) );

    	for(int r = 0; r < rows; r++)
    	{
        	for(int c = 0; c < cols; c++)
        	{
        		noiseMatrix[r*cols + c] = (rand() % (N + 1));

        	}
    	}

    	//if noise Matrix is 0 then set image cell to 0
    	//if noise Matrix is N then set image cell to 255

    	for(int r = 0; r < rows; r++)
    	{
    	   for(int c = 0; c < cols; c++)
    	   {

    	       if (0 == noiseMatrix[r*cols + c])
    	       {
    	    	   image[r*cols + c] = (unsigned char)0;
    	       }
    	       else if(N == noiseMatrix[r*cols + c])
    	       {
    	    	   image[r*cols + c] = (unsigned char)255;
    	       }
    	   }
    	}
    }
}
