#include <iostream>
using namespace std;

/*Chech for the number of bits of 1*/

int main() {
	int nr, a, i;
	_asm {
		mov eax,0
		mov ebx, 1213154
		mov ecx, 0
		inceput_bucla_for:
		cmp ecx, 32
			jae iesire_for
			test ebx, 1
			jz nu_e_1
			inc eax
			nu_e_1 :
		shr ebx, 1
			inc ecx
			jmp inceput_bucla_for
			iesire_for :
		mov nr,eax

	}
	cout << nr;
}

/*
int main() {
	int nr=0,a=1213154,i;
	for (i = 0; i < 32; i++) {
		if (a & 1) nr++;
		a >>= 1;
	}
	cout << nr;
}
*/