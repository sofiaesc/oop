#include <iostream>
#include <map>
#include <fstream>
#include <cstring>
using namespace std;

struct Serie{
	char titulo[100];
	int episodios;
};

class AdminSeries{
	map<string,int>m;
	string a_nom;
public:
	void Cargar(string nom_archivo){
		a_nom=nom_archivo;
		ifstream archivo_carga(nom_archivo,ios::binary|ios::in);
		Serie aux;
		while(archivo_carga.read(reinterpret_cast<char*>(&aux),sizeof(aux))){
			m[aux.titulo]=aux.episodios;
		}
		archivo_carga.close();
	}
	void RegistrarEpisodio(string nom_episodio){
		m[nom_episodio]++;
	}
	int EpisodiosVisualizados(string nom_episodio){
		return m[nom_episodio];
	}
	void Guardar(){
		ofstream archivo_guardado(a_nom,ios::binary|ios::in|ios::out);
		for( auto p : m ) { 
			Serie s;
			strcpy(s.titulo,p.first.c_str());
			s.episodios=p.second;
			archivo_guardado.write(reinterpret_cast<char*>(&s),sizeof(Serie));
		}
	}
};

int main() {
	
	return 0;
}

