#include <iostream>
using namespace std;

int* Funcion(int *p,int n,int x){
	for(int i=0;i<n;i++) { 
		if (p[i]==x){
			return (p+i);
		}
	}
	return nullptr;
}

int main() {
	
	int *p=new int[5];
	
	for(int i=0;i<5;i++) { 
		p[i]=rand()%(50-5+1)+5;
		cout<<p[i]<<" - "<<(p+i)<<endl;
	}
	
	cout<<Funcion(p,5,9)<<endl;
	int ind=Funcion(p,5,9)-p;
	cout<<ind<<endl;
	
	delete[] p;
	
	return 0;
}

