#include <iostream>
using namespace std;

class Vector2D{
	int x, y;
public:
	Vector2D(int a,int b) : x(a),y(b){}
	int VerX(){return x;}
	int VerY(){return y;}
	
	int operator*(Vector2D v){
		return this->VerX()*v.VerX()+this->VerY()*v.VerY();
	}
	
	Vector2D operator^(int x){
		Vector2D escalar(this->VerX()*x,this->VerY()*x);
		return escalar;
	}
	
};

int main() {
	
	return 0;
}

