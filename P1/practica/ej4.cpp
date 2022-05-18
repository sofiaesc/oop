#include <iostream>
using namespace std;

class CORREOS{
	string nombre,mail;
public:
	CORREOS(string n,string m) : nombre(n),mail(m){}
	string VerNombre(){return nombre;}
	string VerMail(){return mail;}
	
	bool operator==(CORREOS &c){
		return (nombre==c.VerNombre());
	}
	
	string operator[](int i)const{
		if (i==1){return nombre;
		}else{
		return mail;
		}
	}
	
	string &operator[](int i){
		if (i==1){return nombre;
		}else{
			return mail;
		}
	}
	
};

ostream &operator<<(ostream &o,CORREOS c){
	o<<c.VerNombre()<<" ("<<c.VerMail()<<")";
	return o;
}

int main() {
	
	return 0;
}

