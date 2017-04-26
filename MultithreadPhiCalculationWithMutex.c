#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "timer.h"

#define NUMBEROFTERMS 4096
#define NUMBEROFTHREADS 8

void* threadFunction( void* rank );
pthread_mutex_t mutex;
double globalSum = 0.0;

//bust waiting threadleri sıralı calıstırır
int main( void )
{
	double startTime, finishTime;
	pthread_mutex_init( &mutex, ( pthread_mutexattr_t* ) NULL );
	pthread_t* threadHandles = ( pthread_t* )malloc( NUMBEROFTHREADS * sizeof( pthread_t ) );
	GET_TIME( startTime );
	for( long threadIndex = 0; threadIndex < NUMBEROFTHREADS; threadIndex++ )
	{
		pthread_create( ( threadHandles + threadIndex ), NULL, threadFunction, ( void* )threadIndex );
	}
	for( long threadIndex = 0; threadIndex < NUMBEROFTHREADS; threadIndex++ )
	{
		pthread_join( *( threadHandles + threadIndex ), NULL );
	}
	GET_TIME( finishTime );
	printf( "phi value: %f \n", 4.0 * globalSum );
	printf( "total elapsed time %f milliseconds\n", finishTime - startTime );
	pthread_mutex_destroy( &mutex );
}

void* threadFunction( void* rank )
{
	long threadRank = ( long ) rank;
	long termsPerThread = NUMBEROFTERMS / NUMBEROFTHREADS;
	long lowerBound = threadRank * termsPerThread;
	long upperBound = lowerBound + termsPerThread;

	double factor;
	double threadSum = 0.0;
	if( lowerBound % 2 == 0 )
	{ 
		factor = 1.0;
	}
	else
	{
		factor = -1.0;
	}
	for( long index = lowerBound; index < upperBound; index++ )
	{
		threadSum = threadSum + factor / ( 2.0 * index + 1.0 );
		factor = factor * ( -1.0 );
	}
	pthread_mutex_lock( &mutex );
	globalSum = globalSum + threadSum;
	printf( "thread %ld was used the mutex..\n", threadRank );
	pthread_mutex_unlock( &mutex );
	return NULL;
}
