MEMORY{
	flash(RX) : ORIGIN = 0x08000000, LENGTH = 128K
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_text = . ;
	}> flash

	.data : {
		_S_data = . ;
		*(.data)
		_E_data = . ;
	}> sram AT> flash

	.bss : {
		. = ALIGN(4);
		_S_bss = . ;
		*(.bss*)
		. = ALIGN(4);
		_E_bss = . ;

		. = . + 0x1000 ;
		_STACK_TOP = . ;
	}> sram
}