#include <iostream>
#include <list>
#include <algorithm>
#include <sstream>
using namespace std;


struct FichaMedico{
	string nomMedico;
	list<int> dniPacientes;
};
class Clinica{
protected:
	FichaMedico f[20];
	int largo;
public:
	Clinica(){ largo =6;
	f[0].nomMedico= "Peralta Rudecinda";
	f[1].nomMedico="Mayo Juan";
	f[2].nomMedico="Carnero Juan";
	f[3].nomMedico="Perez Joaquin";
	f[4].nomMedico="Barcelo Carlos";
	f[5].nomMedico="Rodrigues Ramona";
	for(int k=0;k<6;k++)
		f[k].dniPacientes.resize(10);
	}
	//------------------------------------------------
	string mostrar(){
		stringstream s;
		for (int x=0; x< largo; x++)
			s<<x+1<<" Medico: "<< f[x].nomMedico <<endl;
		return s.str();
	}
	//-------------------------------------------------
	string mostrarPaciente(int nm){
		list<int>::iterator it;
		int x=0;
		stringstream s;
		s<<nm<<" Medico: "<< f[nm].nomMedico <<endl;
		it= f[nm-1].dniPacientes.begin();
		while(it != f[nm-1].dniPacientes.end()){
			if(*it!=0)
				s<<*it<<endl;
			else
				s<<"-----------"<<endl;
			it++;
		}//while
		return s.str();
	}
		//-------------------------------------------------
	void modMedico(int nm, char *nomb){
			f[nm-1].nomMedico.clear();//borro nombre viejo
			f[nm-1].nomMedico += nomb;//agrego nombre nuevo
	}
			//-------------------------------------------------
	void agrPaciente(int nm, long num_dni){
		f[nm-1].dniPacientes.push_back(num_dni);//agrego dni al final
	}
				//-------------------------------------------------
	void modPaciente(int nm, long np, long dnip){//Numero de medico, dniP viejo, dniP nuevo
		list<int>::iterator it,principio, fin;
		principio= f[nm-1].dniPacientes.begin();
		fin= f[nm-1].dniPacientes.end();
		it= find( principio, fin, np);//busco y borro nombre viejo
		if(it != f[nm-1].dniPacientes.end())
			*it= dnip;//modifico valor
	}
};//Class Clinica
//**********************************************************
int main(int argc, char *argv[]) {
	Clinica C;
	int nummed;
	char op;
	while (op!='0'){
		system("cls");
		cout<<" MENU DE OPCIONES"<<endl<<endl;
		cout<<"1 - MODIFICACIONES DATOS DE MEDICOS."<<endl;
		cout<<"2 - ALTA DE PACIENTES."<<endl;
		cout<<"3 - MODIFICACIONES DE PACIENTES."<<endl;
		cout<<"4 - LISTADO DE MEDICOS."<<endl;
		cout<<"5 - LISTADO DE PACIENTES POR MEDICO."<<endl;
		cout<<"6 - GUARDAR FICHAS EN DISCO."<<endl;
		cout<<"7 - RECUPERAR FICHAS DESDE DISCO."<<endl<<endl;
		cout<<"0 - SALIR"<<endl<<endl;
		cout<<"Ingrese su opcion: "; cin>> op;
		switch (op){
			case '1':{system("cls");
				cout<<"Ingrese numero de medico (1 - 6): ";
				cin>>nummed;
				cout<<"Medico ("<<nummed<<"): "<<endl;
				cout<<"Reingrese el nombre del medico: ";
				char nombre[30];
				cin.ignore();
				cin.getline(nombre,50);
				C.modMedico(nummed, nombre);
				break;};
			case '2':{cout<<"Ingrese numero de medico (1 - 6): ";
				cin>>nummed;
				cout<<"Medico ("<<nummed<<"): "<<endl;
				cout<<"Ingrese el DNI del paciente: ";
				long num_dni;
				cin>>num_dni;
				C.agrPaciente(nummed, num_dni);
				break;};
			case '3':{cout<<"Ingrese numero de medico (1 - 6): ";
				cin>>nummed;
				cout<<"Medico ("<<nummed<<"): "<<endl;
				cout<<"Ingrese el DNI del paciente: ";
				long num_dni;
				cin>>num_dni;
				//f[nummed-1].dni.push_back(num_dni);//agrego dni al final
				C.agrPaciente(nummed,num_dni);
			break;};
			case '4':{cout<<C.mostrar()<<endl;
				system("pause");
				break;};
			case '5':{system("cls");
				cout<<"Ingrese numero de medico (1 - 6): ";
				cin>>nummed;
				cout<<C.mostrarPaciente(nummed)<<endl;
				system("pause");
				break;};
		};//del switch
	};//del while
	return 0;
}//
