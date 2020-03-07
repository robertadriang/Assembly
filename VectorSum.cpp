#include <iostream>
using namespace std;

/*Compute the sum for a vector of n elements */

int main() {
	int t[1000], suma, n;

	cin >> n;
	for (i = 0; i < n; i++)
		cin >> t[i];
	_asm {
		mov ecx,n
		mov eax, 0
		mov ebx, 0
		inceput_for:
		cmp ebx, ecx
			jae afara
			add eax, t[ebx * 4]
			inc ebx
			jmp inceput_for
			afara :
		mov suma, eax
	}
	cout << suma;
}

/*int main() {
	int t[1000];
	int suma = 0;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> t[i];

	for (int i = 0; i < n; i++)
		suma = suma + t[i];
	cout << suma << endl;
}
*/

