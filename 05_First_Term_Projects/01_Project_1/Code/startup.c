/* External Symbols (from linker_script.ld)*/
extern unsigned long _STACK_TOP ;
extern unsigned long _E_text ;
extern unsigned long _S_data ;
extern unsigned long _E_data ;
extern unsigned long _S_bss ;
extern unsigned long _E_bss ;

extern int main() ;

/* Handlers Declaration */
void Reset_Handler(void);
void Default_Handler(void);
void H_fault_Handler(void)__attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler(void)__attribute__((weak, alias("Default_Handler")));
void Bus_Fault(void)__attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler(void)__attribute__((weak, alias("Default_Handler")));

/* .vectors section */
unsigned long vectors[]__attribute__((section(".vectors"))) = {
	(unsigned long) &_STACK_TOP,
	(unsigned long) &Reset_Handler,
	(unsigned long) &H_fault_Handler,
	(unsigned long) &MM_Fault_Handler,
	(unsigned long) &Bus_Fault,
	(unsigned long) &Usage_Fault_Handler
};

void Default_Handler(void){
	Reset_Handler();
}

void Reset_Handler(void){
	/* Information about .data section */
	unsigned long data_size = (unsigned char*)&_E_data - (unsigned char*)&_S_data ;
	/* Information about .bss section */
	unsigned long bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;
	/* Variables used in operation */
	unsigned char* ptr_src ;
	unsigned char* ptr_des ;
	unsigned long i ;
	/* Copying .data from Flash to SRAM */
	ptr_src = (unsigned char*) &_E_text ;  /* Why not _E_text + 1 ??? */
	ptr_des = (unsigned char*) &_S_data ;
	for(i=1; i<=data_size; i++){
		*((unsigned char*)ptr_des) = *((unsigned char*)ptr_src) ;
		ptr_src ++ ;
		ptr_des ++ ;
	}

	/* Initializaion of .bss with zeroes in SRAM */
	ptr_des = (unsigned char*) &_S_bss ;
	for(i=1; i<=bss_size; i++){
		*((unsigned char*)ptr_des) = (unsigned char)0 ;
		ptr_des ++ ;
	}

	/* Calling main */
	main();

}