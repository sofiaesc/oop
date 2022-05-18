#include <iostream>
#include <vector>
using namespace std;

class Persona{
private:
	static int p;
	string nombre;
public:
	Persona(string n):nombre(n){}
	virtual string Saludar()=0;	
	string VerNombre(){return nombre;}
	virtual ~Persona(){}
};

class Alumno:public Persona{
	
	string carrera;
public:
	Alumno(string n,string c):Persona(n){
		carrera=c;
	}
	string Saludar(){
		
		string saludo="Soy "+VerNombre()+" y pertenezco a la carrera "+carrera;
		return saludo;
	}
};


class Docente:public Persona{
private:

	string materia;
public:
	Docente(string n,string m):Persona(n){
		materia=m;
	}
	string Saludar(){
		
		string saludo="Mi nombre es "+VerNombre()+" y dicto "+materia;
		
		return saludo;
	}


};


int main() {
	vector<Persona*>jeje;
	
	jeje.push_back(new Docente("Estela","MALA"));
	
	for(int i=0;i<24;i++) { 
		jeje.push_back(new Alumno("Rambo","Capo"));
	}
	
	for(int i=0;i<25;i++) { 
		cout<<jeje[i]->Saludar()<<endl;
	}
	
	for(int i=0;i<25;i++) { delete[] jeje[i]; }
	
	return 0;
}

