#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Multa{
	int dni;
	int codigoInfraccion;
	float monto;
};

class ManejadorMultas{
	vector<Multa>v;
public:
	ManejadorMultas(){
		ifstream archi("multas.dat",ios::binary|ios::in);
		Multa aux;
		while(archi.read(reinterpret_cast<char*>(&aux),sizeof(Multa))){
			v.push_back(aux);
		}
	}
	void condonar(int codigo){
		for(unsigned int i=0;i<v.size();i++) { 
			if (v[i].codigoInfraccion == codigo){
				v[i].monto=0;
			}
		}
	}
	int getDeuda(int dni_consulta){
		int suma=0;
		for(unsigned int i=0;i<v.size();i++) { 
			if(v[i].dni==dni_consulta){
				suma=suma+v[i].monto;
			}
		}
		return suma;
	}
	vector<Multa> obtenerInfracciones(int codigo){
		vector<Multa>aux;
		for(unsigned int i=0;i<v.size();i++) { 
			if(v[i].codigoInfraccion==codigo){
				aux.push_back(v[i]);
			}
		}
		return aux;
	}
};

int main() {
	
	return 0;
}

