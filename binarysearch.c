#include <stdio.h>
#define SIZE 15

size_t binarySearch( const int dizi[], int anahtar, size_t alts, size_t usts );
void printHeader( void );
void printRow( const int dizi[], size_t alts, size_t orta, size_t usts );

int main( void )
{
	int a[ SIZE ];
	size_t i;
	int anahtar;
	size_t sonuc;

	for ( i = 0; i < SIZE; i++ )
	{
		a[ i ] = 2 * i;
	}
	
	printf( "%s", "0-28 arası rakam giriniz" );
	scanf( "%d", &anahtar );
	printHeader();
	sonuc = binarySearch( a, anahtar, 0, SIZE-1 );

	if ( sonuc != -1 )
	{
		printf( "%d değeri %d. indiste bulunmustur \n", anahtar, sonuc );
	}
	else
	{
		printf( "%d bulunamadı\n", anahtar );
	}
}

size_t binarySearch( const int dizi[], int anahtar, size_t alts, size_t usts )
{
	int orta;
	while ( alts <= usts )
	{
		orta = ( alts + usts ) / 2;
		printRow( dizi, alts, orta, usts );
		if ( anahtar == dizi[ orta ] )
		{
			return orta;
		}
		else if ( anahtar <= dizi[ orta ] )
		{
			usts = orta - 1;
		}
		else
		{
			alts = orta + 1;
		}
	}
	return -1;
}

void printHeader( void )
{
	unsigned int i;
	puts( "indisler: " );
	for ( i = 0; i < SIZE; i++ )
	{
		printf( "%3u", i );
	}
	puts( "" );
	for ( i = 1; i <= 4; i++ )
	{
		printf( "%s", "-" );
	}
	puts( "" );
}

void printRow( const int dizi[], size_t alts, size_t orta, size_t usts )
{
	size_t i;
	for ( i = 0; i < SIZE; i++ )
	{
		if( i < alts || i > usts )
		{
			printf( "%s", "" );
		}
		else if( i == orta )
		{
			printf( "%3d", dizi[ i ] );
		}
		else
		{
			printf( "%3d", dizi[ i ] );
		}
	}
	puts( "" );
}	
