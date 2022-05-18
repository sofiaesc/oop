#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main() {
	ifstream ent("inscriptos.txt");
	string n;
	int co=1,i=1;
	stringstream nom;
	nom.str("");
	nom<<"comision"<<co<<".txt";
	ofstream sal(nom.str());
	
	while(getline(ent,n)){
		sal<<n<<endl;
		if(i%5==0){
			sal.close();
			co++;
			nom.str("");
			nom<<"comision"<<co<<".txt";
			sal.open(nom.str());
		}
		i++;
	}
	sal.close();
	ent.close();
	return 0;
}

