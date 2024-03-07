#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
struct alum{
	string n;
	int a,b;
};

void modifica(alum x);

void modifica(string x, int y, int z){
	alum aux;
	aux.n=x;
	aux.a=y;
	aux.b=z;
	modifica(aux);
}

void modifica(alum x){
	vector<alum> v;
	alum r;
	ifstream ent("lista.txt");
	while (getline(ent,r.n) && ent>>r.a>>r.b){
		if (r.n==x.n){
			r.a=x.a;
			r.b=x.b;
		}
		v.push_back(r);
		ent.ignore();
	}
	ent.close();
	ofstream sal("lista.txt",ios::out);
	for(int i=0;i<v.size();i++) {
		sal<<v[i].n<<endl<<v[i].a<<"  "<<v[i].b<<endl;
	}
	sal.close();
}

void promedio(){
	ifstream ent("lista.txt");
	ofstream sal("promedio.txt");
	string n;
	int a,b;
	while(getline(ent,n) && ent>>a>>b){
		float p=(a+b)/2.0;
		string co;
		if(p>=70) co="promocionado";
		else if (p>=40) co="regular";
			 else co="libre";
		sal<<n<<":  "<<p<<"   "<<co<<endl;
		ent.ignore();
	}
	ent.close();
	sal.close();
}
	


int main() {
	
	alum aux;
	aux.n="lopez luis";
	aux.a=61;
	aux.b=33;
	modifica(aux);
	
	modifica ("perez juan",34,8);
	
	promedio();
	return 0;
}

