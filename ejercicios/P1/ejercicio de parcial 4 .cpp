#include <iostream>
using namespace std;

class Tanque{
protected:
	int volumen;
	int peso;
public:
	void AsignarPeso(int p){peso=p;}
	
	virtual void CalcularVolumen()=0;
	int VerVolumen(){return volumen;}
	int VerPeso(){return peso;}
};

class Cilindro:public Tanque{
	int radio;
	int altura;
public:
	Cilindro(int radio,int altura){this->radio=radio;this->altura=altura;}
	void CalcularVolumen(){
		volumen=3.14*radio*radio;
	}
};

class Esfera:public Tanque{
	int radio;
public:
	Esfera(int radio){
		this->radio=radio;
	}
	void CalcularVolumen(){
		volumen=4/3*3.14*radio*radio*radio;
	}
};

int main() {
	Tanque *p;
	
	p=new Cilindro(2,3);
	
	p->CalcularVolumen();
	cout<<p->VerVolumen()<<endl;
	p->AsignarPeso(2);
	cout<<p->VerPeso()<<endl;
	
	p=new Esfera(2);
	p->CalcularVolumen();
	cout<<p->VerVolumen()<<endl;
	p->AsignarPeso(5);
	cout<<p->VerPeso()<<endl;
	
	return 0;
}

