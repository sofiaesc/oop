#include <iostream>
using namespace std;

class Envase{
protected:
	float volumen,peso;
public:
	Envase(float v,float p) : volumen(v),peso(p){}
	void AsignarPeso(int p){peso=p;}
	virtual void CalcularVolumen()=0;
	float VerVolumen(){return volumen;}
	float VerPeso(){return peso;}
	virtual ~Envase(){}
};

class Lata : public Envase{
	float radio,altura;
public:
	Lata(float r,float a,float p) : Envase(0,p){radio=r;altura=a;}
	void CalcularVolumen() override{
		volumen=3.14*radio*radio*altura;
	}
};

class Caja : public Envase{
	float largo, ancho, alto;
public:
	Caja(float l,float an,float al,float p) : Envase(0,p){largo=l;ancho=an;alto=al;}
	void CalcularVolumen() override{
		volumen=largo*ancho*alto;
	}
};


int main() {
	
	Envase *e=new Lata(2,2,10);
	e->CalcularVolumen();
	cout<<e->VerVolumen()<<endl;
	
	e=new Caja(2,2,2,4);
	e->CalcularVolumen();
	cout<<e->VerVolumen()<<endl;
	
	delete e;
	
	return 0;
}

*p
	


