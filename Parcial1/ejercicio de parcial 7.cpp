#include <iostream>
#include <vector>
using namespace std;

struct Compra{
	string codigo_producto;
	float precio_unitario;
	int cantidad;
};

struct Descuento{
	string descripcion;
	float monto;
};

class Promocion{
string descripcion;
public:
	Promocion(string descripcion){this->descripcion=descripcion;}
	virtual float Aplicar(Compra a)=0;
	virtual ~Promocion(){}
	string VerDescripcion(){return descripcion;}
};

class Promo3x2 : public Promocion{
public:
	Promo3x2() : Promocion("3x2 en todas las marcas"){}
	float Aplicar(Compra a){
		if (a.cantidad>=3){ 
			int cant=a.cantidad/3;
			return a.precio_unitario*cant;}
		return 0;
	}
};

class Promo1000 : public Promocion{
public:
	Promo1000() : Promocion("5% en compras superiores a $1000"){}
	float Aplicar(Compra a){
		if (a.cantidad*a.precio_unitario > 1000){
			return a.precio_unitario*0.05;}
		return 0;
	}
};

vector<Descuento>Funcion(vector<Compra>v, Promocion *a, Promocion *b){
	vector<Descuento>d;
	
	for(unsigned int i=0;i<v.size();i++) {

		if (a->Aplicar(v[i])!=0){
			Descuento d1;
			d1.descripcion=a->VerDescripcion();
			d1.monto=a->Aplicar(v[i]);
			d.push_back(d1);
		}
		if (b->Aplicar(v[i])!=0){
			Descuento d2;
			d2.descripcion=b->VerDescripcion();
			d2.monto=b->Aplicar(v[i]);
			d.push_back(d2);
		}
	}
	
	return d;
}

int main() {

	
	return 0;
}

