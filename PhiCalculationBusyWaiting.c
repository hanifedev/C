#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUMBEROFTHREADS 2
#define NUMBEROFTERMS 1024

double globalSum = 0.0;
long threadController = 0;

void* threadFunction( void* rank );

int main( void )
{
	pthread_t* threadHandles = (  pthread_t* )malloc( NUMBEROFTHREADS * sizeof( pthread_t ) );
	for( long threadRank = 0; threadRank < NUMBEROFTHREADS; threadRank++ )
	{
		pthread_create( &threadHandles[ threadRank ], NULL, threadFunction, ( void* )threadRank );
	}
	for( long threadRank = 0; threadRank < NUMBEROFTHREADS; threadRank++ )
	{
		pthread_join( threadHandles[ threadRank ], NULL );
	}
	printf("value of phi:%f\n", 4.0*globalSum );
	free( threadHandles );
}

void* threadFunction( void* rank )
{
	long threadRank = ( long ) rank;
	double sumInThread = 0.0;
	long termsPerThread = NUMBEROFTERMS / NUMBEROFTHREADS;
	long lowerBound = threadRank * termsPerThread;
	long upperBound = lowerBound + termsPerThread;
	double factor;
	if( threadRank % 2 == 0 )
		factor = 1.0;
	else
		factor = -1.0;
	for( long index = lowerBound; index < upperBound; index++ )
	{
		sumInThread = sumInThread + factor / ( 2.0 * index + 1 );
		factor = factor * ( -1.0 );
	}
	while( threadController != threadRank );
	globalSum = globalSum + sumInThread;
	threadController = ( threadController + 1 ) % NUMBEROFTHREADS;
	return NULL;
}
