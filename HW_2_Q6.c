#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define SERVICE_THRESHOLD 600

//global variables
struct service_rates
{
	double under_threshold;
	double over_threshold;
	double flat_rate;
	double standard_rate;
};

struct summer_rates
{

	double peak_charge;
	double off_peak_charge;
	double flat_rate;
	double standard_rate;
};

struct service_rates S1 = {.under_threshold = 0.105179,
		    .over_threshold = 0.129468,
		    .flat_rate = 8.00,
	            .standard_rate = 0.055826
		   };

struct summer_rates SU1 = {.peak_charge = 0.149656,
		    .off_peak_charge = 0.100649,
		    .flat_rate = 8.00,
		    .standard_rate = 0.055826
	           };

//prototypes
char get_operation_code(void);
void calc_electric_bill(char input);
double calc_summer_meter(void);
double calc_service_meter(void);

int main(){

	bool Quit = false;
	char input;

	while(!Quit){
		
		input = get_operation_code();
		getchar(); //flush input buffer
		if(input == 'Q')
			Quit = true;
		else if(input == 'F')
			continue;
		else{

			calc_electric_bill(input);
			getchar(); //flush input buffer
		}
	}

	return 0;

}

char get_operation_code(void){

	char operation_code;
	
	printf("Please enter an operation code: \n");
	scanf("%c", &operation_code);
	
	if(operation_code != 'q' && operation_code != 'Q' &&
	   operation_code != 'c' && operation_code != 'C' &&
	   operation_code != 's' && operation_code != 'S' &&
	   operation_code != 'r' && operation_code != 'R'){

	   	printf("Invalid Operation Code.\n");
		return 'F';
	}
	
	else{
	return (char)toupper(operation_code);
	}
}

void calc_electric_bill(char input){

	double result;

	switch(input){
		case ('C'):
			result = calc_summer_meter() + calc_service_meter(); 	
			break;

		case ('S'):
			result = calc_summer_meter();
			break;

		case ('R'):
			result = calc_service_meter();
			break;

		default :
			printf("Error, invalid case\n");
	}
	
	printf("Your total bill is: $%0.2lf\n", result); 
}

double calc_service_meter(void){

	int kiloWatt_hours;
	double kiloWatt_diff;
	double result;

	printf("Enter the number of kWh: \n");
	scanf("%d", &kiloWatt_hours);

	if(kiloWatt_hours >= SERVICE_THRESHOLD){

		kiloWatt_diff = kiloWatt_hours - (double)SERVICE_THRESHOLD;

		result = (double)SERVICE_THRESHOLD*S1.over_threshold +
			 kiloWatt_diff*S1.under_threshold +
			 S1.flat_rate +
			 (double)kiloWatt_hours * S1.standard_rate;
	}
	else{
		result = (double)kiloWatt_hours*S1.under_threshold +
			 S1.flat_rate +
			 (double)kiloWatt_hours*S1.standard_rate;
	}

	return result;
}

double calc_summer_meter(void){

	double peak_kiloWatt_hours;
	double off_peak_kiloWatt_hours;
	double result;

	printf("Enter the number of KWh during peak time: \n");
	scanf("%lf", &peak_kiloWatt_hours);
	printf("Enter the number of kWh during off-peak time: \n");
	scanf("%lf", &off_peak_kiloWatt_hours);

	result = peak_kiloWatt_hours*SU1.peak_charge +
	         off_peak_kiloWatt_hours*SU1.off_peak_charge +
		 SU1.flat_rate +
		 (peak_kiloWatt_hours + off_peak_kiloWatt_hours)*SU1.standard_rate;

	return result;
}
