#include <iostream>
using namespace std;

/*The sum of elements in a matrix*/

int suma(int** x, int n) {
	_asm {
		push ebx
		push ecx
		mov eax,0 //suma
		mov ebx,0 //i
		mov esi,n
		inceput_for_i:

		cmp ebx,esi
		jge afara_for_i
			mov ecx,0 //j
			inceput_for_j:

			cmp ecx,esi
			jge afara_for_j
			mov edx,x
			mov edx,[edx+ebx*4]
			add eax,[edx+ecx*4]
			inc ecx
			jmp inceput_for_j
			afara_for_j:
			inc ebx
			jmp inceput_for_i
				afara_for_i:
				
			pop ecx
				pop ebx
	}
}

int main() {
	int** x;
	int s;
	x = new int* [3];
	for (int i = 0; i < 3; i++)
		x[i] = new int[3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> x[i][j];

	_asm {
		push dword ptr 3
		push x
		call suma
		add esp,8 
		mov s,eax
	}
	cout << s;
}

/*
int suma(int** x,int n) {
	int s = 0, i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			s = s + x[i][j];
	return s;
}

int main()
{
	int** x;
	x = new int* [3];
	for (int i = 0; i < 3; i++)
		x[i] = new int[3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> x[i][j];
	cout << suma(x, 3);
}
*/