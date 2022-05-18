#include <iostream>
using namespace std;

class Vector3D{
	int x,y,z;
public:
	Vector3D(int a,int b,int c) : x(a),y(b),z(c){}
	
	int &operator[](int i){
	if (i==0){return x;} else{if (i==1){return y;} else{if (i==2){return z;}}}}
	
	int operator[](int i)const{
		if (i==0){return x;} else{if (i==1){return y;} else{if (i==2){return z;}}}}
	
	Vector3D operator+(Vector3D v)
	
};

int main() {
	
	return 0;
}

