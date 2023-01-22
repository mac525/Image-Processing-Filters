#include <stdio.h>
#include <stdlib.h>
#include "Algorithms/MedianFilter/medianFilter.h"

#define ROWS		640
#define COLUMNS		480
#define WINSIZE     3

#define sqr(x)		((x)*(x))

int main( int argc, char **argv )
{
    
    int		i;
    int		threshold;
    FILE		*fp;
    char		*ifile, *ofile;
    unsigned char	image[ROWS][COLUMNS] = {{0}}; //initialize all elements to zero;
    unsigned char	filteredImage[ROWS][COLUMNS] = {{0}}; //initialize all elements to zero
    
    if ( argc != 4 )
    {
        fprintf( stderr, "usage: %s input output threshold\n", argv[0] );
        exit( 1 );
    }
    
    ifile = argv[1];
    ofile = argv[2];
    threshold = atoi(argv[3]);
    
    if (( fp = fopen( ifile, "rb" )) == NULL )
    {
        fprintf( stderr, "error: couldn't open %s\n", ifile );
        exit( 1 );
    }
    
    for ( i = 0; i < ROWS ; i++ )
    {
        if ( fread( image[i], 1, COLUMNS, fp ) != COLUMNS )
        {
            fprintf( stderr, "error: couldn't read enough stuff\n" );
            exit( 1 );
        }
    }
    fclose( fp );
    
    
    medianFilter(image,filteredImage, ROWS, COLUMNS,WINSIZE); //apply median filter to image
    
    
    if (( fp = fopen( ofile, "wb" )) == NULL )
    {
        fprintf( stderr, "error: could not open %s\n", ofile );
        exit( 1 );
    }
    for ( i = 0 ; i < ROWS ; i++ )
    {
        if ( fwrite( filteredImage[i], 1, COLUMNS, fp ) != COLUMNS )
        {
            fprintf( stderr, "error: couldn't write enough stuff\n" );
            exit( 1 );
        }
    }
    fclose( fp );
    
    return 0;
}

