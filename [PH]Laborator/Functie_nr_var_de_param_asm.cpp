 int nrImpare(int nr,...){ 
	 _asm{ 
		 xor eax,eax//folosit pentru a returna nr de elemente impare 
		 xor ecx,ecx // contor bucla 
	bucla: 
		 cmp ecx,[ebp+8]//comparam contorul cu nr_param 
		 je iesire 
		 test [ebp+12+ecx*4], dword ptr 1 
		 jz par 
		 //impar 
		 inc eax 
	par: 
		 inc ecx 
		 jmp bucla
	iesire: 
	 } 
}
//Obs: "test" <=> "and", dar nu modifica registri, seteaza doar flagurile.