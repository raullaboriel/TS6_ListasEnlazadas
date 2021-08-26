#include <iostream>
using namespace std;

struct Nodo{
  int dato;
  Nodo *siguiente;
};

void insertarListaFin(Nodo *&, int);
void insertarListaInicio(Nodo *&, int);
void mostrarLista(Nodo *);
void eliminarLista(Nodo *&, int);

Nodo *lista;
Nodo *fin;

int main() {
  insertarListaFin(lista, 1);
  insertarListaFin(lista, 2);
  insertarListaFin(lista, 3);
  insertarListaFin(lista, 4);
  insertarListaFin(lista, 5);
  mostrarLista(lista);
}

void insertarListaFin(Nodo *&lista, int n){
  Nodo *nuevoNodo = new Nodo();
  nuevoNodo->dato = n;
  Nodo *aux1 = lista;

  if(lista != NULL){
    fin->siguiente = nuevoNodo;
    nuevoNodo->siguiente = lista;
    fin = nuevoNodo;
  }else{
    lista = nuevoNodo;
    nuevoNodo->siguiente = lista;
    fin = lista;
  }
}

void insertarListaInicio(Nodo *&lista, int n){
  Nodo *nuevoNodo = new Nodo();
  nuevoNodo->dato = n;
  Nodo *aux1 = lista;

  if(lista != NULL){
		nuevoNodo->siguiente = lista;
		lista = nuevoNodo;
		fin->siguiente = lista;
  }else{
    lista = nuevoNodo;
    nuevoNodo->siguiente = lista;
    fin = lista;
  }
}


void mostrarLista(Nodo *lista){
  if(lista != NULL){
    Nodo *actual = lista;
    do{
      cout<<actual->dato<<" ";
      actual = actual -> siguiente;
    }while(actual != lista);
    cout<<endl;
  }
}

void eliminarLista(Nodo *&lista, int n){
  if(lista != NULL){
    Nodo *auxBorrar = lista;
    Nodo *anterior = NULL;
  
    while(auxBorrar->siguiente != lista  && auxBorrar -> dato != n){ 
      anterior = auxBorrar;
      auxBorrar = auxBorrar -> siguiente; 
    }

    if(auxBorrar == fin && auxBorrar -> dato != n){
      cout<<"El elemento no ha sido encontrado"<<endl;
    }else if(anterior == NULL){
      if(auxBorrar->siguiente == lista){
      	lista = NULL;
        fin = NULL;
      }else{
        lista = lista -> siguiente;
        fin->siguiente = lista; 
        delete auxBorrar;   
      }
    }else{
      if(auxBorrar == fin){
        anterior -> siguiente = lista;
        fin = anterior;
      }else{
      	anterior -> siguiente = auxBorrar -> siguiente;
      }
      delete auxBorrar;
    }
  }
}