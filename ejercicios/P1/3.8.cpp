#include <iostream>
using namespace std;

class Tanque{
protected:
	float volumen,peso;
public:
	void AsignarPeso(float x){peso=x;}
	virtual void CalcularVolumen()=0;
	float VerVolumen(){return volumen;}
	float VerPeso(){return peso;}
	virtual ~Tanque(){}
	
};

class Cilindro : public Tanque{
	float radio,altura;
public:
	Cilindro(int r,int a){radio=r;altura=a;}
	void CalcularVolumen() override{
		volumen=3.14*radio*radio*altura;
	}
};

class Esfera : public Tanque{
	float radio;
public:
	Esfera(int r){radio=r;}
	void CalcularVolumen() override{
		volumen=(4/3)*3.14*radio*radio*radio;
	}
};

int main() {
	
	Tanque *e[2];
	
	e[0]=new Esfera(2);
	e[1]=new Cilindro(1,10);
	
	for(int i=0;i<2;i++) { 
		(*e[i]).CalcularVolumen();
		cout<<e[i]->VerVolumen()<<endl;
	}
	
	delete e[0];
	delete e[1];
	
	return 0;
}

