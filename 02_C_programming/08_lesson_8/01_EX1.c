#include <stdio.h>
#include <string.h>

int main(){

	int m = 29 ;
	int *ptr_m;
	ptr_m = &m ;

	printf("Address of m : 0x%x\n", &m);
	printf("Value of m : %d\n", m);
	printf("-----------------------------\n");
	printf("Now ptr_m is assigned with the address of m\n");
	printf("Address to which ptr_m points : 0x%x\n", ptr_m);
	printf("Value to which ptr_m points : %d\n", *ptr_m);
	printf("-----------------------------\n");
	m = 34 ;
	printf("The value of m assigned to 34 now\n");
	printf("Address to which ptr_m points : 0x%x\n", ptr_m);
	printf("Value to which ptr_m points : %d\n", *ptr_m);
	printf("-----------------------------\n");
	*ptr_m = 7;
	printf("The pointer variable ab is assigned with the value 7 now");
	printf("Address of m : 0x%x\n", &m);
	printf("Value of m : %d\n", m);

	return 0;
}

