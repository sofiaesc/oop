#include <iostream>
#include <vector>
using namespace std;

class Animal{
private:
	string tipo;
	string especie;
	
public:
	Animal(string tipo, string especie){
		this->tipo=tipo;
		this->especie=especie;
	}
	virtual void desplazarse()=0;
	
	string VerTipo(){
		return tipo;
	}
	string VerEspecie(){
		return especie;
	}
};

class Mamifero:public Animal{

public:
	Mamifero(string especie) : Animal("Mamifero",especie){
	}
		
		
	void desplazarse()override{
		cout<<"Camina ";
	}
	
};

class Ave:public Animal{
public:
	Ave(string especie) : Animal("Ave",especie){
	}
	
	void desplazarse()override{
		cout<<"Vuela ";
	}
	
};

class Pez:public Animal{
public:
	Pez(string especie) : Animal("Pez",especie){
	}
	
	void desplazarse()override{
		cout<<"Nada ";
		
	}
	
};

int main() {
	
	vector<Animal*>Parque;
	
	
	for(int i=0;i<30;i++) { 
		
		Parque.push_back(new Mamifero("Perro"));
		Animal *a =Parque[i];
		cout<<a->VerTipo();;
		cout<<(*a).VerEspecie()<<endl;
	}
	
	
	
	
	
	return 0;
}

