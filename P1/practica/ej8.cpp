#include <iostream>
using namespace std;

class Rectangulo{
	int base,altura;
public:
	Rectangulo(int b,int a) : base(b),altura(a){}
	int ObtenerArea(){return base*altura;}
	
	int operator[](int i)const{
		if(i==0){
			return base;
		}else{
			return altura;
		}
	}
	
	int &operator[](int i){
		if(i==0){
			return base;
		}else{
			return altura;
		}
	}
	
	bool operator<(Rectangulo &r){
		return (ObtenerArea()<r.ObtenerArea());
	}
	
	Rectangulo operator*(float x){
		float b=base*x;
		float a=altura*x;
		Rectangulo r(b,a);
		return r;
	}
	
};

int main() {
	
	return 0;
}

