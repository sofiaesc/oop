#include <iostream>
#include <vector>
using namespace std;

class Tecla{
	string nombre;
	bool estado;
public:
	Tecla(string n) : nombre(n),estado(false){}
	string VerNota(){return nombre;}
	void Apretar(){estado=true;}
	void Soltar(){estado=false;}
	bool EstaApretada(){return estado=true;}
};

class Pedal{
	float presion;
public:
	Pedal() : presion(0){}
	void AsignarPresion(float x){presion=x;}
	float VerPresion(){return presion;}
};

class Instrumento{
public:
	virtual string VerTipo(){
		return "sin_nombre";
	}
};

class Piano : public Instrumento{
	vector<Tecla>teclas;
	Pedal p;
public:
	Piano(){
		teclas.push_back(Tecla("do"));
		teclas.push_back(Tecla("re"));
		teclas.push_back(Tecla("mi"));
		teclas.push_back(Tecla("fa"));
		teclas.push_back(Tecla("sol"));
		teclas.push_back(Tecla("la"));
		teclas.push_back(Tecla("si"));
	}
	
	string ApretarTecla(int i){
		teclas[i].Apretar();
		return teclas[i].VerNota();
	}
	
	void ApretarTecla(int i){
		teclas[i].Soltar();
	}
	
};

int main() {
	
	return 0;
}

