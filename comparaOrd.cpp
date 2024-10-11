#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
//insercion directa
//shell sort
using namespace std;

void InsercionDir(int[],int);
void ShellSort(int[],int);
void copia(int[],int[],int);
void imprimirArreglo(int[],int);

int main() {
	int op;
	int long n=200000;
	srand(time(0));
	const int long tamMax=200000;
	int arr[tamMax];
	int copy[tamMax];
	auto inicio=chrono::high_resolution_clock::now(); //inicio
	for (int i=0;i<n;i++) {
		arr[i]=0+rand()%(100+1);
		cout<<arr[i]<<" ";
	}
	auto fin=chrono::high_resolution_clock::now(); //fin
	chrono::duration<double> duracion=fin-inicio;
	cout<<endl<<"Tiempo de ejecucion: "<<duracion.count();
	
	do {
		copia(arr,copy,n);
		cout<<endl<<"\tCOMPARACION DE EFICIENCIA\n"
			<<"1. Insercion directa"<<endl
			<<"2. Shell sort"<<endl
			<<"3. Salir del programa"<<endl;
		cout<<"Elija una opcion: "; cin>>op;
		switch (op) {
			case 1:
				InsercionDir(copy,n);
				break;
			case 2:
				ShellSort(copy,n-1);
				break;
			case 3:
				cout<<"Saliendo del programa..."<<endl;
				break;
			default:
				cout<<"Ingrese una opcion valida"<<endl;
		}
	} while (op!=3);
	
	
	
}

void copia(int A[],int copy[],int n) {
	for (int i=0;i<n;i++) {
		copy[i]=A[i];
	}
}

void InsercionDir(int A[],int n) {
	auto inicio=chrono::high_resolution_clock::now(); //inicio
	for (int i=1;i<n;i++) {
	int aux=A[i];
	int k=i-1;
		while (k>=0 && aux<A[k]) {
			A[k+1]=A[k];
			k--;
		}
		A[k+1]=aux;
	}
	auto fin=chrono::high_resolution_clock::now(); //fin
	chrono::duration<double> duracion=fin-inicio;
	imprimirArreglo(A,n);
	cout<<endl<<"Tiempo de ejecucion: "<<duracion.count()<<endl;
}

void ShellSort(int A[],int n) {
	auto inicio=chrono::high_resolution_clock::now(); //inicio
	int k=n+1;
	while (k>1) {
		k/=2;
		int cen=1;
		while (cen==1) {
			cen=0;        
			int i=0;
			while (i+k<=n) {
				if (A[i+k]<A[i]) {
					int aux=A[i];
					A[i]=A[i+k];
					A[i+k]=aux;
					cen=1;
				}
				i++;
			}
		}
	}
	auto fin=chrono::high_resolution_clock::now(); //fin
	chrono::duration<double> duracion=fin-inicio;
	imprimirArreglo(A,n);
	cout<<endl<<"Tiempo de ejecucion: "<<duracion.count()<<endl;
}

void imprimirArreglo(int arr[],int n) {
	cout<<endl<<"Elementos del arreglo:\n";
	for (int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}