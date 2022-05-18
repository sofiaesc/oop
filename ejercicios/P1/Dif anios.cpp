#include <iostream>
using namespace std;

class Fecha{
private:
	int dia;
	int mes;
	int anio;
public:
	Fecha(int x,int y,int z){dia=x;mes=y;anio=z;}
	
	int DiferenciaEnAnios(Fecha f){
		return abs(f.anio-anio);

	}
};

int main() {
	
	Fecha x(13,07,2000);
	Fecha y(18,12,2010);
	
	
	cout<<"La diferencia de anios es de "<< x.DiferenciaEnAnios(y);
	
	
	return 0;
}

