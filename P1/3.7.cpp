#include <iostream>
#include <vector>
using namespace std;

class Tecla{
	string nombre;
	bool estado;
public:
	Tecla(string tecla){nombre=tecla;estado=false;}
	string VerNota(){return nombre;}
	void Apretar(){estado=true;}
	void Soltar(){estado=false;}
	bool EstaApretada(){
		if (estado==true){
			return true;
		}else{
			return false;
		}
	}
};


class Pedal{
	float presion;
public:
	Pedal(){presion=0;}
	void ModificarPresion(float x){presion=x;}
	float VerPresion(){return presion;}
};


class Instrumento{
public:
	virtual string VerTipo(){return "sin_nombre";}
};


class Piano : public Instrumento{
	vector<Tecla>t;
	Pedal p;
public:
	Piano() : p() {
		Tecla t0("do");
		Tecla t1("re");
		Tecla t2("mi");
		Tecla t3("fa");
		Tecla t4("sol");
		Tecla t5("la");
		Tecla t6("si");
		t.push_back(t0);
		t.push_back(t1);
		t.push_back(t2);
		t.push_back(t3);
		t.push_back(t4);
		t.push_back(t5);
		t.push_back(t6);}
	
	string ApretarTecla(int x){
		t[x].Apretar();
		return t[x].VerNota();
	}
	
	void SoltarTecla(int x){
		t[x].Soltar();
	}
	
	void PresionarPedal(int x){
		p.ModificarPresion(x);
	}
	
};


int main() {
	
	return 0;
}

