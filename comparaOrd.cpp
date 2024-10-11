#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <windows.h>
//insercion directa
//shell sort
using namespace std;
// los protipos de las funciones
void InsercionDir(int[],int);
void ShellSort(int[],int);
void copia(int[],int[],int);
void imprimirArreglo(int[],int);
void menuOrdenar(int[],int [],int);
int main() {
	SetConsoleOutputCP(CP_UTF8);
	//Tamaño varaible del ARRAY
	int long n=10000;
	//inicilizamos el numero srand
	srand(time(0));
	//tamaño maximo del array
	const int long tamMax=200000;
	int arr[tamMax];
	int copy[tamMax];
	auto inicio=chrono::high_resolution_clock::now(); //inicializa el temporizador
	for (int i=0;i<n;i++) {
		arr[i]=0+rand()%(100+1);
		cout<<arr[i]<<" ";
	}
	auto fin=chrono::high_resolution_clock::now(); //finaliza el temporizador
	chrono::duration<double> duracion=fin-inicio;// caccula el tiempo de ejecucion 
	cout<<endl<<"Tiempo de ejecucion: "<<duracion.count();// imprime el timpo de ejecucion
int op1;
//menu principal
cout<<"\n";
system("pause");
	do {
		system("cls");
		cout<<"\n--------------MENU PRINCIPAL--------------\n"
			<<"1.- COMPARACIÓN DE DOS MÉTODOS DE ORDENAMIENTO\n"
			<<"2.- COMPARACIÓN DE DOS MÉTODOS DE BÚSQUEDA\n"
			<<"0.- Salir del programa \n\n"
			<<"Escriba la opción: "; cin>>op1;
	
		switch(op1){
			
			case 1:
				menuOrdenar(arr,copy,n);
				break;
			case 2:
				break;
			case 0:
				cout<<"Saliendo del programa....\n";
				return 0;
			default :
				cout<<"\nERROR\n";
				
		}
				
	}while(op1!=0);
system("pause");
}

void menuOrdenar(int arr[],int copy[], int n){
	int op;
	do {
		system("cls");
		copia(arr,copy,n);
		cout<<endl<<"\t MÉTODOS DE COMPARACION DE EFICIENCIA\n"
			<<"1. Insercion directa"<<endl
			<<"2. Shell sort"<<endl
			<<"0. Regresar el menú principal"<<endl;
		cout<<"Elija una opcion: "; cin>>op;
		switch (op) {
			case 1:
				InsercionDir(copy,n);
				break;
			case 2:
				ShellSort(copy,n-1);
				break;
			case 0:
			
				break;
			default:
				cout<<"Ingrese una opcion valida"<<endl;
		}
	} while (op!=0);	
		
}
	
	

//funcion que genera la copia del array original
void copia(int A[],int copy[],int n) {
	for (int i=0;i<n;i++) {
		copy[i]=A[i];
	}
}
//metodo de ordenacion por insercion directa
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
	chrono::duration<double> duracion=fin-inicio; //calcula
	imprimirArreglo(A,n);
	cout<<endl<<"Tiempo de ejecucion: "<<duracion.count()<<endl;//imprime
}
//metodo de ordenacion por shellsort
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
	chrono::duration<double> duracion=fin-inicio;//calcula
	imprimirArreglo(A,n);
	cout<<endl<<"Tiempo de ejecucion: "<<duracion.count()<<endl;//imprime
}
// imprime arrays( es reutilizable)
void imprimirArreglo(int arr[],int n) {
	cout<<endl<<"Elementos del arreglo:\n";
	for (int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}