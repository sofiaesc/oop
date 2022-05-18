#include <iostream>
#include <string>
using namespace std;

class Persona {
	
private:
	string apellido,nombre,estcivil;
	int dni,fechanac;
	
protected:
	int diferenciaAnios(int fAct,int fAnt){
		return(fAct-fAnt)/1000;
	}
	
public:
	
	Persona(string apellido,string nombre,int dni, int fechanac,string estcivil){
		this->apellido=apellido;
		this->nombre=nombre;

		this->dni=dni;
		this->fechanac=fechanac;
		this->estcivil=estcivil;
	}
	int Edad(int fechahoy){
		return diferenciaAnios(fechahoy,fechanac);
	}
	string ObtenerNombre(){
		return nombre;
	}
	string ObtenerEstCivil(){
		return estcivil;
	}
	string ObtenerApellido(){
		return apellido;
	}
	int ObtenerDNI(){
		return dni;
	}
	int ObtenerFechaNac(){
		return fechanac;
	}
	void modificarEstCivil(string estado){
		estcivil=estado;
	}
};

class Alumno : public Persona {
	int promedio;
	int aprobadas;
public:
	
	Alumno(string apellido,string nombre,int dni, int fechanac,string estcivil,int promedio,int aprobadas) : Persona(apellido,nombre,dni,fechanac,estcivil){
		this->promedio=promedio;
		this->aprobadas=aprobadas;
	}
	
	int MeritoAcademico(){
		return promedio*aprobadas;
	}
};

class Docente : public Persona {
	int ingreso;
public:
	int Antiguedad(int fechahoy){
		return diferenciaAnios(fechahoy,ingreso);
	}
	Docente(string apellido,string nombre,int dni, int fechanac,string estcivil, int ingreso) : Persona(apellido,nombre,dni,fechanac,estcivil){
		this->ingreso=ingreso;
	}
};

class Curso{
	string nombre;
	Docente profesor;
	vector<alumno>alumnos;
public:
	void AgregarAlumno(Alumno nuevo);
	Alumno MejorAlumno();
};

void AgregarAlumno(Alumno nuevo){
	
}

int main() {
	
	Alumno a("APE","NOM",42870783,20001218,"SOLT",9.75,12);
	
	return 0;
}

