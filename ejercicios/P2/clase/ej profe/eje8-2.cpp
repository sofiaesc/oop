#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;

string muestra(const vector<int>&v) {
	stringstream s;
	for(size_t i=0;i<v.size();i++) {
		s<<"["<<i<<"]: "<<v[i]<<endl;
	}
	return s.str();
}
int main() {
	//Declaro vector y asigno valores
	const int largo=30;//30
	int ini= 10;//10
	int fin= 21;//21
	vector<int> v1(largo);
	srand(time(0));
	for(size_t i=0;i<v1.size();i++)
		v1[i] = rand()%25;
	cout<<endl<<"Vector original\n";
	cout<<muestra(v1)<<endl;;//LLamo a la funcion muestra
	// a- Utilizo los algoritmos sort y reverse
	cout<<endl<<"Ordeno con sort de "<<ini<<" a "<<fin-1<<", Tamaño: "<<v1.size()<<endl;
	sort(v1.begin()+ini,v1.begin()+fin);
	cout<<muestra(v1)<<endl;;//LLamo a la funcion muestra
	cout<<endl<<"Reordeno con reverse de "<<ini<<" a "<<fin-1<<", Tamaño: "<<v1.size()<<endl;
	reverse(v1.begin()+ini,v1.begin()+fin);
	cout<<muestra(v1)<<endl;;//LLamo a la funcion muestra
	// b - Creo otro vector con los elementos de 10 a 20
	vector<int> v2;
	v2.insert(v2.begin(),v1.begin()+ini,v1.begin()+fin);
	//Borro de v1 esos elementos.
	v1.erase(v1.begin()+ini,v1.begin()+fin);
	cout<<endl<<"Vector v1 sin los elementos de "<<ini<<" a "<<fin<<", Tamaño: "<<v1.size()<<endl;
	cout<<muestra(v1)<<endl;;//LLamo a la funcion muestra
	cout<<endl<<"Vector v2 con los elementos de "<<ini<<" a "<<fin<<", Tamaño: "<<v2.size()<<endl;
	cout<<muestra(v2)<<endl;;//LLamo a la funcion muestra
	// c- utilizo algoritmo count
	cout<<endl<<"Ingrese un valor a buscar en v2: ";
	int x;
	cin>> x;
	cout<< "Se encontró " << count(v2.begin(),v2.end(),x) << " veces." <<endl<< endl;
	/*d - auto: el compilador determina el tipo que sustituirá a la palabra
	clave auto como si estuviera utilizando las reglas para la deducción
	de argumento de plantilla a partir de una llamada de función.
	Tambien utilizare el algoritmo remove y el metodo vector::erase*/
	auto it = remove(v2.begin(),v2.end(),x);
	//Observer que remove coloco un 0 en donde estaba el numero
	cout<<endl<<"Vector v2, despues de remove "<<", Tamaño: "<<v2.size()<<endl;
	cout<<muestra(v2)<<endl;;//LLamo a la funcion muestra
	//std::vector:: erase
	v2.erase(it,v2.end());//El metodo erase elimina la posicion de memoria
	cout<<endl<<"Vector v2, despues de erase "<<", Tamaño: "<<v2.size()<<endl;
	cout<<muestra(v2)<<endl;;//LLamo a la funcion muestra
	return 0;
}
