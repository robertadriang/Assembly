#include <iostream>
using namespace std;

/*Acces an element from a 3x3 matrix*/

int element(int x[][3], int i, int j) {
	_asm {
		push ebx
		push ecx
		push esi
		mov esi,x
		mov ebx,i
		mov ecx,j
		mov eax,3
		imul ebx
		add ecx,eax
		mov eax,[esi+ecx*4]
		pop esi
		pop ecx
		pop ebx
	}
}

int main() {
	int x[][3] = { 1,2,3,4,5,6,7,8,9 };
	cout << element(x, 2, 2);

}


/*int element(int x[][3], int i, int j) {
	return x[i][j];
}

int main() {
	int x[][3] = { 1,2,3,4,5,6,7,8,9 };
	cout << element(x, 2, 2);
}
**/