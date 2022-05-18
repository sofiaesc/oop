#include <iostream>
using namespace std;

float* max_element(float *a, float *b){
	int t=b-a;
	float mayor=0;
	float *p=nullptr;
	
	for(int i=0;i<t;i++) { 
		if (a[i]>mayor){
			mayor=a[i];
			p=a+i;
		}
	}
	
	return p;
}

int main() {
	
	float *p=new float[10];
	for(int i=0;i<10;i++) { 
		p[i]=rand()%(50-20+1)+20;
		cout<<p[i]<<" - "<<p+i<<endl; 
	}
	
	cout<<max_element(p,p+10);
	
	delete[] p;
	
	return 0;
}

