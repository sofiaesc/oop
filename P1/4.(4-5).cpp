#include <iostream>
using namespace std;

class Complejo{
	int real;
	int imag;
public:
	Complejo(int r,int i) : real(r), imag(i){}
	int VerParteReal(){return real;}
	int VerParteImaginaria(){return imag;}
	void CargarParteReal(int r){real=r;}
	void CargarParteImaginaria(int i){imag=i;}
	
	Complejo operator+(Complejo r){
		Complejo suma(this->real+r.VerParteReal(),this->imag+r.VerParteImaginaria());
		return suma;
	}
	
	Complejo operator-(Complejo r){
		Complejo resta(this->real-r.VerParteReal(),this->imag-r.VerParteImaginaria());
		return resta;
	}
	
	Complejo operator*(Complejo r){
		int auxr=this->VerParteReal()*r.VerParteReal()-this->VerParteImaginaria()*r.VerParteImaginaria();
		int auxi=this->VerParteReal()*r.VerParteImaginaria()+this->VerParteImaginaria()*r.VerParteReal();
		Complejo producto(auxr,auxi);
		return producto;
	}
	
	bool operator==(Complejo r){
		if (this->VerParteReal()==r.VerParteReal() && this->VerParteImaginaria()==r.VerParteImaginaria()){
			return true;
		} else {
			return false;
		}
	}
	
	int operator[](int i) const{
		if(i==0){ 
			return real;
		} else{
			return imag;
		}
	}
	
	int& operator[](int i){
		if(i==0){
			return real;
		} else{
			return imag;
		}
	}
	
};

istream &operator>>(istream &i, Complejo &c){
	float a;
	i>>a;
	c.CargarParteReal(a);
	float b;
	i>>b;
	c.CargarParteReal(b);
	return i;
}

ostream &operator<<(ostream &o, Complejo c){
	o<<c.VerParteReal()<<" + "<<c.VerParteImaginaria()<<"i";
	return o;
}


int main() {
	
	Complejo c(1,2);
	cout<<"Parte real: "<<c[0]<<endl;
	cout<<"Parte imag:"<<c[1]<<endl;
	
	return 0;
}

