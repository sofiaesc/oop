#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {

	string v[]={"uno","dos","tres","cuatro"};
	ofstream archi(“numeros.dat”, ios::binary);
	for(int i=0; i<5; i++) {
		// no se puede escribir directamente un std::string
		char aux[10]; // usamos un cstring auxiliar, de
		// tamaño fijo (9 letras + ‘\0’)
		strcpy(aux,v[i].c_str()); // copiar el std::string en 
		// el buffer auxiliar
		archi.write(aux,sizeof(aux)); // aux ya es char*
	}
	
	
	return 0;
}

