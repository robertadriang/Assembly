#include <iostream>
using namespace std;

/*
*** IMPLEMENTARE C++***
int main() {
	int n, i,factorial=1;
	cin >> n;
	for (i = 1; i <= n; i++)
		factorial = factorial * i;
	cout << factorial;
}
*/

int main() {
	int n, i, factorial;
	cin >> n;
	_asm {
		mov factorial,1
	}
	for(i=1;i<=n;i++)
		_asm {
		mov eax,factorial
		mov ebx,i
		mul ebx
		mov factorial,eax
	}
	cout << factorial;
}