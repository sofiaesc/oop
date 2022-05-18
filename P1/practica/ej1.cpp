#include <iostream>
using namespace std;

class Fecha{
	int dia,mes,anio;
public:
	Fecha(int d,int m,int a) : dia(d),mes(m),anio(a){}
	int VerDia(){return dia;}
	int VerMes(){return mes;}
	int VerAnio(){return anio;}
	void Cargar(int d,int m,int a){dia=d;mes=m;anio=a;}
	
	bool operator<=(Fecha &f){
		int f1=anio*10000+mes*100+dia;
		int f2=f.VerAnio()*10000+mes*100+dia;
		return (f1>=f2);
	}
	
	int operator[](int i)const{
		if (i==1){return dia;}
		if (i==2){return mes;}
		if (i==3){return anio;}
	}
		
	int &operator[](int i){
		if (i==1){return dia;}
		if (i==2){return mes;}
		if (i==3){return anio;}
	}	
};

istream &operator>>(istream &i, Fecha &f){
	int d,m,a;
	i>>d>>m>>a;
	f.Cargar(d,m,a);
	return i;
}

int main() {
	
	Fecha j(28,00,2001);
	Fecha r(00,00,0000);
	
	cin>>r;
	j[2]=06;
	cout<<j[2];
	
	if (j<=r){cout<<"ggg";}
	
	return 0;
}

