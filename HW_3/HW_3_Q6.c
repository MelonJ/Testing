#include <stdio.h>

void min_max_finder(int* array, int* max, int* min, int size);

int main(){
	
	int min;
	int max;
	int my_arr[10] = {1,22,3,84,5,86,7,1008,-9,10};
	int size = sizeof(my_arr)/ sizeof(my_arr[0]);

	min_max_finder(my_arr, &min, &max, size);
	printf("Min: %d | Max: %d\n", min, max);

	return 0;
}
void min_max_finder(int* array, int* max, int* min, int size){
	
	if(size <= 0)
		return;

	else{
		*min = array[0];
		*max = array[0];

		for(int i = 1; i < size; i++){
			if(array[i] < *min)
				*min = array[i];
			if(array[i] > *max)
				*max = array[i];
		}
	}
}
