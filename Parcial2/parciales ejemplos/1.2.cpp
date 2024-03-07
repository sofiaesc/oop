#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;

// COPY REFERENCE:  < >   <<    >>

class User_Management{
	vector<string>v;
public:
	void GeneratePassword(){
		ifstream text_archive("USERS.txt");
		stringstream ss;
		string line;
		int code;
		string sector,name,last_name,password;
		while(getline(text_archive,line)){
			stringstream ss(line);
			ss>>code>>sector>>name>>last_name;
			password=name.substr(0,1)+last_name;
			stringstream ss2;
			ss2<<code<<" "<<name<<" "<<last_name<<" "<<password;
			string to_insert=ss2.str();
			v.push_back(to_insert);
		}
		text_archive.close();
	}
	void CreateBinary(){
		ofstream binary_archive("USERS.dat",ios::binary|ios::out);
		for(unsigned int i=0;i<v.size();i++) { 
			char aux[100];
			strcpy(aux,v[i].c_str());
			binary_archive.write(reinterpret_cast<char*>(&aux),sizeof(aux));
		}
		binary_archive.close();
	}
};

int main() {
	
	User_Management Example;
	Example.GeneratePassword();
	Example.CreateBinary();
	

	string v[2];
	ifstream example_reading("USERS.dat",ios::binary|ios::in);
	for(int i=0;i<2;i++) { 
		char x[100];
		example_reading.read(x,sizeof(x));
		v[i]=x;
		cout<<v[i]<<endl;
	}
	
	return 0;
}

