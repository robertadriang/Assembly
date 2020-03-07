#include <iostream>
using namespace std;

/*Merge 2 vectors such that the elements are in increasing order*/

int ic(int tablou1[], int tablou2[], int tablourezultat[], int n1, int n2) {
	_asm {
		mov ebx, 0//i
		mov ecx, 0//j
		mov eax,0//k
		mov esi, tablou1
		mov edi, tablou2
		mov edx,tablourezultat
		mov ebp,n1
		inceput_while :
	
 		cmp ebx, ebp
			jge afara_while 
		cmp ecx, n2
			jge afara_while 
			mov ebp, [esi + ebx * 4]
			mov esp, [edi+ecx*4]
		cmp ebp,esp
			jge ramura_else
		mov [edx+4*eax],ebp
			inc eax
			inc ebx
		
			jmp inceput_while
			ramura_else:
		mov [edx+4*eax],esp
			inc eax
			inc ecx
		
			jmp inceput_while
		afara_while:

		cmp ebx, ebp
			jg afara_if
			mov ecx, ebx;
		inceput_for1:
		cmp ecx, ebp
			jge afara_for_1
			mov esp,[esi+4*ecx]
				mov[edx + 4 * eax],esp
				inc eax
			jmp inceput_for1
			afara_for_1:
		afara_if:

		cmp ecx,n2
			jg afara_if_2
			mov ebx,ecx
			inceput_for2:
		cmp ebx,n2
			jge afara_for_2
			mov esp,[edi+4*ebx]
			mov[edx+4*eax],esp
			inc eax
			jmp inceput_for2
			afara_for_2:
		afara_if_2:
		mov eax,ebp
			add eax,n2
	}

}

int main() {
	int tablou1[] = { 1,3,5 }, tablou2[] = { 2,4 }, tablourezultat[5], n1, n2, nr2;
	nr2=ic(tablou1, tablou2, tablourezultat, 3,2);
	for (int i = 0; i < nr2; i++)
		cout << tablourezultat[i] << " ";

}

/*
int ic(int tablou1[],int tablou2[],int tablourezultat[],int n1,int n2) {
	int i = 0, j = 0,k=0;
	while (i < n1 && j < n2)
	{
		if (tablou1[i] < tablou2[j])
		{
			tablourezultat[k] = tablou1[i];
			k++;
			i++;
		}
		else
		{
			tablourezultat[k] = tablou2[j];
			k++;
			j++;
		}
	}
			if (i <= n1)
			{
				for (j = i; j < n1; j++)
				{
					tablourezultat[k] = tablou1[j];
					k++;
				}
			}
			if (j <= n2)
				for(i=j;i<n2;i++)
				{
					tablourezultat[k] = tablou2[i];
					k++;
				}

			return n1 + n2;

}
*/