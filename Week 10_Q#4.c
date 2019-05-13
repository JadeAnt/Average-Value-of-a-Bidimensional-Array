#include <stdio.h>
#include <stdlib.h>

#define NR_ROWS		5
#define NR_COLUMNS	5

FILE *f, *out;

void input_val(float array[][NR_COLUMNS], int Rows, int Col){
	int i, j;
	
	if ((f = fopen("Input_Q4.txt.","r")) == NULL) {
      printf ("File was not opened\n");
      exit(1);
	}
	
	for(i = 0; i < Rows; i++){
		for(j = 0; j < Col; j++){
			fscanf(f,"%f", &array[i][j]);
		}
	}
	
}//function

void average_val(float array[][NR_COLUMNS], int Rows, int Col){
	int i, j;
	float sum = 0.0, average;
	
	out = fopen("Output_Q4.txt","w");
	
	for(i = 0; i < Rows; i++){
		for(j = 0; j < Col; j++){
			fprintf(out,"%f", array[i][j]);
			sum = sum + array[i][j];
		}
	}
	
	average = sum/(Rows * Col);
	printf ("Average Value = %f\n", average);

}//function

int main(){
	float A[NR_ROWS][NR_COLUMNS];
	float solution;
	
	input_val(A, NR_ROWS, NR_COLUMNS);
	
	average_val(A, NR_ROWS, NR_COLUMNS);
	
	return 0;
}
