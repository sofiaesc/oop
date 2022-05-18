#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class VectorDinamico{
private:
	int N;
	vector<T>v;
public:
	VectorDinamico(int i){
		v.resize(i);
	}
	
	int VerTamanio(){
		return v.size();
	}
};


int main() {
	VectorDinamico<float>a(30);
	cout<<a.VerTamanio();
	
	
	return 0;
}

