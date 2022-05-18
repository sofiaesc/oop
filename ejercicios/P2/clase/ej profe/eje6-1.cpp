#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct par{
	int ent;
	float flo;
};


int main() {
	fstream f;
	par aux;
	/*f.open("datos.dat",ios::in|ios::out|ios::binary|ios::trunc);
	srand(time(0));
	for(int i=0;i<20;i++) { 
		aux.ent=rand()%100;
		aux.flo=rand()%100+rand()%100/100.0;
		f.write((char*)&aux,sizeof(aux));
	}
	f.close();
	*/
	f.open("datos.dat",ios::in|ios::out|ios::binary);
	f.seekg(0,ios::end);
	int cant=f.tellg()/sizeof(par);
	f.seekg(0,ios::beg);
	for(int i=0;i<cant;i++) { 
		f.read((char*)&aux,sizeof(aux));
		cout<<i<<") "<<aux.ent<<"   "<<aux.flo<<endl;
	}
	
	int pos;
	cout<<"ingrese pos:"; cin>>pos;
	f.seekg(pos*sizeof(par),ios::beg);
	cout<<"posicion antes"<<f.tellg()<<endl;
	aux.ent=999;
	aux.flo=123.456;
	f.write((char*)&aux,sizeof(aux));
	cout<<"posicion actual"<<f.tellg()<<endl;
	f.seekg(20,ios::cur);
//	f.read((char*)&aux,sizeof(aux));
//	cout<<aux.ent<<"   "<<aux.flo<<endl;
	cout<<"posicion nuevo"<<f.tellg()<<endl;
	
	
	
	
	
	
	
	f.close();
	
	
	
	
	
	return 0;
}

