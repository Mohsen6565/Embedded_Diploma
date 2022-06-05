/* Made by Mohamed Mohsen */

.section .vectors

.word 0x20001000		/* Stack Pointer Address */
/* Building Vector Table */
.word _reset			/* 01- Reset Handler */
.word Vector_handler	/* 02- Hand Fault */
.word Vector_handler	/* 03- MM Fault */
.word Vector_handler	/* 04- Bus Fault */
.word Vector_handler	/* 05- Usage Fault */
.word Vector_handler	/* 06- RESERVED */
.word Vector_handler	/* 07- RESERVED */
.word Vector_handler	/* 08- RESERVED */
.word Vector_handler	/* 09- RESERVED */
.word Vector_handler	/* 10- RESERVED */
.word Vector_handler	/* 11- SV Call  */
.word Vector_handler	/* 12- Debug Reserved */
.word Vector_handler	/* 13- RESERVED */
.word Vector_handler	/* 14- PendSV */
.word Vector_handler	/* 15- Systick */
.word Vector_handler	/* 16- IRQ0 */
.word Vector_handler	/* 17- IRQ1 */
.word Vector_handler	/* 18- IRQ2 */
.word Vector_handler	/* 19 ....  */

.section .text
_reset:
	bl main
	b .

.thumb_func
Vector_handler:
	b _reset
