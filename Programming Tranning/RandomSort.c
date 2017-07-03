#include <stdio.h>
#include <time.h>

#define SIZE 50

void Sort(short array[]);

int main(void)
{
	short i, j, array[SIZE];
	
	srand(time(NULL));
	for(i = 0 ; i < SIZE ; i++)
	{
		array[i] = rand() % 100;
	}
	
	Sort(&array[0]);
	
	for(i = 0 ; i < SIZE ; i++)
	{
		printf("%d ", array[i]);
		
		if(i % 10 == 0)
			printf("\n");
	}
	
	return 0;	
}

void Sort(short array[]){
	short i, j, temp;
	
	for(i = 0 ; i < SIZE ; i++)
		for(j = i+1 ; j < SIZE ; j++)
		{
			if(array[i] < array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
}