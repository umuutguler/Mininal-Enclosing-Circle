#include <stdio.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


int main() {
	
	al_init_primitives_addon();

	ALLEGRO_DISPLAY *display = NULL;

	int n;
	printf("Lutfen koordinat sayisini giriniz:");
	scanf_s("%d", &n);

	int koordinatlar[500][2];
	int i, j;

	for (i = 0; i < n; i++)
	{
		printf("\n");
		printf("%d. Noktanin X Degerini Giriniz : ", i + 1);
		scanf_s("%d", &koordinatlar[i][0]);

		printf("%d. Noktanin Y Degerini Giriniz : ", i + 1);
        scanf_s("%d", &koordinatlar[i][1]);

		printf("     {%d,%d}\n", koordinatlar[i][0], koordinatlar[i][1]);

	}

    float x_1, y_1;
	float x_2, y_2;
	float h = 0, h2 = 0, kok;
	float x0, y0;
	float x1, y1, x2, y2;
	float x3, y3;


	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			x_1 = koordinatlar[i][0];
			y_1 = koordinatlar[i][1];
			x_2 = koordinatlar[j][0];
			y_2 = koordinatlar[j][1];

			kok = ((x_2 - x_1) * (x_2 - x_1)) + ((y_2 - y_1) * (y_2 - y_1));
			kok = sqrt(kok);
            
			if (kok > h)
			{
				h = kok;
				x1 = x_1;
				y1 = y_1;
				x2 = x_2;
				y2 = y_2;
			}
        }
    }
	
	
	x0 = (x1 + x2) / 2;
	y0 = (y1 + y2) / 2;

	for (i = 0; i < n; i++)
	{
		x_1 = koordinatlar[i][0];
		y_1 = koordinatlar[i][1];

		kok = ((x0 - x_1) * (x0 - x_1)) + ((y0 - y_1) * (y0 - y_1));
		kok = sqrt(kok);

		if (kok > h2)
		{
			h2 = kok;
			x3 = x_1;
			y3 = y_1;
		}
	}
	
	float r, xmer, ymer;
	float a, b, c;

    if (h2 <= h / 2)
	{
		xmer = x0;
		ymer = y0;
		r = h / 2;
    }
	else
	{
		a = ((x2 * x2) - (x1 * x1) + (y2 * y2) - (y1 * y1)) * (y3 - y2);
		b = ((x2 * x2) - (x3 * x3) + (y2 * y2) - (y3 * y3)) * (y1 - y2);
		c = (2 * (x1 - x2) * (y3 - y2)) - (2 * (x3 - x2) * (y1 - y2));

		xmer = ((a - b) / c) * (-1);

		a = ((y2 * y2) - (y1 * y1) + (x2 * x2) - (x1 * x1)) * (x3 - x2);
		b = ((y2 * y2) - (y3 * y3) + (x2 * x2) - (x3 * x3)) * (x1 - x2);
		c = (2 * (y1 - y2) * (x3 - x2)) - (2 * (y3 - y2) * (x1 - x2));

		ymer = ((a - b) / c) * (-1);


		r = ((xmer - x1) * (xmer - x1)) + ((ymer - y1) * (ymer - y1));
		r = sqrt(r);

    }
	
	printf("\n");
	printf("Cemberin Merkezi : {%f,%f}\n", xmer, ymer);
	printf("Cemberin Yaricapi : %f\n", r);
	printf("\n");

	 al_init();
     display = al_create_display(900, 900);  
     al_draw_line(450, 25, 450, 875, al_map_rgb(255, 255, 255), 1);
	 al_draw_line(25, 450, 875, 450, al_map_rgb(255, 255, 255), 1);
	 
	 for (i = 1; i < 42; i++)
	 {
     al_draw_line((i * 20) + 30, 445, (i * 20) + 30, 455, al_map_rgb(255, 255, 255), 1);
	 al_draw_line(445, (i * 20) + 30, 455, (i * 20) + 30, al_map_rgb(255, 255, 255), 1);
	 }

	 for (i = 0; i < n; i++)
	 {
		 al_draw_filled_circle((koordinatlar[i][0]*20) + 450, 450 - (koordinatlar[i][1]*20), 2, al_map_rgb(255, 0, 0));
		 al_draw_line((koordinatlar[i][0] * 20) + 450, 450 - (koordinatlar[i][1] * 20), (koordinatlar[i][0] * 20) + 450, 450, al_map_rgb(255, 0, 0), 1 );
		 al_draw_line((koordinatlar[i][0] * 20) + 450, 450 - (koordinatlar[i][1] * 20), 450, 450 - (koordinatlar[i][1] * 20), al_map_rgb(255, 0, 0), 1);
     }
	 
	 al_draw_circle((xmer*20)+450, 450-(ymer*20), r*20, al_map_rgb(0, 0, 255), 2);
	 al_draw_filled_circle((xmer * 20) + 450, 450 - (ymer * 20), 2, al_map_rgb(255, 0, 0));
	 al_flip_display();

    system("pause"); 
	return 0;
}