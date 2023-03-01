void Erosion(int n, int filter_size, short* image_org) {

	__asm {
		MOV ESI, image_org
		MOV EBX,filter_size
		SAR EBX, 1
		MOV filter_size,EBX
		MOV EAX, 1
		IMUL EAX, filter_size
		IMUL EAX, 1024
		SAL n, 1
		ADD n, ESI
		SUB n, EAX
		ADD ESI, EAX

		L1 : MOV ECX, filter_size
		NEG ECX
		MOV EAX, ECX
		IMUL EAX, 512
		MOV ECX, EAX
		MOV AX, WORD PTR[ESI]

		L2 : MOV EDX, filter_size
		NEG EDX

		L3 : MOV EDI, ESI
		XOR EBX, EBX
		ADD EBX, ECX;K* N
		ADD EBX, EDX;L
		SAL EBX, 1
		ADD EDI, EBX
		MOV BX, WORD PTR[EDI]
		CMP BX, AX
		JAE L4
		MOV AX, BX
		L4 : INC EDX
		CMP EDX, filter_size
		JLE L3
		INC ECX
		CMP ECX, filter_size
		JBE L2
		PUSH AX
		ADD ESI, 2
		CMP ESI, n
		JBE L1

		MOV ESI, image_org
		MOV EAX, 1
		IMUL EAX, filter_size
		IMUL EAX, 1024
		ADD ESI, EAX
		MOV EDI, n
		L5 : POP AX
		MOV WORD PTR[EDI], AX
		SUB EDI, 2
		CMP EDI, ESI
		JAE L5
	}
	printf("\n\"eroded.pgm\" has created...\n");
}
