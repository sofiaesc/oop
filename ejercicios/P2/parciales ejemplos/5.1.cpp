#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

template<typename T>
class GestionaSecuencia{
	vector<T>v;
	int longitud;
public:
	GestionaSecuencia(int n){
		longitud=n;
		for(int i=0;i<longitud;i++) { 
			v.push_back(1+rand()%(10));
		}
	}
	void IncorporarDesdeBinario(string n_a){
		ifstream archi(n_a,ios::binary|ios::in);
		T aux;
		while(archi.read(reinterpret_cast<char*>(&aux),sizeof(aux))){
			v.push_back(aux);
		}
		archi.close();
	}
	void EliminarElemento(T dato){
		auto it = v.remove(dato);
		v.erase(it,v.end());
	}
	void OrdenarCreciente(int pos){
		auto *it=v[pos];
		sort(it,v.end());
	}
	vector<T> InformarElementos(int p1,int p2){
		vector<T> aux;
		for(int i=p1;i<p2;i++) { 
			aux.push_back(v[i]);
		}
		return aux;
	}
};

int main() {
	
	return 0;
}

