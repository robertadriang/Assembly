#include <iostream>
using namespace std;

/*Binary search*/

int vector[] = { 1,4,6,8,10,12,59,200,231,900 };

int cautare_binara(int* vector, int stanga, int dreapta, int mijloc, int element_cautat)
{
	_asm {
		mov ecx, [EBP + 12]   //stanga
		cmp ecx, [EBP + 16] //dreapta 
		jne afara_if_stg_drp
		mov edi,[EBP+20]
		mov ecx, [EBP + 8 + edi]
		cmp ecx, [EBP + 24]
		jne afara_if_element_cautat
		mov eax, [EBP + 12]
		jmp afara_1
			afara_if_element_cautat:
		mov eax,-1
			jmp afara_1
			
			afara_if_stg_drp:

			mov esi,[EBP+20] //edi = mijloc
			mov eax,[EBP+8]
			mov ecx,[eax+4*esi]  //ecx [vector+mijloc]
			cmp ecx,[EBP+24]      // [vectormijloc ==element cautat]
			jne nu_egal
			mov eax,[EBP+20]
			jmp afara_1
			nu_egal:
			cmp ecx, [EBP + 24]
			jl else_if
			push dword ptr [EBP+24]
			mov edx,0
			mov eax,[EBP+12]
			add eax,[EBP+16]
			mov ecx,2
			div ecx
			push eax
			push [EBP+20]
			push [EBP+12]
			push [EBP+8]
			call cautare_binara
			add ESP,20
			jmp afara_1
			else_if:
			push dword ptr [EBP+24]
				mov edx, 0
				mov eax, [EBP + 20] //eax=mijloc
				add eax, [EBP + 16]  //stanga+dreapta
				inc eax
				mov ecx, 2  
				div ecx
				
				push eax
				push [EBP+16]
				mov ecx,[EBP+20]
				inc ecx
				push ecx
				push[EBP + 8]
				call cautare_binara
				add ESP, 20

		afara_1:
	}
}

int main() {
	cout << cautare_binara(vector,0, 10, 5, 12);
}

/*
/*int cautare_binara(int stanga, int dreapta, int mijloc, int element_cautat)
{
	if (stanga == dreapta)
	{
		if (vector[stanga] == element_cautat)
			return stanga;
		else
			return dreapta;
	}

	if (vector[mijloc] == element_cautat)
		return mijloc;

	else if (vector[mijloc] > element_cautat)
		cautare_binara(stanga, mijloc, (stanga + mijloc) / 2, element_cautat);
	else if (vector[mijloc] < element_cautat)
		cautare_binara(mijloc + 1, dreapta, (mijloc + 1 + dreapta) / 2, element_cautat);
}

int main() {
	cout<<cautare_binara(0, 10, 5, 200);
}*/
