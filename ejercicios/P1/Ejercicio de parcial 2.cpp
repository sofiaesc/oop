#include <iostream>
#include <vector>
using namespace std;
class Persona{
protected:
	string nombre;
public:
	Persona(string nombre){this->nombre=nombre;}
	virtual void Saludar()=0;
	virtual ~Persona(){}
};

class Alumno:public Persona{
private:
	string carrera;
public:
	Alumno(string nombre,string carrera):Persona(nombre){
		this->carrera=carrera;
	}
	void Saludar()override{
		cout<<"Soy "<<nombre<<" y pertenezco a "<<carrera<<endl;
	}
	
};

class Docente:public Persona{
private:
	string materia;
public:
	Docente(string nombre,string materia):Persona(nombre){
		this->materia=materia;
	}
	void Saludar()override{
		cout<<"Mi nombre es "<<nombre<<" y dicto "<<materia<<endl;;
	}
};


int main() {
	vector<Persona*>Clase;
	
	Clase.push_back(new Docente("POCHIIII","SOCIOOOO"));
	string nombre,carrera;
	
	for(int i=0;i<6;i++) { 
		cout<<"Ingrese el nombre"<<endl;
		getline(cin,nombre);
		cout<<endl;
		cout<<"Ingrese la carrera "<<endl;
		getline(cin,carrera);
		cout<<endl<<endl;
		
		Clase.push_back(new Alumno(nombre,carrera));
	}

	
	for(int i=0;i<6;i++) { 
		Persona *a=Clase[i];
		a->Saludar();
	}
	
	for(int i=0;i<6;i++) { 
		delete Clase[i];
	}
	
	
	
	return 0;
}

