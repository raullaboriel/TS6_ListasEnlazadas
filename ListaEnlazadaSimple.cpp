#include <iostream>
using namespace std;

struct Nodo{
  int dato;
  Nodo *siguiente;
};

void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
bool buscarLista(Nodo *, int);
void eliminarLista(Nodo *&, int);

Nodo *lista;

int main() {
  insertarLista(lista, 1);
  insertarLista(lista, 2);
  insertarLista(lista, 3);
  insertarLista(lista, 4);
  insertarLista(lista, 5);
  mostrarLista(lista);
}

void insertarLista(Nodo *&lista, int n){
  Nodo *nuevoNodo = new Nodo();
  nuevoNodo->dato = n;
  Nodo *aux1 = lista;
  Nodo *aux2;

  while((aux1 != NULL) && (aux1->dato < n)){
    aux2 = aux1;
    aux1 = aux1->siguiente;
  }

  if(lista == aux1)
    lista = nuevoNodo;
  else
    aux2->siguiente = nuevoNodo;

  nuevoNodo->siguiente = aux1;
}

void mostrarLista(Nodo *lista){
  Nodo *actual = lista;
  while(actual != NULL){
    cout<<actual->dato<<" ";
    actual = actual -> siguiente;
  }
  delete(actual);
  cout<<endl;
}

bool buscarLista(Nodo *lista, int n){
  Nodo *aux = lista;
  while(aux != NULL && aux -> dato <= n){
    if(aux -> dato == n){
      return true;
    }
    aux = aux -> siguiente;
  }
  return false;
}

void eliminarLista(Nodo *&lista, int n){
  if(lista != NULL){
    Nodo *auxBorrar = lista;
    Nodo *anterior = NULL;

    while(auxBorrar != NULL && auxBorrar -> dato != n){
      anterior = auxBorrar;
      auxBorrar = auxBorrar -> siguiente;
    }

    if(auxBorrar == NULL){
      cout<<"El elemento no ha sido encontrado"<<endl;
    }else if(anterior == NULL){
      lista = lista -> siguiente;
      delete auxBorrar;
    }else{
      anterior -> siguiente = auxBorrar -> siguiente;
      delete auxBorrar;
    }
  }
}