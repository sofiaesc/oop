#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

string muestra(list<float>&x) {
	stringstream s;
	int a=0;
	for( list<float>::iterator w = x.begin(); w != x.end(); w++){
		s<<a<<": "<<*w<<endl;
		a++;
	}
	return s.str();
}
main(int argc, char *argv[]) {
	//(std::list) Declaro la lista y reservo 15 posiciones
	list<float> lista(15);
	//std:: iterator, utilizado para recorrer la lista
	list<float>::iterator p;
	srand(time(0));
	cout<<"genero 15 números flotantes:"<<endl;
	for( p = lista.begin(); p != lista.end(); p++)
		//cin >> *p;
		*p= (float)(rand()%10);
		//a) mostrar por pantalla
	cout<<"\na) lista(): tamaño:"<<lista.size()<<endl;
	cout<<muestra(lista)<<endl;
	//b) Inserto cada 2 posiciones el promedio.
	//El iterador p apunta al primer elemento del vector
	p = lista.begin();
	list<float>::iterator a , b;
	unsigned int cantidad=lista.size();
	for (unsigned i=0; i<cantidad-1 ; i++){   //tengo un promedio menos
		//Busco los dos datos
		a= p;  //primero
		++p;
		b= p;   //segundo
		lista.insert( p,(*a + *b)/-2);//calculo el promedio y inserto en la posición del segundo
 		
	};
	cout<<"\n\nb) lista con los promedios. Tamaño: "<<lista.size()<<endl;
	cout<<muestra(lista)<<endl;
	//abrir archivo para escritura
	ofstream archi("listafloat.txt");
	if(!archi.is_open()){cout<<"ERROR DE ARCHIVO";exit(1);}
	// grabar los datos de la lista en el archivo
	p= lista.begin();
	cout<<"\nGrabar los datos de la lista en el archivo : "<<lista.size()<<endl;
	for( unsigned i=0; i<lista.size(); ++i, p++ ){
		archi<< *p <<endl;
		cout<< *p <<endl;
		}
	archi.close();
	return 0;
}
