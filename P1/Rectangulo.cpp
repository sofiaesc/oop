#include <iostream>
using namespace std;

class Rectangulo{
private:
	int base;
	int altura;
public:
	Rectangulo(int x,int y){base=x;altura=y;}
	Rectangulo(int x1,int y1,int x2,int y2){
		altura=abs(y1-y2);
		base=abs(x1-x2);
	}
	
	int VerArea(){
		return base*altura;
	}
	int VerPerimetro(){
		return base*2+altura*2;
	}
	
	bool EsCuadrado(){
		if(base==altura){
		return true;}
		
		return false;
	}
};



int main() {
	
	cout<<"Ingrese la base "<<endl;
	int base;
	cin>>base;
	cout<<"Ingrese la altura "<<endl;
	int altura;
	cin>>altura;
	
	Rectangulo a(base,altura);
	
	cout<<"El area es "<<a.VerArea()<<endl;
	cout<<"El perimetro es "<<a.VerPerimetro()<<endl;
	
	if(a.EsCuadrado()==true){
		cout<<"Es cuadrado!!! "<<endl;
	}else{
		cout<<"No es cuadrado!! "<<endl;
	}
	
	return 0;
}

