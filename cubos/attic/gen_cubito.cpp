#include <iostream>
#include <stdlib.h>
using namespace std;


//el cubito se codifica con 6 enteros que contienen el color de: respectivamente arriba, abajo, frente, derecha, atrás, izquierda

// 0
//2345
// 1

//rota horizontalmente el cubito
void rotarh(int a[]) {
  int aux = 0;
  aux = a[2];
  a[2]=a[3];
  a[3]=a[4];
  a[4]=a[5];
  a[5]=aux;
}

//rota verticalmente el cubito
void rotarv(int a[]) {
  int aux = 0;
  aux = a[0];
  a[0]=a[2];
  a[2]=a[1];
  a[1]=a[4];
  a[4]=aux;
}

//compara si dos array son iguales
bool comparar(int a[], int b[]){
	bool t = true;
	for(int i =0; i<6; i++){
		if(a[i] != b[i]){t = false;}
	}
	return t;
}

//compara si dos array son iguales modulo rotación horizontal.
bool compararh(int a[], int b[]){
	bool t = false;
	for(int i =0; i<4; i++){
		t = (t ||comparar(a,b));
		rotarh(a);
		t = (t ||comparar(a,b));
		rotarh(a);
		t = (t ||comparar(a,b));
		rotarh(a);
		t = (t ||comparar(a,b));
		rotarh(a);
	}
	return t;
}


void mostrar(int a[] ){
	for(int i =0; i<6; i++){
		cout << a[i] << ' ';
	}
}

int main() {
	int c[200];
	int count0 = 0;
	int count1 = 1;
	for(int i =0; i<200; i++){
		c[i] = rand()%2;
		if(count0 >= 100){c[i]=1;}
		if(count1 >= 100){c[i]=0;}
		if(c[i]==0){count0++;}
		if(c[i]==1){count1++;}
	}
	int a[6];
	int b[6];
	for(int i =0; i<200; i++){
		for(int j =0; j<6; j++){
			a[j]=rand()%6;
		}
		if(c[i]==0){//generar el otro cubo como rotación del primero.
			for(int j =0; j<6; j++){
				b[j]=a[j];
			}
			for(int j =0; j<100; j++){
				if((rand()%2)==0){
				rotarh(b);
				}
				else{rotarv(b);}
			}
		}
		if(c[i]==1){//generar el otro cubo aleatoriamente, MUY baja chance de que sean iguales.
			for(int j =0; j<6; j++){
				b[j]=rand()%6;
			}
		}
		mostrar(a);
		cout << '\n';
		mostrar(b);
		cout << '\n';
	}
}
