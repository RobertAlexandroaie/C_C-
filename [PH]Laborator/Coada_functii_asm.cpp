#include <iostream>
using namespace std;

#define MAX 30

class Coada{
private:
	int nr;
	int tab[MAX];

public:

	Coada(){
		this->nr = 0;
	}
	
	void Push(int el){
		if(nr < MAX)
			this->tab[this->nr++] = el;
	}

	void Push_asm(int el){
		_asm{
			mov eax,[ecx]
			cmp eax,MAX
			jge iesire
			inc eax
			mov [ecx],eax
			mov ebx,[ebp+8]
			mov [ecx + 4*eax],ebx
		iesire:
		}
	}
	
	int Pop(){		
		int x = tab[0];
		nr = nr-1;
		for(int i=0; i<nr; i++){
			tab[i] = tab[i+1];
		}
		return x;
	}
	
	int Pop_asm(){
		_asm{
			mov edx,[ecx]
			dec edx
			mov [ecx],edx
			mov eax,[ecx+4]
			xor esi,esi
		_loop:
			cmp esi,edx
			jae end_loop
			mov ebx,[ecx+8+4*esi]
			mov [ecx+4+4*esi],ebx
			inc esi
			jmp _loop
		end_loop:
		}
	}
	

	void Print(){
		for(int i=0;i<this->nr;i++)
			cout<<this->tab[i]<<' ';
		cout << endl;
	}
};

void Push(Coada& c,int el){
	int nr_elem = *((int*)(&c));
	nr_elem++;

	*((int*)(&c)) = nr_elem;
	*(int*) ((unsigned int)&c + 4*nr_elem) = el;
}

void Push_asm(Coada& c,int el){
	
	_asm{
		mov eax,[ebp+8]//pointer spre c
		inc [eax]
		mov ecx,[eax]
		mov ebx,[ebp+12]//el
		mov [eax+ecx*4],ebx
	}
}


int Pop(Coada& c){
	int x = ((int*)(&c))[1];
	((int*)(&c))[0] = ((int*)(&c))[0] - 1;
	for(int i=0; i<((int*)(&c))[0]; i++){
		((int*)(&c))[1+i] = ((int*)(&c))[2+i];
	}
	return x;
}
int Pop_asm(Coada& c){
	_asm{
		mov ecx,[ebp+8]
		mov edx,[ecx]
		dec edx
		mov [ecx],edx
		mov eax,[ecx+4]
		xor esi,esi
	_loop:
		cmp esi,edx
		jae end_loop
		mov ebx,[ecx+8+4*esi]
		mov [ecx+4+4*esi],ebx
		inc esi
		jmp _loop
	end_loop:
	}
}

void main(){
	Coada c;
	c.Push(2);
	c.Push_asm(3);
	Push(c,4);
	Push_asm(c,5);
	c.Print();
	printf("S-a eliminat: %d",c.Pop());
	printf("S-a eliminat: %d",c.Pop_asm());
	printf("S-a eliminat: %d",Pop(c));
	printf("S-a eliminat: %d",Pop_asm(c));
	c.Print();
}