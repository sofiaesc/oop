#include <iostream>
using namespace std;

template<typename T>
class VectorDinamico{
	int N;
	T *v;
public:
	VectorDinamico(int tamanio) : N(tamanio){
		v = new T[N];
	}
	
	VectorDinamico(int tamanio,int tope){
		v = new T[N];
		for(unsigned int i=0;i<N;i++) { 
			v[i]=1+rand()%(tope);
		}
	}
	
	T &operator[](int i){
		return v[i];
	}
	
	T operator[](int i) const{
		return v[i];
	}
	
	~VectorDinamico(){
		delete[] v;
	};
};



int main() {
	
	VectorDinamico<int> a(5,10);
	VectorDinamico<string> b(5,60);
	
	cout<<a[2]<<" "<<b[2];
	
	return 0;
}

