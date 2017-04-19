#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "timer.h"

#define NUMBEROFTHREADS 2 
#define NUMBEROFTERMS 4096  
// işletim sistemi threadleri birbirinden ayırsın diye pthread_t kullanılır

long globalSum[ NUMBEROFTHREADS ];
long threadController = 0;
void* threadFunction( void* rank );

int main( void )
{
	long threadRank;
	double startTim, finishTim;
	pthread_t* threadHandles = ( pthread_t* )malloc( NUMBEROFTHREADS * sizeof( pthread_t ) );
	GET_TIME( startTim );
	for( threadRank = 0; threadRank < NUMBEROFTHREADS; threadRank++ )
	{
		pthread_create( &threadHandles[ threadRank ], NULL, threadFunction, ( void* )threadRank );
	}
	for( threadRank = 0; threadRank < NUMBEROFTHREADS; threadRank++ )
	{
		pthread_join( threadHandles[ threadRank ], NULL );
	}
	GET_TIME( finishTim );
	printf( "value of phi: %f\n", 4.0*globalSum );
	printf( "total elapsed time: %f milliseconds\n", finishTim - startTim );
	free( threadHandles );
	return 0;
}

void* threadFunction( void* rank )
{
	double sumInThread = 0.0;
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
		sumInThread = sumInThread + factor / ( 2.0 * index + 1 );
		factor = factor * ( -1.0 );
		globalSum[ index ] = sumInThread;
	}
	return NULL;
}
