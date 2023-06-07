#include <stdio.h>

double three_int_avg(int x, int y, int z);

int main(){

	int test_1 = 5;
	int test_2 = 8;
	int test_3 = 41;

	printf("The result of the average function is: %lf", three_int_avg(test_1, test_2, test_3));
	
	return 0;
}

double three_int_avg(int x, int y, int z){

	double avg=((double)(x + y + z))/3;

	return avg;
}
