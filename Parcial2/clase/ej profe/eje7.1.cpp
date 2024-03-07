#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
struct Persona{
	string nombre;
	string apellido;
	int dni;
};

bool cmp_nombre(const Persona &x1, const Persona &x2) {
	return x1.nombre < x2.nombre;
}
bool cmp_apellido(const Persona &x1, const Persona &x2) {
	return x1.apellido < x2.apellido;
}
bool cmp_dni(const Persona &x1, const Persona &x2) {
	return x1.dni < x2.dni;
}


template<class T, class U>
T mayor(vector<T> &x, U puntFunc){
	T m=x[0];
	for(int i=1;i<x.size();i++) {
		if (puntFunc(m,x[i])) m=x[i];
	}
	return m;
}
	

template<class T>
T mayor(vector<T> &x){
	T m=x[0];
	for(int i=1;i<x.size();i++) {
		if (m<x[i]) m=x[i];
	}
	return m;
}

	
	
int main() {
	vector <int> v;
	vector <float> w;
	vector <string> s;
	string l;
	srand(time(0));
	for(int i=0;i<10;i++) { 
		v.push_back(rand()%100);
		w.push_back(rand()%10+rand()%100/100.0);
		
		string cad="";
		for(int i=0;i<5;i++){
			l= char(rand()%26+65);
			cad=cad+l;
		}
		s.push_back(cad);
	}
	for(int i=0;i<10;i++) cout<<setw(7)<<v[i];
	cout<<endl;
	for(int i=0;i<10;i++) cout<<setw(7)<<w[i];
	cout<<endl;
	for(int i=0;i<10;i++) cout<<setw(7)<<s[i];
	cout<<endl;
	cout<<"\nMayor int: "<< mayor<int>(v);
	cout<<"\nMayor float: "<< mayor<float>(w);
	cout<<"\nMayor string: "<< mayor<string>(s)<<endl<<endl;

		
	vector<Persona> vp;
	Persona p;
	for(int i=0;i<10;i++) { 
		for(int i=0;i<5;i++){
			l= char(rand()%26+97);
			p.nombre=p.nombre+l;
			l= char(rand()%26+65);
			p.apellido=p.apellido+l;
		}
		p.dni=1219*(rand()%20000)+20000000;
		vp.push_back(p);
		p.nombre=""; p.apellido="";
		cout<<vp[i].nombre<<"  "<<vp[i].apellido<<"  "<<vp[i].dni<<endl;
	}
	p= mayor<Persona>(vp,cmp_apellido);
	cout<<"\nMayor apellido: "<< p.apellido <<endl;
	p= mayor<Persona>(vp,cmp_nombre);
	cout<<"Mayor nombre: "<< p.nombre <<endl;
	p= mayor<Persona>(vp,cmp_dni);
	cout<<"Mayor dni: "<< p.dni <<endl;
	
	
	return 0;
}

