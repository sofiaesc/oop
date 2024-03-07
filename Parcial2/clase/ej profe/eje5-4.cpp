#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;
struct registro {
	string campo, valor;
} ;
//***************************************************
class ConfigFile{
private:
	vector<registro> V;
	string archi;
public:
	ConfigFile(string x);
	string verCampo(string x);
	void modificarCampo(string x, string y);
	void guardar(string x);
	registro verRegistro(int x){return V[x];}
	int cantReg(){return V.size();}
};
//Implementacion ************************
ConfigFile::ConfigFile(string x){
	archi=x;
	ifstream leer(archi.c_str());
	if(!leer.is_open()){cout<<"Error";getchar();exit(0);}//Valido
	string aux,cadena;
	int pos;
	registro R;
	while(getline(leer,cadena)){
		aux= cadena;
		if(aux.substr(0,1)!="#"){//Si es distinto de #
			pos=aux.find("=");//Busco el =
			R.campo=aux.substr(0,pos);//Corto el campo
			R.valor=aux.substr(pos+1);//Corto el valor
			V.push_back(R);//Agrego R al vector
		}
	}
	leer.close();//Cierro el archivo
}
string ConfigFile::verCampo(string x){
	if(V.empty()){return "Archivo vacio";}
	int i=0;
	while((i<V.size()) && (V[i].campo != x)){
		i++; }
	if(V[i].campo == x)
		return V[i].valor;
	else
		return "ERROR";
}

void ConfigFile::modificarCampo(string x, string y){
	if(V.empty()){return;}
	int i=0;
	while((i<V.size())&&(V[i].campo != x)){
		i++;}
	if(V[i].campo == x)
		V[i].valor= y;
}

void ConfigFile::guardar(string x){
	ofstream escribir(x.c_str());
	if(!escribir.is_open()){cout<<"Error";getchar();exit(0);}//Valido
	for(int i=0; i<V.size(); i++){
		escribir<<V[i].campo<<"="<<V[i].valor<<endl;
	}
	escribir.close();
}

//****************************************************************************
int main(int argc, char *argv[]) {
	ConfigFile F("archiE04.txt");	
	registro aux;
	
	cout<<"Tamaño del Vector:  "<<F.cantReg()<<endl;
	for(int i=0;i<F.cantReg();i++) { 
		aux=F.verRegistro(i);
		cout<<aux.campo<<"= "<<aux.valor<<endl;
	}
	cout<<"\n\nVer campo Facultad: ";
	cout<<F.verCampo("facultad");
	
	cout<<"\n\nModificar campo nro_unidad=6: "<<endl<<endl;
	F.modificarCampo("nro_unidad", "6");
	
	cout<<"Tamaño del Vector:  "<<F.cantReg()<<endl;
	for(int i=0;i<F.cantReg();i++) { 
		aux=F.verRegistro(i);
		cout<<aux.campo<<"= "<<aux.valor<<endl;
	}
	F.guardar("archiE04bis.txt");
	return 0;
}

