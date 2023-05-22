// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// COMENTARIOS: programa de prueba del TAD cola
// Se compila con:
// g++ main_queue.cpp -o main_queue

//#include <cstdio>
#include "queue_v_t.h"
#include "queue_l_t.h"

int main(void)
{
	queue_v_t<char> cola_vector;

	for (int i = 0; i < 10; i++)
	{
		cola_vector.push('a' + i);
		cout << cola_vector;
	}

	cout << endl;

	queue_l_t<char> cola_lista;

	for (int i = 0; i < 10; i++)
	{
		cola_lista.push('a' + i);
		cout << cola_lista;
	}

	cout << endl;

	//Invertir una cola
	cout << "Cola original: ";
	cola_vector.write();
	cout << "Cola invertida: ";
	cola_vector.mirror();
	cola_vector.write();
	cout << endl;

	//Dividir la cola en posiciones pares e impares
	queue_l_t<char> cola_par, cola_impar;
	cola_lista.divide(cola_par, cola_impar);
	cout << "Cola con posiciones pares: ";
	cola_par.write();
	cout << "Cola con posiciones impares: ";
	cola_impar.write();

	//Fusionar las dos colas resultantes del problema anterior
	queue_l_t<char> cola_fusionada;
	
	
	

	return 0;
}
