#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUMBEROFTHREADS 8

//Shared mutex and conditional variables
pthread_mutex_t mutex;
pthread_cond_t conditionalVariable;
//Shared mutex and conditional variables 

//Shared variable
int threadCounter = 0;
//Shared variable

void* threadFunction( void* rank );

int main( void )
{
	//Initialize mutex and conditional variable
	pthread_mutex_init( &mutex, ( pthread_mutexattr_t* ) NULL );
	pthread_cond_init( &conditionalVariable, ( pthread_condattr_t* ) NULL );
	//Initialize mutex and conditional variable

	pthread_t* threadHandles = ( pthread_t* )malloc( NUMBEROFTHREADS * sizeof( pthread_t ) );
	for( long threadIndex = 0; threadIndex < NUMBEROFTHREADS; threadIndex++ )
	{
		pthread_create( ( threadHandles + threadIndex ), NULL, threadFunction, ( void* )threadIndex );
	}
	for( long threadIndex = 0; threadIndex < NUMBEROFTHREADS; threadIndex++ )
	{
		pthread_join( *( threadHandles + threadIndex ), NULL );
	}

	pthread_mutex_destroy( &mutex );
	pthread_cond_destroy( &conditionalVariable );
}

void* threadFunction( void* rank )
{
	long threadRank = ( long ) rank;
	//First Barrier 
	pthread_mutex_lock( &mutex );
	threadCounter = threadCounter + 1;
	printf( "thread %ld used the mutex-->threadCounter:%d\n", threadRank, threadCounter );
	if( threadCounter == NUMBEROFTHREADS )
	{
		threadCounter = 0;
		printf( "thread %ld notifies other threads...\n\n", threadRank );
		pthread_cond_broadcast( &conditionalVariable );
	}
	else
	{
		printf(" thread %ld was suspended...\n", threadRank );
		while( pthread_cond_wait( &conditionalVariable, &mutex ) != 0 );
	}
	pthread_mutex_unlock( &mutex );
	printf("thread %ld pass through the first barrier...\n\n",threadRank );
	//first barrier
	return NULL;
}
