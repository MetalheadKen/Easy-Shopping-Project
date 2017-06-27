#include <stdio.h>

#define MAX_RSSI_COUNT 		10
#define MAX_GAUSSIAN_COUNT 	3

#define SWAP(X, Y) {int TEMP; TEMP = X; X = Y; Y = TEMP;}

int main(void)
{
	int i, j;
	int count, index, times, move;
	int gaussianArrayRSSI[MAX_GAUSSIAN_COUNT] = {0},
		gaussianArrayTIME[MAX_GAUSSIAN_COUNT] = {0},
		rssi[MAX_RSSI_COUNT] = {0};
	
	fflush(stdin);
	for(i = 0; i < MAX_RSSI_COUNT; i++)
		scanf("%d", &rssi[i]);
	
	//Bubble Sort
	for(i = MAX_RSSI_COUNT - 2; i >= 0; i--)
	{
		for (j = 0; j <= i; j++)
		{
			if (rssi[j] > rssi[j + 1])
				SWAP(rssi[j], rssi[j + 1]);
		}
	}
	
	for(i = 0; i < MAX_RSSI_COUNT; i++)
		printf("%d ", rssi[i]);
	
	putchar('\n');

	//Move The Different RSSI
	for (times = 0; times < MAX_RSSI_COUNT; times += count)
	{
		count = 0;

		//Find The Same
		for(i = 0; i < MAX_RSSI_COUNT; i++)
		{
			if(rssi[times] == rssi[i])
				count++;
		}

		//Find Top 20 MAX Count
		for(index = 0; index < MAX_GAUSSIAN_COUNT; index++)
		{
			if(count > gaussianArrayTIME[index])
			{				
				//Move Right
				for(move = MAX_GAUSSIAN_COUNT - 2; move >= index; move--)
				{
					gaussianArrayRSSI[move + 1] = gaussianArrayRSSI[move];
					gaussianArrayTIME[move + 1] = gaussianArrayTIME[move];
				}
				
				gaussianArrayRSSI[index] = rssi[times];
				gaussianArrayTIME[index] = count;

				break;
			}
		}
	}
	
	for(i = 0; i < MAX_GAUSSIAN_COUNT; i++)
		printf("%d %d\n", gaussianArrayRSSI[i], gaussianArrayTIME[i]);
	
	return 0;
}
