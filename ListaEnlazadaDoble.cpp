#include <iostream>
using namespace std;

struct Nodo{
  int dato;
  Nodo *siguiente;
  Nodo *anterior;
};

void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void mostrarSiguienteAnterior(Nodo *);
bool buscarLista(Nodo *, int);
void eliminarLista(Nodo *&, int);

Nodo *lista;

int main() {
  insertarLista(lista, 1);
  insertarLista(lista, 2);
  insertarLista(lista, 3);
  insertarLista(lista, 4);
  insertarLista(lista, 5);
  mostrarSiguienteAnterior(lista);
}

//Insertar lista
void insertarLista(Nodo *&lista, int n){
  Nodo *nuevoNodo = new Nodo();
  nuevoNodo->dato = n;
  Nodo *aux1 = lista;
  Nodo *aux2;

  while((aux1 != NULL) && (aux1->dato < n)){
    aux2 = aux1;
    aux1 = aux1->siguiente;
  }

  if(lista == aux1){
    nuevoNodo->anterior = NULL;
    lista = nuevoNodo;
  }else{
    nuevoNodo->anterior = aux2;
    aux2->siguiente = nuevoNodo;
  }

  nuevoNodo->siguiente = aux1;
}

//Mostrar lista
void mostrarSiguienteAnterior(Nodo *lista){
  cout<<"\nFormato: | Anterior Actual Siguiente |"<<endl;
  Nodo *actual = lista;
  while(actual != NULL){
    if(actual->anterior != NULL){
      cout<<actual->anterior->dato<<" ";
    }else{
      cout<<"|  ";
    }
    cout<<actual->dato<<" ";
    actual->siguiente != NULL ? cout<<actual->siguiente->dato<<" | " : cout<<" ";
    actual = actual -> siguiente;
  }
  cout<<"|"<<endl;
}

//Eliminar lista
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
      lista->anterior = NULL;
      delete auxBorrar;
    }else{
      anterior -> siguiente = auxBorrar -> siguiente;
      auxBorrar->siguiente->anterior = anterior;
      delete auxBorrar;
    }
  }
}