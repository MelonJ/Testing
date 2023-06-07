#include <stdio.h>

#define create_average_function(T) \
	T average_##T(T num1, T num2, T num3) {\
		return (num1 + num2 + num3) / 3; \
	}

create_average_function(int)
create_average_function (double)

int main(){


	int int_1 = 8;
	int int_2 = 66;
	int int_3 = 900;

	int int_average = average_int(int_1, int_2, int_3);
	printf("Integer Average: %d\n", int_average);

	double double_1 = 8.5;
	double double_2 = 66.8;
	double double_3 = 900.4;

	double double_average = average_double(double_1, double_2, double_3);
	printf("Double Average: %lf\n", double_average);

	return 0;
}
