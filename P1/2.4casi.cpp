#include <iostream>
using namespace std;

struct Alumno{
	string nombre;
	float nota;
};

class Curso{
private:
	string materia;
	int cantidadAlumnos;
	Alumno *v;
public:
	Curso(){
		Alumno *v = new Alumno[cantidadAlumnos];
	}
	
	void agregarAlumno(string nom,float nota){
		Alumno a;
		a.nombre=nom;
		a.nota=nota;
	};
	
	float promedio(){
		
		float suma=0;
		
		for(int i=0;i<cantidadAlumnos;i++){
			suma= v[i].nota;
		}
		
		return suma/cantidadAlumnos;
	}
	
	void calfAlta(){
		int Alta;
		string nombre;
		
		for(int i=0;i<cantidadAlumnos;i++){
			if(v[i].nota>Alta){
				Alta=v[i].nota;
				nombre=v[i].nombre;
			}
		}
		
	}
	
	void agregarcantidadalumnos(int a){
		cantidadAlumnos=a;
	}
	
	Alumno copiarArreglo(){
		Alumno x[cantidadAlumnos]=v;
	}
	~Curso(){}
};



int main() {
	
	cout<<"Ingrese la cantidad de alumnos"<<endl;
	int n;
	cin>>n;
	
	Curso k;
	
	k.agregarcantidadalumnos(n);
	
	for(int i=0;i<n;i++){
		string nombrex;
		cout<<"Ingrese el nombre "<<endl;
		k.v[i].nombre=nombrex;
	}
	
	
	return 0;
}

