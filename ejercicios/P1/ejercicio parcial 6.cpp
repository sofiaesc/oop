#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Jugador{
	string nombre;
public:
	Jugador(string nombre){this->nombre=nombre;}
	virtual int Jugar()=0;
	virtual ~Jugador(){}
	string VerNombre(){return nombre;}
};

class JugadorIA : public Jugador{
public:
	JugadorIA() : Jugador("HAL 9000"){}
	int Jugar(){
		srand(time(0));
		return rand()%3+1;
	}
};

class JugadorHumano : public Jugador{
public:
	JugadorHumano(string nombre) : Jugador(nombre){}
	int Jugar(){
		int x;
		cout<<"Elija: piedra (1), papel (2) o tijera (3)"<<endl;
		cin>>x;
		cout<<endl;
		return x;
	}
};

string Juego(Jugador *j1,Jugador *j2){
	int a= j1->Jugar();
	int b= j2->Jugar();
	string r1="GANADOR: "+j1->VerNombre();
	string r2="GANADOR: "+j2->VerNombre();
	string r3="EMPATE";
	if (a==1){
		
		switch(b){
		case 1: return r3;
		case 2: return r2;
		case 3: return r1;
		}
	}
	if (a==2){
		switch(b){
		case 1: return r1;
		case 2: return r3;
		case 3: return r2;
		}
	}
	if (a==3){
		switch(b){
		case 1: return r2;
		case 2: return r1;
		case 3: return r3;
		}
	}
	return "Error";
}

int main() {
	
	vector<Jugador*>v;

	v.push_back(new JugadorHumano("Bastian qliao"));
	v.push_back(new JugadorHumano("Sofi linda"));
	
	Jugador *j1=v[0];
	Jugador *j2=v[1];
	
	cout<<Juego(j1,j2);
	
	for(int i=0;i<2;i++) { delete v[i]; }
	
	return 0;
}

