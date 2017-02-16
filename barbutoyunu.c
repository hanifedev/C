//barbut oyunu
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Durumlar {DEVAM,KAYBETTINIZ,KAZANDINIZ};

int zarAt( void )
{
	int zar1;
	int zar2;
	int zarSum;
	zar1=1+(rand()%6);
	zar2=1+(rand()%6);
	zarSum=zar1+zar2;
	printf("Sonuc %d + %d = %d \n", zar1, zar2, zarSum);
	return zarSum;
}

int main( void )
{
	int toplam;
	int puan;
	enum Durumlar oyunDurumu;
	srand(time(NULL));
	toplam=zarAt();
	switch(toplam)
	{
	   case 7: 
	   case 11:
		oyunDurumu=KAZANDINIZ;
		break;
	   case 2:
	   case 3:
	   case 12: 
		oyunDurumu=KAYBETTINIZ;
		break;
	   default:
		oyunDurumu=DEVAM;
	        puan=toplam;
		printf("PUAN = %d \n", puan);
		break;
	}
	while ( DEVAM == oyunDurumu )
	{
  	   	toplam=zarAt();
	   	if ( toplam == puan )
	   	{
	       		oyunDurumu=KAZANDINIZ;
	   	}
	   	else
	   	{
			if ( toplam == 7 ) 
			{
		   		oyunDurumu=KAYBETTINIZ; 
			}
	   	}
	}
	if ( oyunDurumu == KAZANDINIZ )
	{
		printf("Kazandınız\n");
	}
	else
	{
		printf("Kaybettiniz\n");
	}
}
