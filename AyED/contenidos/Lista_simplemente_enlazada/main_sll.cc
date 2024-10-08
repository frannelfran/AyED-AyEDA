// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 
// COMPILACIÓN: g++ -g main_sll.cc -o main_sll
// EJECUCIÓN: ./main_sll

#include <iostream>

#include "sll_t.h"

#define N_CHARS 26

using namespace std;

int main(void)
{
  sll_t<char> lista;

  // Inserción de N_CHARS elementos ('a', 'b, 'c' ...) a la lista por el frente
  for (int i = 0; i < N_CHARS; i++)
    lista.push_front(new sll_node_t<char>('a' + i));

  // Impresión de la lista elemento a elemento
  lista.write(cout);
  cout << endl;

  // Extracción de elemento 1 por el frente
  sll_node_t<char>* nodo = lista.pop_front();
  char dato = nodo->get_data();
  delete nodo;

  // Impresión del elemento 1 extraído
  cout << "Dato 1: " << dato << endl;

  // Extracción de elemento 2 por el frente
  nodo = lista.pop_front();
  dato = nodo->get_data();
  delete nodo;

  // Impresión del elemento 2 extraído
  cout << "Dato 2: " << dato << endl;

  // Extracción de elemento 3 por el frente
  nodo = lista.pop_front();
  dato = nodo->get_data();
  delete nodo;

  // Impresión del elemento 3 extraído
  cout << "Dato 3: " << dato << endl;

  // Impresión de la lista elemento a elemento
  lista.write(cout);
  cout << endl;

  // Búsqueda e impresión del elemento 4 con valor 'n'
  nodo = lista.search('n');
  dato = nodo->get_data();
  cout << "Dato 4: " << dato << endl; 

  // Extracción del elemento siguiente al de valor 'n' localizado anteriormente
  nodo = lista.erase_after(nodo);
  delete nodo;
  cout << "Se ha extraído la letra 'm'" << endl;

  // Impresión de la lista elemento a elemento
  lista.write(cout);
  cout << endl;

  // Elimina el último elemento de la lista
  sll_node_t<char>* ultimo = lista.erase_last();
  char last_element = ultimo -> get_data();
  nodo = lista.search(last_element);
  nodo = lista.erase_after(nodo);
  delete nodo;

  lista.write(cout);
  cout << endl;

  // Intercambia el primer y segundo elemento de la lista
  cout << "Primer y segundo elemento de la lista intercambiados" << endl;
  lista.change_elto();

  lista.write(cout);
  cout << endl;

  // Elimina los elementos impares de la lista y los coloca en otra
  sll_t<char> lista_impar;
  lista_impar.delete_odd(lista);

  cout << "\nLista con los elementos impares puestos\n" << endl;
  lista_impar.write(cout);
  cout << endl;
  
  return 0;
}
