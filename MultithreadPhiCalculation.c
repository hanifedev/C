#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUMBEROFTHREADS 2 
#define NUMBEROFTERMS 8192  
// işletim sistemi threadleri birbirinden ayırsın diye pthread_t kullanılır
double globalSum = 0.0;
void* threadFunction( void* rank );

int main( void )
{
	long threadRank;
	pthread_t* threadHandles = ( pthread_t* )malloc( NUMBEROFTHREADS * sizeof( pthread_t ) );
	for( threadRank = 0; threadRank < NUMBEROFTHREADS; threadRank++ )
	{
		pthread_create( &threadHandles[ threadRank ], NULL, threadFunction, ( void* )threadRank );
	}
	for( threadRank = 0; threadRank < NUMBEROFTHREADS; threadRank++ )
	{
		pthread_join( threadHandles[ threadRank ], NULL );
	}
	printf( "value of phi: %f\n", 4.0*globalSum );
	free( threadHandles );
	return 0;
}

void* threadFunction( void* rank )
{
	long threadRank = ( long ) rank;
	long termPerThread = NUMBEROFTERMS / NUMBEROFTHREADS;
	long loverBound = threadRank * termPerThread;
	long upperBound = loverBound + termPerThread;
	double factor;
	if ( threadRank % 2 == 0 )
	{
		factor = 1.0;
	}
	else
	{
		factor = -1.0;
	}

	for ( long index = loverBound; index < upperBound; index++ )
	{
		globalSum = globalSum + factor / ( 2.0 * index + 1 );
		factor = factor * ( -1.0 );
	}
	return NULL;
}
