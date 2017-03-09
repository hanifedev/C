#include <stdio.h>
#define SIZE 10

void bubbleSort( int dizi[], int n )
{
	int i;
	int j;
	int gecici;
	for ( i=1; i < SIZE; i++ )
	{
		for ( j=0; j < SIZE-i; j++ )
		{
			if ( dizi[j] > dizi[j+1] )
			{
				gecici = dizi[j];
				dizi[j] = dizi[j+1];
				dizi[j+1] = gecici;
			}
		}
	}
}


int main( void )
{
	int i;
	int dizi[ SIZE ];
	printf("dizinin elemanlarini giriniz\n");
	for ( i = 0; i < SIZE; i++ )
	{
		scanf("%d", &dizi[i]);
	}
	bubbleSort(dizi,SIZE);
	printf("sıralı dizi\n");
	for ( i = 0; i< SIZE; i++ )
	{
		printf("%d \t", dizi[i]);
	}
}
