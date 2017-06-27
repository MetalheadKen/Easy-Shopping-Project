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

/* �������h�k */
void GaussianElimination(double (*matrix)[COLUMN])
{
	for(int i = 0; i < ROW; i++) {
		/* �p�G�� ROW �������t�Ƭ��s�A�h��M�U�誺�D�s ROW ���洫 */
		if(IS_ZERO(matrix[i][i])) {
			for(int j = i + 1; j < ROW; j++) {
				if(NOT_ZERO(matrix[j][i])) {
					/* �洫�� ROW �P�U�� ROW */
					for(int k = i; k < COLUMN; k++) {
						SWAP(double, matrix[i][k], matrix[j][k]);
					}
					
					break;
				}
			}
		}
		
		/* �Y�� COLUMN �����s�A���ܤU�@ ROW */
		if(IS_ZERO(matrix[i][i])) continue;
		
		/* �⦹ ROW �������t�ƽվ㦨�@�A���F���x�}���﨤�u�����@ */
		double temp = matrix[i][i];
		for(int j = i; j < COLUMN; j++) {
			matrix[i][j] /= temp;
		}
		
		/* ���h�U��Ҧ��� ROW */
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

/* �ϦV�N�^�k */
void BackSubstitution(double (*matrix)[COLUMN], double *answer)
{
	for(int i = ROW - 1; i >= 0; i--) {
		double temp = 0.0;
		
		/* �]�﨤�u���n�D�������ơA�G���ݭp�� */
		for(int j = i + 1; j < COLUMN - 1; j++) {
			temp += matrix[i][j] * answer[j];
		}

		/* ����]���s�ӳy���� Undefined Behavior */
		if(NOT_ZERO(matrix[i][i])) {
			answer[i] = (matrix[i][COLUMN - 1] - temp) / matrix[i][i];
		}
	}
}
