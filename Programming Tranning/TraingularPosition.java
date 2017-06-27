float [][] min_coordinate = new float [MAX_COORDINATE_COUNT][3]; //Three Min Device Store Distance、X Coordinate、Y Coordinate
float [][] beacon_distance = new float [MAX_DEVICE_COUNT][3];	 //Every Device Store Distance、X Coordinate、Y Coordinate
float axis1[] = new float [3]; //Circle1, Circle2 Equation		 //Store X Coefficient、Y Coefficient、Constant
float axis2[] = new float [3]; //Circle2, Circle3 Equation
float axis3[] = new float [3]; //Circle1, Circle3 Equation
int down_count = 0;
private void TraingularPosition(BluetoothDevice device, String distances, int x_point, int y_point) {
	int rssi_index = deviceMacList.indexOf(device.getAddress());

	//Store Distance、X Coordinate、Y Coordinate
	beacon_distance[rssi_index][RADIUS] 		 = Float.parseFloat(distances);
	beacon_distance[rssi_index][X_COORDINATE]	 = x_point;
	beacon_distance[rssi_index][Y_COORDINATE]	 = y_point;

	//Sort
	for(int i = 0; i < MAX_DEVICE_COUNT; i++)
	{
		for(int j = 0; j < MAX_DEVICE_COUNT - 1; j++)
		{
			if(beacon_distance[j][RADIUS] > beacon_distance[j + 1][RADIUS])
			{
				float temp = beacon_distance[j][RADIUS];
				beacon_distance[j][RADIUS] = beacon_distance[j + 1][RADIUS];
				beacon_distance[j + 1][RADIUS] = temp;

				temp = beacon_distance[j][X_COORDINATE];
				beacon_distance[j][X_COORDINATE] = beacon_distance[j + 1][X_COORDINATE];
				beacon_distance[j + 1][X_COORDINATE] = temp;

				temp = beacon_distance[j][Y_COORDINATE];
				beacon_distance[j][Y_COORDINATE] = beacon_distance[j + 1][Y_COORDINATE];
				beacon_distance[j + 1][Y_COORDINATE] = temp;
			}
		}
	}

	//Pass The 200 Times Function Call
	//if(down_count++ < 200) return;

	//Find The Three Shortest Distance
	for(int index = 0; index < MAX_DEVICE_COUNT - 2; index++)
	{
		if (beacon_distance[index][RADIUS] > 0)
		{
			min_coordinate[0][RADIUS] 		   	= beacon_distance[index][RADIUS];
			min_coordinate[0][X_COORDINATE] 	= beacon_distance[index][X_COORDINATE];
			min_coordinate[0][Y_COORDINATE] 	= beacon_distance[index][Y_COORDINATE];

			min_coordinate[1][RADIUS] 		  	= beacon_distance[index + 1][RADIUS];
			min_coordinate[1][X_COORDINATE] 	= beacon_distance[index + 1][X_COORDINATE];
			min_coordinate[1][Y_COORDINATE] 	= beacon_distance[index + 1][Y_COORDINATE];

			min_coordinate[2][RADIUS]			= beacon_distance[index + 2][RADIUS];
			min_coordinate[2][X_COORDINATE]	= beacon_distance[index + 2][X_COORDINATE];
			min_coordinate[2][Y_COORDINATE] 	= beacon_distance[index + 2][Y_COORDINATE];

			break;
		}
	}

	//Linear Equation of Two Circle Twice Intersect
	//If Y Coefficient Both Are Equal, Then Do Exception Process
	//
	if(min_coordinate[0][Y_COORDINATE] != min_coordinate[1][Y_COORDINATE])
	{
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
		//Circle2 Equation - Circle3 Equation = Root Axis2
		//Y = M * K + X, M = (X1 - X2), K = (R1 * R1 - R2 * R2 + X2 * X2 - X1 * X1) / (2)
		axis2[0] = (min_coordinate[0][X_COORDINATE] - min_coordinate[1][X_COORDINATE]);
		axis2[1] = -1;
		axis2[2] = ((min_coordinate[0][RADIUS] * min_coordinate[0][RADIUS]) - (min_coordinate[1][RADIUS] * min_coordinate[1][RADIUS])
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
		//Circle1 Equation - Circle3 Equation = Root Axis3
		//Y = M * K + X, M = (X1 - X2), K = (R1 * R1 - R2 * R2 + X2 * X2 - X1 * X1) / (2)
		axis3[0] = (min_coordinate[0][X_COORDINATE] - min_coordinate[1][X_COORDINATE]);
		axis3[1] = -1;
		axis3[2] = ((min_coordinate[0][RADIUS] * min_coordinate[0][RADIUS]) - (min_coordinate[1][RADIUS] * min_coordinate[1][RADIUS])
					+ (min_coordinate[1][X_COORDINATE] * min_coordinate[1][X_COORDINATE]) - (min_coordinate[0][X_COORDINATE] * min_coordinate[0][X_COORDINATE]))
					/ (2);
	}

	//If Two Circle Have No Intersection Point, Then Do Exception Process
	//One Farthest Distance And One Medium Distance To Compare
	//a * x ^ 2 + b * x + c = 0
	//a = 1 + M * M, b = 2 * (M * K - M * Y2 - X2), c = X2 * X2 + Y2 * Y2 + K * K - 2 * K * Y2 - R2 * R2
	float a_parameter, b_parameter, c_parameter;
	a_parameter = 1 + axis2[0] * axis2[0];
	b_parameter = 2 * (axis2[0] * axis2[2] - axis2[0] * min_coordinate[2][Y_COORDINATE] - min_coordinate[2][X_COORDINATE]);
	c_parameter = min_coordinate[1][X_COORDINATE] * min_coordinate[2][X_COORDINATE] + min_coordinate[2][Y_COORDINATE] * min_coordinate[2][Y_COORDINATE]
					+ axis2[2] * axis2[2] - 2 * axis2[2] * min_coordinate[2][Y_COORDINATE] - min_coordinate[2][RADIUS] * min_coordinate[2][RADIUS];

	//If b * b - 4 * a * c Bigger Than 0, It Means They Have Intersection Point
	float x_coordinate = 0.0f, y_coordinate = 0.0f;
	if (b_parameter * b_parameter - 4 * a_parameter * c_parameter > 0)
	{
		//Three Linear To Find One Point
		//If Y Coefficient Both Are Equal, Then Do Exception Process
		//
		if((min_coordinate[0][Y_COORDINATE] != min_coordinate[1][Y_COORDINATE]) && (min_coordinate[1][Y_COORDINATE] != min_coordinate[2][Y_COORDINATE])
				&& (min_coordinate[0][Y_COORDINATE] != min_coordinate[2][Y_COORDINATE]))
		{
			//X = (K2 - K1) / (M1 - M2), Y = M1 * X + K1
			x_coordinate = (axis2[2] - axis1[2]) / (axis1[0] - axis2[0]);
			y_coordinate = (axis1[0] * x_coordinate) + axis1[2];
		}
		else
		{
			//X = ((-1 * K1) / M1), Y = M2 * X + K2
			x_coordinate = ((-1 * axis1[2]) / axis1[0]);
			y_coordinate = (axis2[0] * x_coordinate) + axis2[2];
		}
	}
	else
	{
		x_coordinate = (min_coordinate[0][X_COORDINATE] + min_coordinate[1][X_COORDINATE] + min_coordinate[2][X_COORDINATE]) / 3;
		y_coordinate = (min_coordinate[0][Y_COORDINATE] + min_coordinate[1][Y_COORDINATE] + min_coordinate[2][Y_COORDINATE]) / 3;
	}

	for (int i = 0; i < MAX_COORDINATE_COUNT; i++)
	{
		Log.e("coordinate", i + x_coordinate + " " + y_coordinate);
		Log.e("xy", axis2[0] + " " + axis2[2]);
	}

	if(Float.isNaN(x_coordinate) || Float.isNaN(y_coordinate) || Float.isInfinite(x_coordinate) || Float.isInfinite(y_coordinate))	return;

	tvTraingle.setText("目前定位座標為：(" + String.format("%.5f, %.5f", x_coordinate, y_coordinate) + ")");
	Log.e("CoordinateTest", String.format("%.5f, %.5f", x_coordinate, y_coordinate));
	down_count = 0;
}
