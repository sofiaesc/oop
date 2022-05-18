#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int rand10(){
	return rand()%(20+1)-10;
}

bool es_par(int x){
	return (x%2==0);
}

bool menor_abs(int a,int b){
	return (abs(a)<abs(b));
}

int main() {
	
	srand(time(0));
	int v[20];
	
	generate(v,v+20,rand10);
	
	for(int i=0;i<20;i++) { 
		cout<<v[i]<<" ";
	}
	cout<<endl<<endl;
	
	int x=count_if(v,v+20,es_par);
	cout<<x;
	
	cout<<endl<<endl;
	
	sort(v,v+20,menor_abs);
	
	for(int i=0;i<20;i++) { 
		cout<<v[i]<<" ";
	}
	cout<<endl;
	
	int *p = unique(v,v+20);
	int nuevo_t=(v+20)-p;
	
	for(int i=0;i<nuevo_t;i++) { 
		cout<<v[i]<<" ";
	}
	
	delete p;
	
	return 0;
}

