#include <iostream>
using namespace std;

class Envase{
protected:
	int volumen;
	int peso;
public:
	Envase(int peso){this->peso=peso;}
	void AsignarPeso(int peso){this->peso=peso;}
	virtual void CalcularVolumen()=0;
	int VerVolumen(){return volumen;}
	int VerPeso(){return peso;}
};

class Lata:public Envase{
private:
	int radio;
	int altura;
public:
	Lata(int radio,int altura,int peso):Envase(peso){
		this->radio=radio;
		this->altura=altura;
	}
	void CalcularVolumen()override{
		volumen=altura*(3.14*radio*radio);
	}
};


class Caja:public Envase{
private:
	int largo,ancho,alto;
public:
	Caja(int largo,int ancho,int alto,int peso):Envase(peso){
		this->largo=largo;
		this->ancho=ancho;
		this->alto=alto;
	}
	
	void CalcularVolumen()override{
		volumen=largo*ancho*alto;
	}
};

int main() {
	
	Envase *p;
	
	p=new Lata(3.3,2,10);
	
	p->CalcularVolumen();
	
	cout<<p->VerVolumen()<<endl;
	cout<<p->VerPeso()<<endl;
	
	p=new Caja(2,3,4,9);
	p->CalcularVolumen();
	cout<<p->VerVolumen()<<endl;
	cout<<p->VerPeso()<<endl;
	
	
	
	return 0;
}

