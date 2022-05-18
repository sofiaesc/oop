#include <iostream>
#include <vector>
using namespace std;

class Persona{
	string nombre;
	int dni;
public:
	void IngresarDatos(string x,int y){nombre=x;dni=y;}
	string VerNombre(){return nombre;}
};

class Alumno:public Persona{
	float promedio;
public:
	//Alumno(string x,int y,float z){nombre=x;dni=y;promedio=z;}
	void Datos(string x,int y, float z){IngresarDatos(x,y);promedio=z;}
	void IngresarPromedio(float x){promedio=x;}
	float VerPromedio(){return promedio;}
};

class Docente:public Persona{
	int ingreso;
public:
	void Datos(string x,int y, int z){IngresarDatos(x,y);ingreso=z;}
	int VerIngreso(){return ingreso;}
};

class Curso{
	string materia;
	Docente D;
	vector<Alumno>A;
public:
	Curso(string x,Docente y){materia=x;D=y;}
	int VerCant(){return A.size();}
	//void AgregarDocente(Docente x){D=x;}
	void AgregarAlumno(Alumno x){A.push_back(x);}
	Alumno VerAlumno(int x){return A.at(x);}
	string VerMateria(){return materia;}
	Docente VerDocente(){return D;}
	float Promedio();
};

float Curso::Promedio(){
	float s=0;
	for(unsigned int i=0;i<A.size();i++){
		s=s+A[i].VerPromedio();
	}
	return s/A.size();
}

int main(){
	Docente D;
	D.Datos("Manuel",1976,2010);
	Curso x("POO2019",D);

	Alumno a,b,c,d,e,f;
	a.Datos("Juancito",2005,8);
	b.Datos("Ana",2001,7);
	c.Datos("Gime",2000,9);
	d.Datos("Perón",1978,10);
	e.Datos("Eva",2020,6);
	f.Datos("Laura",2031,4);
	
	x.AgregarAlumno(a);
	x.AgregarAlumno(b);
	x.AgregarAlumno(c);
	x.AgregarAlumno(d);
	x.AgregarAlumno(e);
	x.AgregarAlumno(f);
	
	cout<<"el curso tiene "<<x.VerCant()<<" alumnos."<<endl;
	cout<<"el alumno "<<a.VerNombre()<<" tiene promedio de "<<a.VerPromedio()<<endl;
	cout<<"el alumno "<<b.VerNombre()<<" tiene promedio de "<<b.VerPromedio()<<endl;
	cout<<"el docente "<<D.VerNombre()<<" ingresó en "<<D.VerIngreso()<<endl<<endl;
	
	for(int i=0;i<x.VerCant();i++){
		cout<<x.VerAlumno(i).VerNombre()<<": "<<x.VerAlumno(i).VerPromedio()<<endl;
	}
	
	cout<<"El promedio del curso es "<<x.Promedio()<<endl;
	
	return 0;
}

