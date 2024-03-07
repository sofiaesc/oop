#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

void creaBinario(string nombre, int cant){
	fstream w(nombre , ios::binary |ios::in|ios::out|ios::trunc);
	int d=0;
	for (int i=1; i<=cant; i++){
		w.write((char*)&d, sizeof(d));
		d=d+5;
	} 
	w.close();
}
int main(int argc, char *argv[]) {
	//creaBinario("crecer.dat",10);
	fstream f("crecer.dat" , ios::binary |ios::in|ios::out);
	int d,dato,i,pos;
	f.seekg(0,ios::end);//Me posciono al final del archivo
	int cantidad= (f.tellg()/sizeof(int));//Calculo cantidad de elementos
	f.seekg(0,ios::beg);//llevo el puntero al inicio para comenzar la lectura
	cout<<endl<<"Datos del archivo:\nLargo en cantidad de numeros: "<<cantidad<<endl;
	for (i=0; i<cantidad; i++){
		f.read((char*)&d, sizeof(d));
		cout<<"Posicion:"<<i<<" "<<d<<endl;
	}
	
	cout<<"ingrese un numero: ";
	cin>>d;
	f.seekg(0,ios::beg);//llevo el puntero al inicio para comenzar la lectura
	for (pos=0; pos<cantidad; pos++){
		f.read((char*) &dato, sizeof(dato));
		if (d<=dato) break;
	}
	cout<<d<<" - Encontro la posicion siguiente: "<<pos<<endl;
	
	for (i=cantidad-1;i>=pos;i--){
		f.seekg(i*sizeof(dato),ios::beg);
		f.read((char*)&dato, sizeof(dato));
		f.seekg((i+1)*sizeof(dato),ios::beg);    //esta línea no haría falta porque el lugar de acceso del archivo ya se encuentra aqui
		f.write((char*)&dato, sizeof(dato));
	}
	f.seekg((pos)*sizeof(dato),ios::beg);
	f.write((char*)&d, sizeof(d));			//escribo el dato leido
	
	//muestro nuevamente el archivo modificado
	f.seekg(0,ios::end);//Me posciono al final del archivo
	cantidad= (f.tellg()/sizeof(i));//Calculo cantidad de elementos
	f.seekg(0,ios::beg);//llevo el puntero al inicio para comenzar la lectura
	cout<<endl<<"\nDatos del archivo:\nLargo en cantidad de numeros: "<<cantidad<<endl;
	for (i=0; i<cantidad; i++){
		f.read((char*)&d, sizeof(d));
		cout<<"Posicion:"<<i<<" "<<d<<endl;
	}
	
	f.close();
}
