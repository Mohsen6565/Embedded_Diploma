#include <stdio.h>
#include <string.h>

struct distance{
	int feet;
	float inch;
};

int main(){
	struct distance d1, d2;
	int feet_sum=0.0;
	float inch_sum=0;

	printf("Enter Information of 1st Distance:\n");
	printf("Enter feet: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &d1.feet);
	printf("Enter inch: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &d1.inch);

	printf("Enter Information of 2st Distance:\n");
	printf("Enter feet: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &d2.feet);
	printf("Enter inch: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &d2.inch);

	feet_sum = d1.feet + d2.feet;
	inch_sum = d1.inch + d2.inch;

	while(inch_sum > 12.0){
		inch_sum -= 12.0 ;
		feet_sum += 1 ;
	}

	printf("Sum of Distances = %d\' %.2f\'\n", feet_sum, inch_sum);

	return 0;
}

