#include <stdio.h>
#include <stdlib.h>

#define RADIUS			0
#define X_COORDINATE	1
#define Y_COORDINATE	2

int main(void)
{
	float min_coordinate[3][3] = {{1.0, 1.0, 2.0}, {1.0, 3.0, 2.0}, {1.0, 2.0, 3.0}},
		  axis1[3], axis2[3], axis3[3], x_coordinate, y_coordinate;
	
	int i, j;  
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%f ", min_coordinate[i][j]);
		}
	}
	
	putchar('\n');
	
	if(min_coordinate[0][Y_COORDINATE] != min_coordinate[1][Y_COORDINATE])
	{	
		//Linear Equation of Two Circle Twice Intersect
		//
		//Circle1 Equation - Circle2 Equation = Root Axis1
		//Y = M * K + X, M = (X1 - X2) / (Y2 - Y1), K = (R1 * R1 - R2 * R2 + X2 * X2 - X1 * X1 + Y2 * Y2 - Y1 * Y1) / (2 * Y2 - 2 * Y1)
		axis1[0] = (min_coordinate[0][X_COORDINATE] - min_coordinate[1][X_COORDINATE]) / (min_coordinate[1][Y_COORDINATE] - min_coordinate[0][Y_COORDINATE]);
		axis1[1] = -1;
		axis1[2] = ((min_coordinate[0][RADIUS] * min_coordinate[0][RADIUS]) - (min_coordinate[1][RADIUS] * min_coordinate[1][RADIUS])
					+ (min_coordinate[1][X_COORDINATE] * min_coordinate[1][X_COORDINATE]) - (min_coordinate[0][X_COORDINATE] * min_coordinate[0][X_COORDINATE])
					+ (min_coordinate[1][Y_COORDINATE] * min_coordinate[1][Y_COORDINATE]) - (min_coordinate[0][Y_COORDINATE] * min_coordinate[0][Y_COORDINATE]))
					/ (2 * (min_coordinate[1][Y_COORDINATE] - min_coordinate[0][Y_COORDINATE]));
	}
	else
	{	
		//Linear Equation of Two Circle Twice Intersect
		//
		//Circle1 Equation - Circle2 Equation = Root Axis1
		//Y = M * K + X, M = (X1 - X2), K = (R1 * R1 - R2 * R2 + X2 * X2 - X1 * X1) / (2)
		axis1[0] = (min_coordinate[0][X_COORDINATE] - min_coordinate[1][X_COORDINATE]);
		axis1[1] = -1;
		axis1[2] = ((min_coordinate[0][RADIUS] * min_coordinate[0][RADIUS]) - (min_coordinate[1][RADIUS] * min_coordinate[1][RADIUS])
					+ (min_coordinate[1][X_COORDINATE] * min_coordinate[1][X_COORDINATE]) - (min_coordinate[0][X_COORDINATE] * min_coordinate[0][X_COORDINATE]))
					/ (2);
	}
	
	if(min_coordinate[1][Y_COORDINATE] != min_coordinate[2][Y_COORDINATE])
	{
		//Circle2 Equation - Circle3 Equation = Root Axis2
		//Y = M * K + X, M = (X2 - X3) / (Y3 - Y2), K = (R2 * R2 - R3 * R3 + X3 * X3 - X2 * X2 + Y3 * Y3 - Y2 * Y2) / (2 * Y3 - 2 * Y2)
		axis2[0] = (min_coordinate[1][X_COORDINATE] - min_coordinate[2][X_COORDINATE]) / (min_coordinate[2][Y_COORDINATE] - min_coordinate[1][Y_COORDINATE]);
		axis2[1] = -1;
		axis2[2] = ((min_coordinate[1][RADIUS] * min_coordinate[1][RADIUS]) - (min_coordinate[2][RADIUS] * min_coordinate[2][RADIUS])
					+ (min_coordinate[2][X_COORDINATE] * min_coordinate[2][X_COORDINATE]) - (min_coordinate[1][X_COORDINATE] * min_coordinate[1][X_COORDINATE])
					+ (min_coordinate[2][Y_COORDINATE] * min_coordinate[2][Y_COORDINATE]) - (min_coordinate[1][Y_COORDINATE] * min_coordinate[1][Y_COORDINATE]))
					/ (2 * (min_coordinate[2][Y_COORDINATE] - min_coordinate[1][Y_COORDINATE]));
	}
	else
	{	
		//Linear Equation of Two Circle Twice Intersect
		//
		//Circle1 Equation - Circle2 Equation = Root Axis1
		//Y = M * K + X, M = (X1 - X2), K = (R1 * R1 - R2 * R2 + X2 * X2 - X1 * X1) / (2)
		axis1[0] = (min_coordinate[0][X_COORDINATE] - min_coordinate[1][X_COORDINATE]);
		axis1[1] = -1;
		axis1[2] = ((min_coordinate[0][RADIUS] * min_coordinate[0][RADIUS]) - (min_coordinate[1][RADIUS] * min_coordinate[1][RADIUS])
					+ (min_coordinate[1][X_COORDINATE] * min_coordinate[1][X_COORDINATE]) - (min_coordinate[0][X_COORDINATE] * min_coordinate[0][X_COORDINATE]))
					/ (2);
	}

	if(min_coordinate[0][Y_COORDINATE] != min_coordinate[2][Y_COORDINATE])
	{
		//Circle1 Equation - Circle3 Equation = Root Axis3
		//Y = M * K + X, M = (X1 - X3) / (Y3 - Y1), K = (R1 * R1 - R3 * R3 + X3 * X3 - X1 * X1 + Y3 * Y3 - Y1 * Y1) / (2 * Y3 - 2 * Y1)
		axis3[0] = (min_coordinate[0][X_COORDINATE] - min_coordinate[2][X_COORDINATE]) / (min_coordinate[2][Y_COORDINATE] - min_coordinate[0][Y_COORDINATE]);
		axis3[1] = -1;
		axis3[2] = ((min_coordinate[0][RADIUS] * min_coordinate[0][RADIUS]) - (min_coordinate[2][RADIUS] * min_coordinate[2][RADIUS])
					+ (min_coordinate[2][X_COORDINATE] * min_coordinate[2][X_COORDINATE]) - (min_coordinate[0][X_COORDINATE] * min_coordinate[0][X_COORDINATE])
					+ (min_coordinate[2][Y_COORDINATE] * min_coordinate[2][Y_COORDINATE]) - (min_coordinate[0][Y_COORDINATE] * min_coordinate[0][Y_COORDINATE]))
					/ (2 * (min_coordinate[2][Y_COORDINATE] - min_coordinate[0][Y_COORDINATE]));
	}
	else
	{	
		//Linear Equation of Two Circle Twice Intersect
		//
		//Circle1 Equation - Circle2 Equation = Root Axis1
		//Y = M * K + X, M = (X1 - X2), K = (R1 * R1 - R2 * R2 + X2 * X2 - X1 * X1) / (2)
		axis1[0] = (min_coordinate[0][X_COORDINATE] - min_coordinate[1][X_COORDINATE]);
		axis1[1] = -1;
		axis1[2] = ((min_coordinate[0][RADIUS] * min_coordinate[0][RADIUS]) - (min_coordinate[1][RADIUS] * min_coordinate[1][RADIUS])
					+ (min_coordinate[1][X_COORDINATE] * min_coordinate[1][X_COORDINATE]) - (min_coordinate[0][X_COORDINATE] * min_coordinate[0][X_COORDINATE]))
					/ (2);
	}
	
	if((min_coordinate[0][Y_COORDINATE] != min_coordinate[1][Y_COORDINATE]) && (min_coordinate[1][Y_COORDINATE] != min_coordinate[2][Y_COORDINATE])
		&& (min_coordinate[0][Y_COORDINATE] != min_coordinate[2][Y_COORDINATE]))
	{
		//Three Linear To Find One Point
		//X = (K2 - K1) / (M1 - M2), Y = M1 * X + K1
		x_coordinate = (axis2[2] - axis1[2]) / (axis1[0] - axis2[0]);
		y_coordinate = (axis1[0] * x_coordinate) + axis1[2];
	}
	else
	{
		//Three Linear To Find One Point
		//X = ((-1 * K1) / M1), Y = M2 * X + K2
		x_coordinate = ((-1 * axis1[2]) / axis1[0]);
		y_coordinate = (axis2[0] * x_coordinate) + axis2[2];
	}
	
	printf("%.5f\n%.5f", x_coordinate, y_coordinate);
	
	return 0;
}