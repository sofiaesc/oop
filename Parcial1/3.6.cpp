#include <iostream>
using namespace std;

class Fraccion{
protected:
	int numerador, denominador;
	
public:
	void asignar(int n,int d){ numerador=n; denominador=d;}
	int ver_numerador(){return numerador;}
	int ver_denominador(){return denominador;}
	double convertiradoble(){return (double)numerador/(double)denominador;}
	
};

class NumeroMixto{
	int entero;
	Fraccion impropia;
public:
	NumeroMixto(int e,int n,int d){entero=e;impropia.asignar(n,d);}
	NumeroMixto(int e,int d){entero=e/d; impropia.asignar(e%d,d);}
	int ver_entero(){return entero;}
	int ver_numerador_imp(){return impropia.ver_numerador();}
	int ver_denominador_imp(){return impropia.ver_denominador();}
	double convertiradoble(){return (entero+impropia.convertiradoble());}
};

int main() {
	
	NumeroMixto Num(7,4);
	Num.convertiradoble();
	
	return 0;
}

