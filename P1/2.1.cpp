#include <iostream>
using namespace std;

class Cilindro{

private:
	float radio=0;
	float altura=0;

public:
	Cilindro(){};
	void AsignarDatos(float x,float y){
		radio=x;
		altura=y;
	}
	int ObtenerVolumen(){
		return 3.14*radio*radio*altura;

	}
	~Cilindro(){};
};




int main() {
	Cilindro c1,c2;
	float radio;
	float altura;
	
	cout<<"Ingrese el radio de c1"<<endl;
	cin>>radio;
	cout<<"Ingrese la altura de c1"<<endl;
	cin>>altura;
	
	
	c1.AsignarDatos(radio,altura);
	
	cout<<"El volumen de c1 es de "<<c1.ObtenerVolumen()<<endl;
	
	
	c2.AsignarDatos(5.3,10.2);
	cout<<"El volumen de c2 es de "<<c2.ObtenerVolumen()<<endl;
	
	return 0;
}

