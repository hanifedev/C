#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main( void ) 
{
	pid_t pid;
	pid = fork();
	if( pid < 0 ) 
	{
		fprintf( stderr, "Hata oluştu" );
		return -1;
	}
	else if( pid == 0 )
	{
		execlp( "/bin/ls", "ls", NULL );	
	}
	else
	{
		wait( NULL );
		printf( "Çocuk process tamamlandı \n" );
	}
}
