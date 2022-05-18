#include <iostream>
using namespace std;

int main() {
	
	float (*p)[6]=new float[10][6];
	
	for(int i=0;i<10;i++){
		for(int j=0;j<6;j++){
			*(*(p+i)+j)=rand()%10;
			cout<<*(*(p+i)+j)<<"  ";
		}
		cout<<endl;
	}
	
	int f;
	cout<<endl<<"fila"<<endl;
	cin>>f;
	cout<<endl;
	float suma;
	
	for(int i=0;i<6;i++){
		suma=suma+*(*(p+f)+i);
	}
	cout<<endl<<"el promedio es: "<<suma/6<<endl;
	cout<<endl;
	for (int i=0;i<6;i++){
		suma=0;
		for (int j=0;j<10;j++){
			suma=suma+*(*(p+j)+i);
		}
		cout<<"La suma de la columna "<<i<<" es de "<<suma<<endl;
	}
	
	return 0;
}

