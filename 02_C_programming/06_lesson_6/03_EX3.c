#include <stdio.h>
#include <string.h>

struct complex{
	float real;
	float imaginary;
};

struct complex add_complex(struct complex c1, struct complex c2);

int main(){
	struct complex c1, c2, c_sum;

	printf("Enter Data for 1st complex number:\n");
	printf("Enter Real part: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &c1.real);
	printf("Enter Imaginary part: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &c1.imaginary);

	printf("Enter Data for 2st complex number:\n");
	printf("Enter Real part: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &c2.real);
	printf("Enter Imaginary part: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &c2.imaginary);

	c_sum = add_complex(c1, c2);

	printf("Sum = %.2f + %.2f i\n", c_sum.real, c_sum.imaginary);

	return 0;
}

struct complex add_complex(struct complex c1, struct complex c2){
	struct complex c_sum;

	c_sum.real = c1.real + c2.real;
	c_sum.imaginary= c1.imaginary + c2.imaginary;
	return c_sum;
}
