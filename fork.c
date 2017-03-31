#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main( void )
{
	pid_t cocuk_pid;
	cocuk_pid = fork();
	if( cocuk_pid > 0 )
	{
		printf( "Burası ana surectir, surec id = %d \n", (int)getpid() );
		printf( "Çocuk sürecin idsi pid = %d \n", (int)cocuk_pid );
	}
	else if( cocuk_pid == 0 )
	{
		printf( "burası çocuk süreçtir, pid = %d", (int)getpid() );
	}
}
