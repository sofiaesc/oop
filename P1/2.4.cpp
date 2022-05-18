#include <iostream>
using namespace std;

class VectorDinamico{
private :
	int *p;
	
public:
	VectorDinamico(int n){
		p=new int [n];
		for(int i=0;i<n;i++){
			p[i]=rand()%(20-10+1)+10;
		}
	};
	
	void Duplicar(int n){
		
		
		for(int i=n;i<n+n;i++){
			p[i]=rand()%(10-1+1)+1;
		}
		
	}
	
	int VerElemento(int numeroElemento){
		return p[numeroElemento];
	}
	
	void mostrar(int n){
		for(int i=0;i<n;i++){
			cout<<*(p+i)<<endl;
		}
	}
	
	~VectorDinamico(){
		delete p;
	};
};
int main() {
	
	int n;
	cout<<"Ingrese el tamaño del vector "<<endl;
	cin>>n;
	VectorDinamico v(n);
	
	v.mostrar(n);
	v.Duplicar(n);
	cout<<"NUMEROS NUEVOS"<<endl;
	cout<<endl;
	v.mostrar(n*2);
	
	
	

	
	
	
	
	cout<<"Ingrese el elemento a buscar "<<endl;
	int elemento;
	cin>>elemento;
	
	cout<<"El elemento es "<< v.VerElemento(elemento)<<endl;
	
	
	
	
	
	
	return 0;
}

