#include <iostream>
using namespace std;

// el cubito se codifica con 6 enteros que contienen el color de:
// respectivamente arriba, abajo, frente, derecha, atrás, izquierda

// 0
// 2345
// 1

// rota horizontalmente el cubito
void rotarh(int a[]) {
  int aux = 0;
  aux = a[2];
  a[2] = a[3];
  a[3] = a[4];
  a[4] = a[5];
  a[5] = aux;
}

// rota verticalmente el cubito
void rotarv(int a[]) {
  int aux = 0;
  aux = a[0];
  a[0] = a[2];
  a[2] = a[1];
  a[1] = a[4];
  a[4] = aux;
}

// compara si dos array son iguales
bool comparar(int a[], int b[]) {
  bool t = true;
  for (int i = 0; i < 6; i++) {
    if (a[i] != b[i]) {
      t = false;
    }
  }
  return t;
}

// compara si dos array son iguales modulo rotación horizontal.
bool compararh(int a[], int b[]) {
  bool t = false;
  for (int i = 0; i < 4; i++) {
    t = (t || comparar(a, b));
    rotarh(a);
    t = (t || comparar(a, b));
    rotarh(a);
    t = (t || comparar(a, b));
    rotarh(a);
    t = (t || comparar(a, b));
    rotarh(a);
  }
  return t;
}

void mostrar(int a[]) {
  for (int i = 0; i < 6; i++) {
    cout << a[i] << ' ';
  }
}

int main() {
  int a[6];
  int b[6];
  for (int i = 0; i < 6; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 6; i++) {
    cin >> b[i];
  }
  bool ans = false;
  // caso 1
  ans = (ans || compararh(a, b));
  // caso 2
  rotarv(a);
  ans = (ans || compararh(a, b));
  // caso 3
  rotarv(a);
  ans = (ans || compararh(a, b));
  // caso 4
  rotarv(a);
  ans = (ans || compararh(a, b));
  rotarv(a); // cubo vuelve al estado inicial.
  // caso 5
  rotarh(a);
  rotarv(a);
  ans = (ans || compararh(a, b));
  // caso 6
  rotarv(a);
  rotarv(a);
  ans = (ans || compararh(a, b));
  if (ans)
    cout << 1 << '\n';
  else
    cout << 0 << '\n';
}
