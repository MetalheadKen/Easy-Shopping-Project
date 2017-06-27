#include <stdio.h>

#define ROW		2
#define COLUMN 	3

#define ZERO 	0.000001

#define SWAP(TYPE, X, Y) {TYPE temp = (X); (X) = (Y); (Y) = temp;}

#define IS_ZERO(X) ((X) < ZERO && (X) > (-ZERO))
#define NOT_ZERO(X) (!((X) < ZERO && (X) > (-ZERO)))

void GaussianElimination(double (*)[COLUMN]);
void BackSubstitution(double (*)[COLUMN], double *);

int main(void)
{
	double matrix[ROW][COLUMN] = {0.0};
	double answer[ROW] = {0.0};
		
	for(int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			scanf("%lf", &matrix[i][j]);
		}
	}
	
	GaussianElimination(matrix);
	
	for(int i = 0; i < ROW; i++) {		
		for (int j = 0; j < COLUMN; j++) {
			printf("%.2f ", matrix[i][j]);
		}
		
		putchar('\n');
	}
	
	BackSubstitution(matrix, answer);

	for(int i = 0; i < (((ROW > COLUMN) ? ROW : COLUMN) - 1); i++) {
		printf("%.2f ", answer[i]);
	}
	
	return 0;
}

/* 高斯消去法 */
void GaussianElimination(double (*matrix)[COLUMN])
{
	for(int i = 0; i < ROW; i++) {
		/* 如果此 ROW 的首項系數為零，則找尋下方的非零 ROW 做交換 */
		if(IS_ZERO(matrix[i][i])) {
			for(int j = i + 1; j < ROW; j++) {
				if(NOT_ZERO(matrix[j][i])) {
					/* 交換此 ROW 與下方 ROW */
					for(int k = i; k < COLUMN; k++) {
						SWAP(double, matrix[i][k], matrix[j][k]);
					}
					
					break;
				}
			}
		}
		
		/* 若此 COLUMN 都為零，跳至下一 ROW */
		if(IS_ZERO(matrix[i][i])) continue;
		
		/* 把此 ROW 的首項系數調整成一，為了讓矩陣的對角線階為一 */
		double temp = matrix[i][i];
		for(int j = i; j < COLUMN; j++) {
			matrix[i][j] /= temp;
		}
		
		/* 消去下方所有的 ROW */
		for(int j = i + 1; j < ROW; j++) {
			if(NOT_ZERO(matrix[j][i])) {
				double temp = matrix[j][i];
				
				for (int k = i; k < COLUMN; k++) {
					matrix[j][k] -= matrix[i][k] * temp;
				}
			}
		}
	}
}

/* 反向代回法 */
void BackSubstitution(double (*matrix)[COLUMN], double *answer)
{
	for(int i = ROW - 1; i >= 0; i--) {
		double temp = 0.0;
		
		/* 因對角線為要求的未知數，故不需計算 */
		for(int j = i + 1; j < COLUMN - 1; j++) {
			temp += matrix[i][j] * answer[j];
		}

		/* 防止因除零而造成的 Undefined Behavior */
		if(NOT_ZERO(matrix[i][i])) {
			answer[i] = (matrix[i][COLUMN - 1] - temp) / matrix[i][i];
		}
	}
}
