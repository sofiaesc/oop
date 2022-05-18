#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

/* a) Implemente una funci�n int rand10() que genere un entero aleatorio entre
-10 y 10, y util�cela como argumento para generate para inicializar el
arreglo con valores aleatorios.*/
int rand10() { return -10+rand()%21; }
/* b) Implemente una funci�n bool es_par(int x) que retorne true si el entero
que recibe es par; y util�cela en combinaci�n con count_if para contar
cuantos elementos pares hay en el contenedor generado.*/
bool es_par(int x) { return x%2==0; }
/* c) Implemente una funci�n bool menor_abs(int a, int b) que reciba dos enteros
y retorne verdadero cuando el valor absoluto del primero sea menor que el
valor absoluto del segundo; y utilice esta funci�n en como argumento de
sort para ordenar el vector por valor absoluto.*/
bool menor_abs(int a, int b) { return abs(a)<abs(b); }

string muestra(const int x[], int c) {
	stringstream s;
	for(size_t i=0;i<c;i++) {
		s<<"["<<i<<"]: "<<x[i]<<endl;
	}
	return s.str();
}
//***************************************************************************
int main() {
	// Declare un arreglo est�tico de 20 elementos enteros (int v[20];)
	int v[20];
	// a
	generate(v,v+20,rand10);
	cout<<"Vector original:\n"<<muestra(v,20)<<endl;
	/* b) std:: count(p,u), std:: count_if(p,u,p)
	Devuelve el n�mero de elementos en el rango [primero, �ltimo) que cumplan
	criterios espec�ficos. La primera versi�n cuenta los elementos que son
	iguales a valor, la segunda versi�n cuenta con elementos para los cuales el
	predicado p retorna verdadero.*/
	cout<< "Cant pares: " << count_if(v,v+20,es_par) << endl;
	/* c) std::sort Ordena los elementos en el rango [primero, �ltimo)
	en orden ascendente.
	La primera versi�n utiliza el operador < para comparar los elementos,
	la segunda versi�n utiliza la comparaci�n de objetos funci�n de los dado.
	*/
	
	sort(v,v+20);
	cout<<"Despues de sort(v,v+20)"<<endl;
	cout<<muestra(v,20)<<endl;
	
	sort(v,v+20,menor_abs);
	cout<<"Despues de sort(v,v+20,menor_abs)"<<endl;
	cout<<muestra(v,20)<<endl;
	/* d) Elimine los elementos repetidos utilizando los algoritmos gen�ricos de la
	STL, y luego muestre el arreglo resultante.
	std:: unique
	unique( ForwardIt first, ForwardIt last ) ; (1)
	unique( ForwardIt first, ForwardIt last, BinaryPredicate p ) ; (2)
	Elimina todos los elementos duplicados consecutivos desde el rango
	[primero, �ltimo) y devuelve un iterador past-the-end para el nuevo final
	l�gico de la gama. La primera versi�n utiliza el operador == para comparar
	los elementos, la segunda versi�n utiliza el predicado binario dado p.
	Extracci�n es realizado por el desplazamiento de los elementos en el rango
	de tal manera que los elementos a ser borrados se sobrescriben.
	orden relativo de los elementos que permanecen se conserva y el tama�o
	f�sico del recipiente es sin cambios. Los iteradores que apuntan a un elemento
	entre el nuevo final l�gico y el final f�sico de la gama son todav�a Desreferenciable,
	pero los propios elementos tienen valores no especificados. Una llamada a la
	�nique es seguido por una llamada al m�todo de borrado de un contenedor, que
	borra los valores especificados y reduce el tama�o f�sico del contenedor
	para que coincida con su nuevo tama�o l�gico.
	*/
	//Para que funcione el unique hay que hacer un sort
	sort(v,v+20);
	int *vend = unique(v,v+20);
	int n = vend-v;
	cout<<"Despues de unique"<<endl;
	cout<<muestra(v,n)<<endl;
	
	return 0;
}
