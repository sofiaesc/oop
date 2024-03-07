#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {

	string v[]={"uno","dos","tres","cuatro","cinco"};
	ofstream archi("numeros.dat", ios::binary);
	for(int i=0; i<5; i++) {
		char aux[10]; 
		strcpy(aux,v[i].c_str());
		archi.write(aux,sizeof(aux)); 
	}
	archi.close();
	
	string m[5];
	ifstream archi1("numeros.dat", ios::binary);
	for(int i=0; i<5; i++) {
		// no se puede leer directamente un std::string
		char aux[10]; // usamos un cstring auxiliar, de
		// tamaño fijo (9 letras + ‘\0’)
		archi1.read(aux,sizeof(aux)); // aux ya es char*
		m[i] = aux; 
		cout<<m[i]<<endl;
	}
	archi1.close();
	
	
	
	return 0;
}

