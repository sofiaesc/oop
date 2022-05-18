#include <iostream>
using namespace std;

template<typename T>
class Rect{
	T Alto;
	T Ancho;
public:
	Rect(T x,T y){Alto=x;Ancho=y;};
	
	T VerAlto(){return Alto;}
	T VerAncho(){return Ancho;}
	
};

int main() {
	Rect<double> a(33.43,20.555);
	cout<<a.VerAlto()<<endl;
	cout<<a.VerAncho()<<endl;
	return 0;
}

