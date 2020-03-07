#include <iostream>
using namespace std;

/*The sum of 2 complex numbers*/

struct complex {
	int re, im;
};
complex a = { 2,5 }, b = { 3,11 }, c;

void suma_numere_complexe(complex* a, complex* b, complex* c) {
	_asm {
		mov eax,a
		mov ebx,[eax]
		mov eax,b
		add ebx,[eax]
		mov eax,c
		mov [eax],ebx

		mov eax, a
		mov ebx, [eax+4]
		mov eax, b
		add ebx, [eax+4]
		mov eax, c
		mov[eax+4], ebx
	}
}

int main() {

	suma_numere_complexe(&a, &b, &c);
	cout << c.re << " " << c.im;
	return 0;
}

/*
void suma_numere_complexe(complex *a, complex *b, complex *c) {
	c->re = a->re + b->re;
	c->im = a->im + b->im;
}}*/