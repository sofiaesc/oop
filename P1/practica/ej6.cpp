#include <iostream>
using namespace std;

class Cilindro{
private:
	int radio;
	int altura;
public:
	Cilindro(int rad,int alt):radio(rad),altura(alt){};
	void Cargar(int r,int a){
		
		radio=r;
		altura=a;
		
	
	}
	int ObtenerVolumen(){return radio*altura;}
	int VerRadio(){return radio;}
	int VerAltura(){return altura;}
	
	
	int operator[](int i)const{
		
		if(i==0){
			return radio;
		}else{
			if(i==1){
				return altura;
			}
		}
	}
	int& operator[](int i){
		
		if(i==0){
			return radio;
		}else{
			if(i==1){
				return altura;
			}
		}
	}
	
	bool operator>(Cilindro &c){
		
		return (ObtenerVolumen()==c.ObtenerVolumen());
	}
	
};

istream &operator>>(istream &i, Cilindro &c){
	int a,b;
	i>>a>>b;
	
	c.Cargar(a,b);
	
	return i;
}




int main() {
	
	return 0;
}

