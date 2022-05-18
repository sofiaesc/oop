#include <iostream>
#include <ctime>
using namespace std;

int main() {
	
	srand(time(0));
	
	int *p = new int[20];
	
	for(int i=0;i<20;i++) { p[i]=rand()%(500)+1;}
	
	for(int i=0;i<20;i++) { cout<<*(p+i)<<endl; }
	
	delete[] p;
	
	return 0;
}

