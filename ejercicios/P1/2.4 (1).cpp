#include <iostream>
#include <ctime>
using namespace std;

class VectorDinamico{
	int *p;
	int N;
public:
	VectorDinamico(int N){
		this->N=N;
		p=new int[N];
		for (int i=0;i<N;i++){
			p[i]=rand()%10;
		}
	}
	
	void Duplicar(){
		for (int i=N;i<(N*2);i++){
			p[i]=rand()%10;
		}
		N=N*2;
	}
	
	int VerElemento(int e){
		return p[e];
	}
	
	void MostrarVector(){
		for (int i=0;i<N;i++){
			cout<<i<<" - "<<*(p+i)<<endl;
		}
	}
	
	VectorDinamico operator*(int x){
		for (int i=0;i<N;i++){
			p[i]=p[i]*x;
		}
		return *p;
	}
	
	~VectorDinamico(){
		delete p;
	}
	
};



int main() {
	
	srand(time(0));
	
	int N;
	cout<<"Ingrese tamaño del vector: ";
	cin>>N;

	VectorDinamico v(N);
	v.MostrarVector();
	cout<<endl<<endl;
	
	int p;
	cout<<"Ver el elemento número: ";
	cin>>p;
	cout<<v.VerElemento(p);
	
	cout<<endl<<endl;
	v.Duplicar();
	N=N*2;
	v.MostrarVector();
	cout<<endl<<endl;
	
	int x;
	cout<<"Multiplicar vector por el siguiente numero: ";
	cin>>x;
	v*x;
	cout<<endl<<endl;
	v.MostrarVector();
	
	return 0;
}

