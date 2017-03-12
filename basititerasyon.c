//fonksiyon (e^-x)-x
#include <stdio.h>
#include <math.h>

void basititerasyonyontemi( float x, int iterasyon )
{
	int i;
	float fx;
	float sonuc;
	float xeski;
	float xyeni;
	float ea;
	for ( i = 0; i < iterasyon; i++ )
	{
		fx = pow(2.72, (-1) * x);
		xeski = x;
		if ( i != 0 )
		{
			ea = ( ( fx - xeski ) / fx );	
			if ( ea < 0 )
			{
				ea *= -1;
			}
			sonuc = ea * 100;
		}
		x = fx;
		printf("%d \t  %10f \t %f \n", i+1, fx, sonuc);
	}	
}

int main( void )
{
	float sayi;
	int iterasyon;
	printf("x sayısı giriniz");
	scanf("%f", &sayi);
	printf("iterasyon sayısını giriniz");
	scanf("%d", &iterasyon);
	printf("iterasyon \t xi \t ea\n");
	basititerasyonyontemi( sayi, iterasyon );
}


