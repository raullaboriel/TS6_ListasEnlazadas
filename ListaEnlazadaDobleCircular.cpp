#include <iostream>
using namespace std;

struct Nodo{
  int dato;
  Nodo *siguiente;
  Nodo *anterior;
};

void insertarListaFin(Nodo *&, int);
void insertarListaInicio(Nodo *&, int);
void mostrarSiguienteAnterior(Nodo *);
void eliminarLista(Nodo *&, int);

Nodo *lista;
Nodo *fin;
Nodo *inicio;

int main() {
  int dato;
  insertarListaFin(lista, 1);
  insertarListaFin(lista, 2);
  insertarListaFin(lista, 3);
  insertarListaFin(lista, 4);
  insertarListaFin(lista, 5);
  mostrarSiguienteAnterior(lista);
}

//Insertar al inicio de la lista
void insertarListaInicio(Nodo *&lista, int n){
  Nodo *nuevoNodo = new Nodo();
  nuevoNodo->dato = n;
  if(lista != NULL){
    nuevoNodo->siguiente = inicio;
    inicio->anterior = nuevoNodo;
    nuevoNodo->anterior = fin;
    inicio = nuevoNodo;
    fin->siguiente = inicio;
    lista = inicio;
  }else{
    fin = nuevoNodo;
    inicio = nuevoNodo;
    nuevoNodo->siguiente = inicio;
    nuevoNodo->anterior = fin;
    lista = nuevoNodo;
  }
}

//Insertar al fin de la lista
void insertarListaFin(Nodo *&lista, int n){
  Nodo *nuevoNodo = new Nodo();
  nuevoNodo->dato = n;
  if(lista != NULL){
    fin->siguiente = nuevoNodo;
    nuevoNodo->anterior = fin;    
    nuevoNodo->siguiente = inicio;
    inicio->anterior = nuevoNodo;
    fin = nuevoNodo;
  }else{
    fin = nuevoNodo;
    inicio = nuevoNodo;
    nuevoNodo->siguiente = inicio;
    nuevoNodo->anterior = fin;
    lista = nuevoNodo;
  }
}

//Mostrar lista con anterior, actual y siguiente 
void mostrarSiguienteAnterior(Nodo *lista){
  if(lista != NULL){
    cout<<"\nFormato: | Anterior Actual Siguiente |"<<endl;
    Nodo *actual = lista;
    do{
      cout<<"| "<<actual->anterior->dato<<" ";
      cout<<actual->dato<<" ";
      cout<<actual->siguiente->dato<<" ";
      actual = actual -> siguiente;
    }while(actual != inicio);
    cout<<"|"<<endl;
  }
}

//Eliminar lista
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
        inicio = NULL;
      }else{
        lista = auxBorrar -> siguiente;
        inicio = lista;
        inicio->anterior = fin;
        fin->siguiente = inicio; 
      }
      delete auxBorrar;
    }else{
      if(auxBorrar == fin){
        anterior -> siguiente = inicio;
        fin = anterior;
        inicio->anterior = fin;
      }else{
      	anterior -> siguiente = auxBorrar -> siguiente;
        auxBorrar->siguiente->anterior = anterior;
      }
      delete auxBorrar;
    }
  }
}