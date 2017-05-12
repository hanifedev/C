#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "timer.h"

#define NUMBEROFTHREADS 8

int threadCounter = 0;
sem_t* barrierSemaphore;
sem_t* counterSemaphore;
double elapsedTimes[ NUMBEROFTHREADS ];
void* threadFunction( void* rank );

int main( void )
{
	barrierSemaphore = ( sem_t* )malloc( sizeof( sem_t ) );
	counterSemaphore = ( sem_t* )malloc( sizeof( sem_t ) );
	sem_init( barrierSemaphore, 0, 0 );
	sem_init( counterSemaphore, 0, 1 );
	pthread_t* threadHandles = ( pthread_t* )malloc( NUMBEROFTHREADS * sizeof( pthread_t ) );
	for( long threadRank = 0; threadRank < NUMBEROFTHREADS; threadRank++ )
	{
		pthread_create( ( threadHandles + threadRank ), NULL, threadFunction, ( void* )threadRank ); 
	}
	for( long threadRank = 0; threadRank < NUMBEROFTHREADS; threadRank++ )
	{
		pthread_join( *( threadHandles + threadRank ), NULL );
	}
	for( long threadRank = 0; threadRank < NUMBEROFTHREADS; threadRank++ )
	{
		printf( "threadRank: %ld Time %f \n", threadRank, elapsedTimes[ threadRank ] );
	}
	sem_destroy( barrierSemaphore );
	sem_destroy( counterSemaphore );
}

void* threadFunction( void* rank )
{
	long threadRank = ( long ) rank;
	double startTimeOfThread, finishTimeOfThread;
	GET_TIME( startTimeOfThread );
	sem_wait( counterSemaphore );
	if( threadCounter == NUMBEROFTHREADS -1 )
	{
		threadCounter = 0;
		printf( "In If -> ThreadRank: %ld Counter: %d \n", threadRank, threadCounter );
		sem_post( counterSemaphore );
		for( long index = 0; index < ( NUMBEROFTHREADS -1 ); index++ )
		{
			sem_post( barrierSemaphore );
		}
	}
	else
	{
		threadCounter = threadCounter + 1;
		printf( "In Else -> ThreadRank: %ld Counter %d \n", threadRank, threadCounter );
		sem_post( counterSemaphore );
		sem_wait( barrierSemaphore );
	}
	GET_TIME( finishTimeOfThread );
	elapsedTimes[ threadRank ] = finishTimeOfThread - startTimeOfThread;
	printf( "threadRank: %ld was passed the barrier \n", threadRank );
	return NULL;
}
