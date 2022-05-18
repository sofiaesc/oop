#include <iostream>
using namespace std;
template<typename T>
void intercambia(T &x,T &y){
	
	T aux=x;
	x=y;
	y=aux;
	
}

int main() {
	int p=32;
	int u=23;
	intercambia(p,u);
	
	cout<<"p era 32.3   "<<p<<endl;
	cout<<"u era 23.3   "<<u<<endl;
	return 0;
}

