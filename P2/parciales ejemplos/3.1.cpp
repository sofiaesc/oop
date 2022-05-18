#include <iostream>
#include <list>
#include <fstream>
#include <vector>
using namespace std;

list<string> list_includes(string archive_name){
	ifstream code_archive(archive_name,ios::in);
	list<string>l;
	string str;
	while(getline(code_archive,str)){
		if(str.size()>8 && str.substr(0,8)=="#include"){
			if(str[8]==' ') l.push_back(str.substr(9));
			else l.push_back(str.substr(8));
		}
	}
	return l;
}

int main() {
	
	ofstream test_archive("proof_text.txt");
	
	vector<string>v;
	v.push_back("#include<fstream>");
	v.push_back("#include <list>");
	v.push_back("hol ahol ahola");
	v.push_back("#include MiClase.h");
	
	for(unsigned int i=0;i<v.size();i++) { 
		test_archive<<v[i]<<endl;
	}
	
	test_archive.close();
	
	list<string>l=list_includes("proof_text.txt");
	
	for(string &x : l){
		cout<<x<<endl;
	}
	
	return 0;
}

