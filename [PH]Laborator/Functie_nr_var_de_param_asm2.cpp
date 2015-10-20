int nrImpare(...){ 
	 _asm{ 
		 xor eax,eax//folosit pentru a returna nr de elemente impare 
		 xor ecx,ecx // contor bucla 
	bucla: 
		 mov edx,[ebp+4] 
		 mov dl,byte ptr [edx+2] 
		 cmp cl,dl//compar contorul cu nr_param
		 je iesire 
		 test [ebp+8+ecx*4],dword ptr 1 
		 jz par 
		 //impar 
		 inc eax 
	par: 
		 inc ecx 
		 jmp bucla
	iesire: 
	 } 
}