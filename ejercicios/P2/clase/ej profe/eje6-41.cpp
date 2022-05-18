#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
using namespace std;
//A partir del byte 178 se debe reemplazar "mswxp"
//	por "msw10", y a partir del byte 239 reemplazar el valor entero 2003 por el valor 2016.

int main() {
	char m[6];
	strcpy(m,"JAP");
	
	for(int i=1;i<=4;i++) {
		stringstream s;
		s.str("");
		s<<"a"<<i<<".pdf";
		fstream f(s.str(), ios::binary |ios::in|ios::out);
		f.seekg(5,ios::beg);
		f.write((char*)&m[0],3);
		f.close();
		cout<<s.str()<<" modificado\n";
	}
	return 0;
}
