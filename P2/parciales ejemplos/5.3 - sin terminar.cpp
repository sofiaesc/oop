#include <iostream>
#include <fstream>
using namespace std;

struct alumno{
	char nombre[15];
	char apellido[15];
	int nota1,nota2,nota3;
	long dni;
};

void agregar_en_orden(alumno al_nuevo){
	
	ifstream archi("CURSO.DAT",ios::binary|ios::in|ios::ate);
	int t=archi.tellg()/sizeof(alumno);
	int pos;
	long dni_anterior=99999999;
	for(int i=0;i<t;i++){
		alumno x;
		archi.read(reinterpret_cast<char*>(&x),sizeof(x));
		if (al_nuevo.dni>=dni_anterior && al_nuevo.dni<=x.dni){
			pos=i;
			break;
		}
		dni_anterior=x.dni;
	}
	
	archi.close();
	int t_pos=pos*sizeof(alumno);
	
	fstream archi2("CURSO.DAT",ios::binary|ios::in|ios::out);
	archi2.seekp(t_pos);
	archi2.write(reinterpret_cast<char*>(&al_nuevo),sizeof(al_nuevo));
}

int main() {
	
	
	return 0;
}

