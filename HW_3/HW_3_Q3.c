#include <stdio.h>
#include "stdarg.h"

double avg(int list_size, ...){
	va_list mylist;
	double sum = 0.0;

	va_start(mylist, list_size);

	for(int i = 0; i < list_size; i++){
		double num = va_arg(mylist, double);
		sum += num;
	}

	va_end(mylist);

	double average = sum / list_size;
	return average;
}

int main(){
	
	double avg_1 = avg(5, 10.7, 8.8, 42.888, 662.2, 1.1);
	printf("Average 1: %.3lf\n", avg_1);

	double avg_2 = avg(3, 88.8, 77.7, 44.4);
	printf("Average 2: %.2lf\n", avg_2);

	double avg_3 = avg(1, 5.1);
	printf("Average 3: %.2lf\n", avg_3);

	return 0;
}


