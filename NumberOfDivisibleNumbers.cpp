#include <iostream>
using namespace std;

/*Number of numbers that are divisible with a certain number*/

int numar_numere(int* v, int n, int nr) {
	_asm {
		mov ebx, 0  // numarul de numere
		mov ecx, 0 // i
		inceput_for:
		cmp ecx, [EBP + 12]
			jge afara_for
			mov edx, 0
			mov esi, [EBP + 8]
			mov eax, [ESI + 4 * ecx]
			mov esi,[EBP+16]
			div esi
			cmp edx, 0
			jg afara_if 
			inc ebx
			afara_if :
			inc ecx
			jmp inceput_for
			afara_for :
		mov eax, ebx
	}
}

int main() {
	int numar, v[] = { 2,5,6,8,9,11,23,20 },c;
	cin >> numar;
	c = sizeof(v) / 4;
	_asm {
		lea eax,v
		mov ebx,c
		mov ecx,numar
		push ecx
		push ebx
		push eax
		call numar_numere
		add ESP,12
		mov c,eax

	}
	cout << c<<endl;
	c = sizeof(v) / 4;
	cout << numar_numere(v, c, numar);
}

/*int numar_numere(int* v, int n, int nr) {
	int nr_numere = 0;
	for (int i = 0; i < n; i++)
		if (v[i] % nr == 0)
			nr_numere++;
	return nr_numere;
}*/


