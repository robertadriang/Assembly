#include <iostream>
using namespace std;

/* Converting an unsigned number into a char table*/
int main() {
	unsigned n = 24973;
	char t[20], c;
	_asm {
		mov eax,n
		mov ebx,0
		mov edi,10
		inceput_do_while:
		mov edx,0
		mov eax,n
		div edi
		mov t[ebx],dl
		add t[ebx],'0'
		mov n,eax
		inc ebx
		cmp n,0
			jne inceput_do_while
			mov t[ebx],'\0'

			mov ecx,0
			dec ebx
			inceput_for:
		cmp ecx, ebx
			jae afara_for
			mov al, t[ebx]
			mov ah, t[ecx]
			mov t[ebx], ah
			mov t[ecx], al
			inc ecx
			dec ebx
			jmp inceput_for
				afara_for:
	 }
	for (int i = 0; i < 5; i++)
		cout << t[i];
	return 0;
}

/*
int main() {
	unsigned n = 24973, i = 0, j;
		char t[20], c;
	do {
		t[i] = n % 10 + '0';
		n = n / 10;
		i++;
	} while (n != 0);
	t[i] = '\0';

	for (j = 0, i--; j < i; j++, i--)
	{
		c = t[i];
		t[i] = t[j];
		t[j] = c;
	}

	for(i=0;i<5;i++)
	cout << t[i];
	return 0;
}
*/
