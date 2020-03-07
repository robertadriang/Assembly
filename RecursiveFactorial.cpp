#include <iostream>
using namespace std;

/*The factorial of a number recursive*/

unsigned f(unsigned n) {
	
	_asm {
	mov eax,n
	cmp eax,1
	jbe mai_mic
	mov ebx,eax
	dec eax
	push eax
	call f
	add esp,4
	mul ebx
	jmp afara_functie

	mai_mic:
	mov eax,1
		afara_functie:
	}
}

int main() {
	unsigned n;
	cin >> n;
	_asm {
		push n
		call f
		add esp,4
		mov n,eax
	}
	cout<<n;
	return 0;
}

/*unsigned f(unsigned n)
if (n <= 1)
		return 1;
	else
		return n * f(n - 1);
*/