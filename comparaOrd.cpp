#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <windows.h>
using namespace std;
// los protipos de las funciones
void InsercionDir(int[],int,int&);
void ShellSort(int[],int,int&);
void copia(int[],int[],int);
int secuencialDes(int[],int,int,int&);
int binaria(int[],int,int,int&);
void imprimirArreglo(int[],int);
void menuOrdenar(int[],int [],int);
void menuBusqueda(int[], int[],int);
int main() {
	SetConsoleOutputCP(CP_UTF8);
	//inicilizamos el numero srand
	srand(time(0));
	//tamaño maximo del array
	const int long tamMax=10000000;
	//int arr[tamMax];
	//int copy[tamMax];
	//Tamaño varaible del ARRAY
	int n=10000000;
	int* arr = new int[n];
	int* copy = new int[n];
	//generar numeros de 1 a n 
	for (int i=0;i<n;i++) {
		arr[i]=i+1;
	}
	//algoritmo de fisher-yates para desordenar
	for (int i=n-1;i>=0;i--) {
		int j=rand()%(i+1);
		//intercambiar
		int temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
	int op1;
	//menu principal
	cout<<"\n";
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
				menuBusqueda(arr,copy,n);
				break;
			case 0:
				cout<<"Saliendo del programa....\n";
				return 0;
			default :
				cout<<"\nERROR\n";
				
		}
				
	}while(op1!=0);
system("pause");
	return 0;
}

void menuOrdenar(int arr[],int copy[], int n){
	int op;
	//declaracion
	auto inicio = chrono::high_resolution_clock::now();
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion; // Duración
	do {
		int comparaciones=0;
		system("cls");
		copia(arr,copy,n);
		cout<<endl<<"\t MÉTODOS DE COMPARACION DE EFICIENCIA\n"
			<<"1. Insercion directa"<<endl
			<<"2. Shell sort"<<endl
			<<"0. Regresar el menú principal"<<endl;

		cout<<"Elija una opcion: "; cin>>op;
		switch (op) {
			case 1:
				inicio=chrono::high_resolution_clock::now(); // inicio
            	InsercionDir(copy,n,comparaciones);
           		fin=chrono::high_resolution_clock::now(); // fin
            	duracion=fin-inicio;//calcula
            	imprimirArreglo(copy,n);
            	cout<<endl<<"Tiempo de ejecucion (Insercion Directa): "<<duracion.count()<<endl<<endl; // imprime
            	cout<<"Numero de comparaciones: "<<comparaciones<<endl<<endl;
            	system("pause");
				break;
			case 2:
				inicio=chrono::high_resolution_clock::now(); // inicio
				ShellSort(copy,n,comparaciones);
				fin=chrono::high_resolution_clock::now(); // fin
				duracion=fin-inicio;//calcula
				imprimirArreglo(copy,n);
            	cout<<endl<<"Tiempo de ejecucion (Shell Sort): "<<duracion.count()<<endl<<endl; // imprime
            	cout<<"Numero de comparaciones: "<<comparaciones<<endl<<endl;
            	system("pause");
				break;
			case 0:
			
				break;
			default:
				cout<<"Ingrese una opcion valida"<<endl;
		}

	} while (op!=0);	
		
}

void menuBusqueda(int arr[], int copy[], int n) {
		int dato,op,pos;
		//declaracion
		auto inicio = chrono::high_resolution_clock::now();
   		auto fin = chrono::high_resolution_clock::now();
   		chrono::duration<double> duracion; // Duración
		do {
		int comparaciones=0;
		copia(arr,copy,n);
		cout<<endl<<"\tCOMPARACION DE EFICIENCIA\n"
			<<"1. Busqueda secuencial desordenada"<<endl
			<<"2. Busqueda binaria"<<endl
			<<"0. Volver al menu principal"<<endl;
		cout<<"Elija una opcion: "; cin>>op;
		switch (op) {
			case 1:
				cout<<"Ingrese un numero a buscar: "; cin>>dato;
				inicio=chrono::high_resolution_clock::now(); // inicio
				pos=secuencialDes(arr,n,dato,comparaciones);
				fin=chrono::high_resolution_clock::now(); // fin
            	duracion=fin-inicio;//calcula
				if (pos!=-1) {
					cout<<"Resultado de la busqueda indice: ";
					cout<<pos;
				} else {
					cout<<"No se encontro el dato";
				}
				cout<<endl<<"Tiempo de ejecucion (Busqueda Secuencial Desordenada): "<<duracion.count()<<endl<<endl; // imprime
				cout<<"Numero de comparaciones: "<<comparaciones<<endl<<endl;
            	system("pause");
				break;
			case 2:
				ShellSort(copy,n,comparaciones);
				cout<<"Ingrese un numero a buscar: "; cin>>dato;
				inicio=chrono::high_resolution_clock::now(); // inicio
				pos=binaria(copy,n,dato,comparaciones);
				fin=chrono::high_resolution_clock::now(); // fin
            	duracion=fin-inicio;//calcula
				cout<<"Resultado de la busqueda, indice: "<<pos;
				cout<<endl<<"Tiempo de ejecucion (Busqueda Binaria): "<<duracion.count()<<endl<<endl; // imprime
				cout<<"Numero de comparaciones: "<<comparaciones<<endl<<endl;
            	system("pause");
				break;
			case 0:
				break;
			default:
				cout<<"Ingrese una opcion valida"<<endl;
		}
	} while (op!=0);
}

void copia(int A[],int copy[],int n) {
	for (int i=0;i<n;i++) {
		copy[i]=A[i];
	}
}
//metodo de ordenacion por insercion directa
void InsercionDir(int A[],int n,int& comparaciones) {
	for (int i=1;i<n;i++) {
	int aux=A[i];
	int k=i-1;
		while (k>=0 && aux<A[k]) {
			comparaciones++;
			A[k+1]=A[k];
			k--;
		}
		A[k+1]=aux;
	}
}
//metodo de ordenacion por shellsort
void ShellSort(int A[],int n,int& comparaciones) {
	int k=n;
	while (k>0) {
		k/=2;
		int cen=1;
		while (cen==1) {
			cen=0;        
			int i=0;
			comparaciones++;
			while (i+k<n) {
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
}

//Busqueda secuencial desordenada
int secuencialDes(int A[],int n,int dato,int& comparaciones) {
	int pos=-1;
	int i=0;
	while (i<n && A[i]!=dato) {
		comparaciones++;
		i++;
	}
	if (i<n) {
		pos=i;
	}
	return pos;
}
//Busqueda binaria
int binaria(int A[],int n,int dato,int& comparaciones) {
	int izq,der,cen,m,pos;
	izq=0;
	der=n-1;
	cen=0;
	while (izq<=der && cen==0) {
		m=(izq+der)/2; //division entero
		comparaciones++;
		if (A[m]==dato) {
			cen=1;
		} else {
			comparaciones++;
			if(dato>A[m]) {
				izq=m+1;
			} else {
				der=m-1;
			}
		}
	}
	if (cen==1) {
		pos=m;
	} else {
		pos=-izq;
	}
	return pos;
}

void imprimirArreglo(int arr[],int n) {
	cout<<endl<<"Elementos del arreglo:\n";
	for (int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}