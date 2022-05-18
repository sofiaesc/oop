#include <iostream>
#include <vector>
using namespace std;

struct FichaMedico{
	string nombreMedico;
	vector<long> dniPacientes;
};

class Clinica{
	vector<FichaMedico> Medicos;
public:
	Clinica(string n1,string n2,string n3,string n4,string n5, string n6){
		Medicos.resize(7);
		Medicos[1].nombreMedico=n1;
		Medicos[2].nombreMedico=n2;
		Medicos[3].nombreMedico=n3;
		Medicos[4].nombreMedico=n4;
		Medicos[5].nombreMedico=n5;
		Medicos[6].nombreMedico=n6;
	}
	void NuevoPaciente(int i,long dni){
		Medicos[i].dniPacientes.push_back(dni);
	}
	void ListarPacientes(){
		for(unsigned int i=1;i<Medicos.size();i++){
			cout<<"MEDICO: "<<Medicos[i].nombreMedico<<endl<<endl;
			
			for(unsigned int j=0;j<Medicos[i].dniPacientes.size();j++) { 
				cout<<"PACIENTES: "<<endl<<Medicos[i].dniPacientes[j]<<endl;
			}
		}
	}
	void EliminarPaciente(long dni){
		for(unsigned int i=1;i<Medicos.size();i++){
			for(unsigned int j=0;j<Medicos[i].dniPacientes.size();j++) { 
				if(Medicos[i].dniPacientes[j]==dni){
					auto it=Medicos[i].dniPacientes.begin()+i+1;
					Medicos[i].dniPacientes.erase(it);
				}
			}
		}
	}
};

int main() {
	
	return 0;
}

