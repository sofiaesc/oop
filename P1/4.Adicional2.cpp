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
	
	int VerElemento(int e) const{
		return p[e];
	}
	
	void MostrarVector() const{
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
	
	VectorDinamico operator=(VectorDinamico v){
		for(int i=0;i<N;i++) { 
			this->p[i]=v.p[i];
		}
		return *p;
	}
	
	int operator[](int x) const{
		if (x>=N){
			cout<<"El índice no es correcto.";
			return p[-1];
		}else{
			return p[x];
		}
	}
	
	int &operator[](int x){
		if (x>=N){
			cout<<"El índice no es correcto.";
			return p[-1];
		}else{
			return p[x];
		}
	}
	
	~VectorDinamico(){
		delete p;
	}
	
};



int main() {
	
	srand(time(0));
	
	//generar vector:
	int N;
	cout<<"Ingrese tamaño del vector: ";
	cin>>N;

	VectorDinamico v(N);
	v.MostrarVector();
	cout<<endl;
	
	//ver elemento del vector:
	int p;
	cout<<"Ver el elemento número: ";
	cin>>p;
	cout<<v.VerElemento(p);
	
	//duplicar y llenar:
	cout<<endl<<endl<<"Vector duplicado:"<<endl;
	v.Duplicar();
	N=N*2;
	v.MostrarVector();
	cout<<endl;
	
	//multiplicar por escalar:
	int x;
	cout<<"Multiplicar vector por el siguiente numero: ";
	cin>>x;
	v*x;
	v.MostrarVector();
	
	//asignar un vector a otro:
	cout<<endl<<"Nuevo vector:"<<endl;
	VectorDinamico b(N);
	b.MostrarVector();
	cout<<endl<<"Vector viejo:"<<endl;
	v=b;
	v.MostrarVector();
	
	cout<<v[4]<<endl;
	v[1]=3;
	cout<<v[1]<<endl;
	
	
	return 0;
}

