#include "stdio.h"
#include "stdlib.h"
#include "math.h"

double frand()
{
	return 2 * ((rand() / (double)RAND_MAX) - 0.5);//隨機噪聲
}

void main()
{
	float x_last = 0;
	float p_last = 0.02;
	float Q = 0.018;
	float R = 0.542;
	float kg;
	float x_mid;
	float x_now;
	float p_mid;
	float p_now;
	float z_real = 0.56;
	float z_measure;
	float summerror_kalman = 0;
	float summerror_measure = 0;
	int i;
	x_last = z_real + frand()*0.03;
	x_mid = x_last;
	for (i = 0; i < 20;i++)
	{
		x_mid = x_last;
		p_mid = p_last + Q;
		kg = p_mid / (p_mid + R);
		z_measure = z_real + frand()*0.03;//測量值
		x_now = x_mid + kg*(z_measure - x_mid);//估計出的最有值
		p_now = (1 - kg)*p_mid;//最優值對應的均方差

		printf("Real position:%6.3f\n", z_real);
		printf("Measure position:%6.3f [diff:%.3f]\n", z_measure, fabs(z_real - z_measure));
		printf("Kalman position: %6.3f [diff:%.3f]\n", x_now, fabs(z_real - x_now));
		printf("\n\n");
		summerror_kalman += fabs(z_real - x_now);
		summerror_measure += fabs(z_real - z_measure);
		p_last = p_now;
		x_last = x_now;
	}
	printf("總體測量誤差      :%f\n", summerror_measure);
	printf("總體卡爾曼濾波誤差:%f\n", summerror_kalman);
	printf("卡爾曼誤差所佔比例:%d%%\n", 100 - (int)((summerror_kalman / summerror_measure) * 100));

	getchar();
}
