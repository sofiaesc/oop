#include <iostream>
using namespace std;

class Racional{
	int num,den;
public:
	Racional(int n,int d) : num(n), den(d){}
	int VerNum() const{return num;}
	int VerDen() const{return den;}	
	void CargarNumerador(int num){this->num=num;}
	void CargarDenominador(int den){this->den=den;}
	
	Racional &operator++(){
		this->num+=this->den;
		return *this;
	}
	
	Racional operator++(int){
		Racional aux=*this;
		this->num+=this->den;
		return aux;
	}
	
	Racional operator+(Racional r){
		Racional suma(this->VerNum()*r.VerDen()+r.VerNum()*this->VerDen(),this->VerDen()*r.VerDen());
		return suma;
	}
	
	Racional operator*(Racional r){
		Racional producto(this->VerNum()*r.VerNum(),this->VerDen()*r.VerDen());
		return producto;
	}
	
	bool operator>(Racional r) {
		if (this->VerNum()/this->VerDen()>r.VerNum()/r.VerDen()){
			return true;
		}else{
			return false;
		}
	}
	
};

ostream &operator<<(ostream &o,Racional r) {
	o << r.VerNum() << "/" << r.VerDen();
	return o;
}

istream &operator>>(istream &i,Racional &r) {
	float a;
	i>>a;
	r.CargarNumerador(a);
	float b;
	i>>b;
	r.CargarDenominador(b);
	return i;
}


int main() {
	Racional a(3,5), b(2,3),c(0,1);
	c=a+b;
	cout<<c.VerNum()<<" "<<c.VerDen()<<endl;
	c=a*b;
	c=a+b+c;
	c=a*b*c;
	b=c++;
	a=++c;
	
	Racional d(0,0);
	cin>>d;
	cout<<d<<endl;
	
	if (a>b){
		cout<<a<<" es mayor que "<<b<<endl;
	}else{
		cout<<b<<" es mayor que "<<a<<endl;
	}
	
	cout<<a.VerNum()<<" "<<a.VerDen()<<endl;
	cout<<b.VerNum()<<" "<<b.VerDen()<<endl;
	
	return 0;
}

