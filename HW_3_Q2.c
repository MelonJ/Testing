#include <stdio.h>

#define average(a,b,c) (((a) + (b) + (c)) / 3)

int main(){
	
	int result_1;
	double result_2;

	result_1 = average(5,6,7);
	printf("Values passed: 5,6,7\n");
	printf("average int is %d\n",result_1);

	printf("Values passed: 5.5,6.5,7.5\n");
	result_2 = average(5.5,6.5,7.5);
	printf("average double is %lf\n", result_2);

	return 0;
}


