#include <iostream>
using namespace std;

int* redimensionar(int tamanio,int ceros,int *a){
	
	int *x=new int[tamanio+ceros];
	
	for(int i=0;i<tamanio;i++){
		x[i]=a[i];
	}
	
	for(int i=tamanio;i<tamanio+ceros;i++){
		x[i]=0;
	}
	
	return x;
}
int main() {
	int n;
	cout<<"Ingrese n"<<endl;
	cin>>n;
	
	
	int *a=new int [n];
	
	for(int i = 0;i<n;i++){
		a[i]=rand()%(10-0+1)+0;
		cout<<a[i]<<" "<<"pos"<<(a+i)<<endl;
	
	}
	cout<<"Ingrese la cantidad de ceros a agregar "<<endl;
	int ceros;
	cin>>ceros;
	
	int *x=new int [n+ceros];
	
	
	x=redimensionar(n,ceros,a);
	
	for(int i=0;i<n+ceros;i++){
		cout<<x[i]<<endl;
	}

	
	
	return 0;
}

