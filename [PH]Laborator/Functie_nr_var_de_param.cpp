#include <stdarg.h>

//nr = numarul de parametri de dupa prima virgula
 int nrImpare(int nr, ...){
	 va_list vl;
	 int result = 0;
	 va_start(vl,nr);
	 while(nr--){
		result += va_arg(vl,int)%2;
	 }
	 va_end(vl);
	 return result;
 }

