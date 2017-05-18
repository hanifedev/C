#include <stdio.h>

int main( void )
{
	unsigned int account;
	char name[ 30 ];
	double balance;
	FILE *cfPtr;

	if( ( cfPtr = fopen( "clients.dat", "w" ) ) == NULL ) 
	{
		puts( "dosya açılamadı" );
	}
	else
	{
		puts( "hesap, ad ve bakiye girin" );
		puts( "giriş işlemini sonlandırmak için EOF girin" );
		printf( "%s", "?" );
		scanf( "%d%29s%1f", &account, name, &balance );
		while( !feof( stdin ) )
		{
			fprintf( cfPtr, "%d %s %.2f\n", account, name, balance );
			printf( "%s", "?" );
			scanf( "%d%29s%1f", &account, name, &balance );
		}
		fclose( cfPtr );
	}
}
