#include <stdio.h>
#include <stdlib.h>

#include "Common/ImageConstants.h"
#include "Common/noiseGen.h"
#include "Common/utils.h"

#include "Algorithms/Filters/medianFilter.h"
#include "Algorithms/Filters/averageFilter.h"
#include "Algorithms/applyFilter.h"

const int WINSIZE = 9;
const int NOISETHRESH = 50;
enum FilterAlgorithm
{
	AVERAGE,
	MEDIAN
};

int main( int argc, char **argv )
{
	enum FilterAlgorithm algorithmType = MEDIAN;

    int		i;
    FILE		*fp;
    char		*ifile, *ofile, *noisefile;
    unsigned char	image[ROWS*COLUMNS] = {0}; //initialize all elements to zero;
    
    if ( argc != 4 )
    {
        fprintf( stderr, "usage: %s inputFile outputFile noiseFile\n", argv[0] );
        exit( 1 );
    }
    
    ifile = argv[1];
    ofile = argv[2];
    noisefile = argv[3];
    
    if (( fp = fopen( ifile, "rb" )) == NULL )
    {
        fprintf( stderr, "error: couldn't open %s\n", ifile );
        exit( 1 );
    }
    
    for ( i = 0; i < ROWS ; i++ )
    {
        if ( fread( &image[i*COLUMNS], 1, COLUMNS, fp ) != COLUMNS )
        {
            fprintf( stderr, "error: couldn't read enough stuff\n" );
            exit( 1 );
        }
    }
    fclose( fp );
    
    //APPLY NOISE
    saltAndPepper(ROWS,COLUMNS,image,NOISETHRESH); //apply salt and pepper noise to image

    //write noisey image
    writeOutputImage(noisefile, image,ROWS,COLUMNS);


    if (algorithmType == AVERAGE)
    {
        //APPLY AVERAGE FILTER
    	applyFilter(ROWS,COLUMNS,image,WINSIZE, averageFilter); //apply average filter to image
    }
    else if (algorithmType == MEDIAN)
	{
        //APPLY MEDIAN FILTER
    	applyFilter(ROWS,COLUMNS,image,WINSIZE, medianFilter); //apply median filter to image
	}
    else
    {
    	fprintf( stderr, "error: filter algorithm not implemented\n" );
    	exit( 1 );
    }
    //write output image
    writeOutputImage(ofile, image,ROWS,COLUMNS);
    
    return 0;
}

