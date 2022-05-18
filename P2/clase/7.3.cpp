#include <iostream>
using namespace std;

template<typename T>
class VectorDinamico{
	int N;
	T *a=new T [N];
public:
	VectorDinamico(int tamanio){
		N=tamanio;
	}
	
	
	T &operator[](int i){
		
		return a[i];
	}
	
	T operator[](int i) const{
		
		return a[i];
	}
	
	
	
	~VectorDinamico(){
		
		delete a;
	}
	
};
int main() {
	
	VectorDinamico<float>v(10);
	
	v[1]=2.2;
	
	cout<<v[1];
	
	return 0;
}

