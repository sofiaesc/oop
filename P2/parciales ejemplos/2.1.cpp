#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

class team_management{
	vector<string>v;
public:
	void generate_e_mail(){
		ifstream read_archive("team.txt");
		string x;
		while(getline(read_archive,x)){
			stringstream ss(x);
			string dni,last_name,name,e_mail;
			ss>>dni>>last_name>>name;
			e_mail=name.substr(0,1)+last_name+"@gmail.com";
			string aux=name+" "+last_name+" "+dni+" "+e_mail;
			v.push_back(aux);
		}
	}
	void create_binary(){
		ofstream write_archive("team.dat",ios::binary);
		for(unsigned int i=0;i<v.size();i++) { 
			char aux[100];
			strcpy(aux,v[i].c_str());
			write_archive.write(aux,sizeof(aux));
		}
	}
};
	
int main() {
	
	team_management Company;
	Company.generate_e_mail();
	Company.create_binary();
	
	ifstream read_binary("team.dat",ios::binary);
	char aux2[100];
	while(read_binary.read(aux2,sizeof(aux2))){
		cout<<aux2<<endl;
	}
	
	return 0;
}

