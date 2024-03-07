#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Gestion{
	vector<string>v;
	string nombre_archivo;
public:
	Gestion(string nom_arch){
		ifstream archi1(nom_arch,ios::in);
		nombre_archivo=nom_arch;
		string s1,s2,nom_p;
		while(archi1>>s1>>s2){
			if (s2.substr(1,1)>s1.substr(1,1)){
				nom_p=s1+" "+s2;
			}
			if (s1.substr(1,1)>s2.substr(1,1)){
				nom_p=s2+" "+s1;
			}
			v.push_back(nom_p);
		}
		archi1.close();
	}
	void Ordenar(){
		auto it = unique(v.begin(),v.end());
		v.erase(it);
		sort(v.begin(),v.end());
	}
	void Guardar(){
		ofstream archi2(nombre_archivo,ios::in|ios::out);
		for(unsigned int i=0;i<v.size();i++) { 
			archi2.write(reinterpret_cast<char*>(&(v[i])),sizeof(v[i]));
		}
		archi2.close();
	}
};

int main() {
	
	ofstream archi3("personitas.txt");
	string a="Sofia ESCUDERO",b="PORTA Rocio",c="LEPEZ Juliana",d="Agustina BORSATTI",e="Rocio PORTA";
	archi3<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl;
	archi3.close();
	Gestion g("personitas.txt");
	
	cout<<endl<<endl;
	g.Ordenar();
	
	return 0;
}

