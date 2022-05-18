#include <iostream>
using namespace std;

template<typename T>
void Clamp(T &x, T lim_sup, T lim_inf){
	if(x>lim_sup){
		x=lim_sup;
	}
	if(x<lim_inf){
		x=lim_inf;
	}
}

int main() {
	
	int x=6;
	int lim_sup=5;
	int lim_inf=3;
	
	Clamp(x,lim_sup,lim_inf);
	cout<<x;
	
	return 0;
}

