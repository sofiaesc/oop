#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	ifstream archi("PROSA.TXT",ios::in);
	vector<string>v;
	string x;
	while(getline(archi,x)){
		size_t p = x.find("software");
		while (p!=string::npos){
			x.replace(p,p+8,"programa");
			p = x.find("software");
		}
		v.push_back(x);
	}
	archi.close();
	ofstream archi2("PROSA.TXT");
	for(unsigned int i=0;i<v.size();i++) { 
		archi2<<v[i]<<endl;
	}
	
	return 0;
}

