#include <iostream>
using namespace std;

void insertar(int valor,int posicion,int *arreglo){
	
	arreglo[posicion]=valor;

	
}

int main() {
	cout<<"Ingrese n"<<endl;
	int n;
	cin>>n;
	
	int *a=new int[n];
	int max=0;
	int *p=nullptr;
	for ( int i=0;i<n;i++){
		*(a+i)=rand()%(1500-1000+1)+1000;
		
		if(*(a+i)>max){
			max=*(a+i);
			p=(a+i);
		}
		
		cout<<*(a+i)<< " pos "<<(a+i)<<endl;
	} 
	
	cout<<endl<<"mayor: "<<max<<" posicion: "<<p<<endl<<endl;
	
	int m;
	int pos;
	
	cout<<"Ingrese el nuevo valor "<<endl;
	cin>>m;
	cout<<"Ingrese la posicion"<<endl;
	cin>>pos;
	
	
	insertar(m,pos,a);
	
	
	for ( int i=0;i<n;i++){
		
		
		
		cout<<*(a+i)<< " pos "<<(a+i)<<endl;
	} 
	
	
	delete p;
	delete[] a;
	
	
	return 0;
}

