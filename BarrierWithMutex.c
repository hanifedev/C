#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "timer.h"

#define NUMBEROFTHREADS 16

double elapsedTimesInThreads[ NUMBEROFTHREADS ];
int threadCounter = 0;
pthread_mutex_t mutex;

void* threadFunction( void* rank );

int main( void )
{
	pthread_mutex_init( &mutex, NULL );
	pthread_t* threadHandles = ( pthread_t* )malloc( NUMBEROFTHREADS * sizeof( pthread_t ) );
	for( long threadIndex = 0; threadIndex < NUMBEROFTHREADS; threadIndex++ )
	{
		pthread_create( ( threadHandles + threadIndex ), NULL, threadFunction, ( void* )threadIndex );
	}
	for( long threadIndex = 0; threadIndex < NUMBEROFTHREADS; threadIndex++ )
	{
		pthread_join( *( threadHandles + threadIndex ), NULL );
	}
	for( long threadIndex = 0; threadIndex < NUMBEROFTHREADS; threadIndex++ )
	{
		printf( "thread %ld: %f \n", threadIndex, elapsedTimesInThreads[ threadIndex ] );
	}
}

void* threadFunction( void* rank )
{
	long threadRank = ( long ) rank;
	double startTimeOfThread, finishTimeOfThread;
	GET_TIME( startTimeOfThread );
	pthread_mutex_lock( &mutex );
	threadCounter = threadCounter + 1;
	printf( "thread Rank : %ld \t Counter: %d \n", threadRank, threadCounter );
	pthread_mutex_unlock( &mutex );
	while( threadCounter < NUMBEROFTHREADS );
	GET_TIME( finishTimeOfThread );
	elapsedTimesInThreads[ threadRank ] = finishTimeOfThread - startTimeOfThread;
	return NULL;
}
