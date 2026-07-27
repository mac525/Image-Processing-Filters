#include <stdio.h>
#include <stdlib.h>

const int ROWS = 640;
const int COLUMNS = 480;


void setInput(unsigned char* image, int r, int c,unsigned char val)
{
	image[r*COLUMNS + c] = val;
}

void genImage(unsigned char* image)
{
    const int imageLength = 2; //pixels white out length x length box

    setInput(image, ROWS/2, COLUMNS/2, (unsigned char)255 );

    /*for(int r=(ROWS/2 - imageLength); r < (ROWS/2 + imageLength); r++)
    {
        for(int c= (COLUMNS/2 - imageLength); c < (COLUMNS/2 + imageLength); c++)
        {

        	setInput(image, r, c, (unsigned char)255 );
            //image[r][c] = (unsigned char)255;
            //printf("%d %d \n", r, c);
            
            
        }
    }
    */

}


int main( int argc, char **argv )
{
    
    int		i;
    FILE		*fp;
    char		*ofile;
    unsigned char	image[ROWS*COLUMNS] = {0}; //initialize all elements to zero;
    
    if ( argc != 2 )
    {
        fprintf( stderr, "usage: %s input output threshold\n", argv[0] );
        exit( 1 );
    }
    
    ofile = argv[1];
    
    //generate image
    genImage(image);
    
    
    if (( fp = fopen( ofile, "wb" )) == NULL )
    {
        fprintf( stderr, "error: could not open %s\n", ofile );
        exit( 1 );
    }
    for ( i = 0 ; i < ROWS ; i++ )
    {
        if ( fwrite( &image[i*COLUMNS], 1, COLUMNS, fp ) != COLUMNS )
        {
            fprintf( stderr, "error: couldn't write enough stuff\n" );
            exit( 1 );
        }
    }
    fclose( fp );
    
    return 0;
}
