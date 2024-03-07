#include <iostream>
using namespace std;

class Ejemplo{
public:
	operator int() const{
		return 3;
	}
	operator float() const{
		return 3.5;
	}
};

int main() {
	
	Ejemplo c;
	int i=c;
	float f=c;
	cout<<"int: "<<i<<endl;
	cout<<"float: "<<f<<endl;
	
	return 0;
}

