/* Lab2 V2 writing startup.c 
	Mohamed Mohsen
*/

/* External Symbols from Linker script*/
extern unsigned long _STACK_TOP;
extern unsigned long _S_data ;
extern unsigned long _E_data ;
extern unsigned long _S_bss ;
extern unsigned long _E_bss ;
extern unsigned long _E_text ;

extern int main(void);
/* Declaration of Handlers */
void Reset_Handler(void);
void Default_Handler(void){
	Reset_Handler();
}
void H_fault_Handler(void)__attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler(void)__attribute__((weak, alias("Default_Handler")));
void Bus_Fault(void)__attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler(void)__attribute__((weak, alias("Default_Handler")));
unsigned long vectors[] __attribute__((section(".vectors"))) = {
	(unsigned long) &_STACK_TOP,
	(unsigned long) &Reset_Handler,
	(unsigned long) &H_fault_Handler,
	(unsigned long) &MM_Fault_Handler,
	(unsigned long) &Bus_Fault,
	(unsigned long) &Usage_Fault_Handler
};

void Reset_Handler(void){
	/* Information about .data Segment */
	unsigned long data_size = (unsigned char*)&_E_data - (unsigned char*)&_S_data ;
	/* Information about .bss Segment */
	unsigned long bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;
	/* Pointer used for Trasfering */
	unsigned char* p_src ;
	unsigned char* p_des ;

	/* Transfering .data from Flash to RAM */
	p_src = (unsigned char*)&_E_text;
	p_des = (unsigned char*)&_S_data;
	for(unsigned long i=0; i<data_size; i++){
		*((unsigned char*)(p_des)) = *((unsigned char*)(p_src));
		p_des ++ ;
		p_src ++ ;
	}
	/* Initialization of .bss with 0 in RAM */
	p_des = (unsigned char*)&_S_bss ;
	for(unsigned long i=0; i<bss_size; i++){
		*((unsigned char*)(p_des)) = (unsigned char)0 ;
	}

	/* Calling main function */
	main();

}


















