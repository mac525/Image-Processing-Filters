#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>

void writeOutputImage(const char *file, unsigned char* data, const size_t rows,const size_t cols)
{

       FILE		*fp;

	   if (( fp = fopen( file, "wb" )) == NULL )
	    {
	        fprintf( stderr, "error: could not open %s\n", file );
	        exit( 1 );
	    }

	    for ( size_t i = 0 ; i < rows ; i++ )
	    {
	        if ( fwrite( &data[i*cols], 1, cols, fp ) != cols )
	        {
	            fprintf( stderr, "error: couldn't write enough stuff\n" );
	            exit( 1 );
	        }
	    }

	    if (fclose(fp) != 0)
	    {
	        fprintf(stderr, "error: could not close %s\n", file);
	        exit(1);
	    }

}



#endif
