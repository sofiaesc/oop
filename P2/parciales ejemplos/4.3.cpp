#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

struct ficha{
	bool borrado;
	string dni,ape,nom;
	float h;
};

bool esta_borrado(ficha aux){
	return (aux.borrado==true);
}

class gestion{
	vector<ficha>v;
	string nombre_archivo;
public:
	gestion(string n_a){
		nombre_archivo=n_a;
		ifstream archi_1(n_a,ios::binary|ios::in);
		ficha aux;
		while(archi_1.read(reinterpret_cast<char*>(&aux),sizeof(aux))){
			v.push_back(aux);
		}
	}
	void eliminar_repetidos(){
		auto it = remove_if(v.begin(),v.end(),esta_borrado);
		v.erase(it,v.end());
	}
	void guardar(){
		ofstream archi_2(nombre_archivo,ios::binary|ios::out);
		for(unsigned int i=0;i<v.size();i++) { 
			archi_2.write(reinterpret_cast<char*>(&(v[i])),sizeof(v[i]));
		}
	}
};

int main() {
	
	ofstream archi_3("eliminar.dat",ios::binary|ios::out);
	vector<ficha>v;
	
	ficha a,b,c,d;
	a.ape="Porta";a.nom="Rocio";a.dni="42869483";a.borrado=false;a.h=43.2;
	b.ape="Borsatti";b.nom="Agustina";b.dni="42843231";b.borrado=true;b.h=41.8;
	c.ape="Lepez";c.nom="Juliana";c.dni="43583293";c.borrado=false;c.h=23.7;
	d.ape="Escudero";d.nom="Sofia";d.dni="42870783";d.borrado=false;d.h=18.9;
	
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	
	
	for(unsigned int i=0;i<v.size();i++) { 
		archi_3.write(reinterpret_cast<char*>(&(v[i])),sizeof(v[i]));
	}
	archi_3.close();
	
	gestion g("eliminar.dat");
	g.eliminar_repetidos();
	g.guardar();
	
	ifstream archi_1("eliminar.dat",ios::binary|ios::in);
	ficha aux;
	while(archi_1.read(reinterpret_cast<char*>(&aux),sizeof(aux))){
		cout<<aux.nom<<" "<<aux.ape<<" "<<aux.dni<<" "<<aux.h<<endl;
	}
	
	return 0;
}

