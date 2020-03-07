#include <iostream>
using namespace std;

/*Bubble Sort*/

void sortare_vector(int* vector, int numar) {
	_asm {
		mov edx, 0 // edx=i
		mov ebx, [ebp + 8]  // ebx=vector[0]
		inceput_for_i:
		cmp edx, [ebp + 12] //[ebp+12]= numar
			jge afara_for_i
			mov ecx, edx
			inc ecx //j=i+1 ecx=j
			inceput_for_j :
		cmp ecx, [ebp + 12]
			jge afara_for_j
			mov edi, [ebx + edx * 4] //[ebx + edx * 4]=vector[i]
			cmp edi, [ebx + ecx * 4]// vector[i] compared vector[j]
			jle afara_if
			push dword ptr[ebx + 4 * edx] //swap using stack.
			push dword ptr[ebx + 4 * ecx]
			pop dword ptr[ebx + 4 * edx]
			pop dword ptr[ebx + 4 * ecx]// the swap is completed
			afara_if:
		inc ecx
			jmp inceput_for_j
			afara_for_j :
		inc edx
			jmp inceput_for_i
			afara_for_i :

	}
}


int main() {
	int vector_de_sortat[] = { 23,54,213,22,99,10,24,0,43,55,30,1 };
	int numar_elemente=sizeof(vector_de_sortat)/4;
	int i;
	sortare_vector(vector_de_sortat, numar_elemente);

	for (i = 0; i < numar_elemente; i++)
		cout << vector_de_sortat[i]<< " ";
	cout << endl;

	_asm {
		mov eax,0
		inceput_for_main:
		cmp eax,numar_elemente
		jge afara_for_main
			mov i,eax

	}
	cout << vector_de_sortat[i] << " ";
	_asm {
		mov eax,i
		inc eax
		jmp inceput_for_main
		afara_for_main:
	}

}

/*
void sortare_vector(int *vector,int numar) {
	int aux;
	for (int i = 0; i < numar - 1; i++)
		for (int j = i + 1; j < numar; j++)
			if (vector[i] > vector[j])
			{
				aux = vector[i];
				vector[i] = vector[j];
				vector[j] = aux;
			}
}*/