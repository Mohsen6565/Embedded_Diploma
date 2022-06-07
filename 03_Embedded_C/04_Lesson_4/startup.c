/* Lab 4 Startup.c */
/* Mohamed Mohsen */

/* Symbols about memory from Linker Script */
extern unsigned long _STACK_TOP;
extern unsigned long _E_text ;
extern unsigned long _S_data ;
extern unsigned long _E_data ;
extern unsigned long _S_bss ;
extern unsigned long _E_bss ;

/* Declaration of main function */
extern int main(void);

/* Getting Stack-top from .bss not from linker script */
static volatile unsigned char  stack_top[1024];

/* Declaration of Handlers */
void Default_Handler(void);
void Reset_Handler(void);
void H_fault_Handler(void)__attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler(void)__attribute__((weak, alias("Default_Handler")));
void Bus_Fault(void)__attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler(void)__attribute__((weak, alias("Default_Handler")));

/* .Vector section in memory using array of pointer to function */
void(* const vectors[])()__attribute__((section(".vectors"))) = {
	(void(*)())((unsigned long)stack_top + sizeof(stack_top)),
	&Reset_Handler,
	&H_fault_Handler,
	&MM_Fault_Handler,
	&Bus_Fault,
	&Usage_Fault_Handler
};

/* Definition of Default Handler */
void Default_Handler(void){
	Reset_Handler();
}
/* Definition of Reset Handler */
void Reset_Handler(void){
	/* Information about .data */
	unsigned long data_size = (unsigned char*)&_E_data - (unsigned char*)&_S_data ;

	/* Information about .bss */
	unsigned long bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;

	/* Pointers used for Transferring */
	unsigned char* p_src ;
	unsigned char* p_des ;

	/* Transferring .data from Flash to RAM */
	p_src = (unsigned char*)&_E_text ;
	p_des = (unsigned char*)&_S_data ;
	for(unsigned long i=0; i<data_size; i++){
		*((unsigned char*)p_des) = *((unsigned char*)p_src);
		p_src ++ ;
		p_des ++ ;
	}

	/* Initialization of .bss in RAM */
	p_des = (unsigned char*)&_S_bss ;
	for(unsigned long i=0; i<bss_size; i++){
		*((unsigned char*)p_des) = (unsigned char)0;
	}

	/* Calling main function */
	main();
}






