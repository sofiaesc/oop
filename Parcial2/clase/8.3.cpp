#include <iostream>
#include <list>
#include <fstream>
using namespace std;



int main() {
	
	float a;
	list<float> l;
	
	cout<<"Ingrese valores de la lista:"<<endl;
	
	cin>>a;
	while (a!=0){
		l.push_back(a);
		cin>>a;
	}
	
	cout<<endl<<"La lista es:"<<endl;
	
	for(float &x : l){
		cout<<x<<" ";
	}
	
	for( auto it = next(l.begin()); it!=l.end(); advance(it,2) )
	{
		float prom = (*prev(it)+*it)/2;
		it = l.insert(it,prom);
	}
	
	cout<<endl<<"La lista es:"<<endl;
	
	for(float &x : l){
		cout<<x<<" ";
	}
	
	ofstream archi("listafloat.txt");
	
	//  for(auto it=l.begin() ; it!=l.end() ; it++){
	// 	   cout<<*it<<" ";
	//  *
	
	//	for(auto it=l.begin();it!=l.end();it++){
	//	 	archi<<*it<<" ";
	//  }
	
	for( float &x : l ) { 
		archi<<x<<endl;
	}

	archi.close();
	
	
	return 0;
}

