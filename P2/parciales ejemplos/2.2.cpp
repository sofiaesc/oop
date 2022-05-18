#include <iostream>
#include <list>
#include <vector>
using namespace std;

template<typename T>
vector<T> list_to_vector(list<T>l){
	vector<T>v;
	for(T &x : l){
		v.push_back(x);
	}
	return v;
}

int main() {
	
	list<int>l(15);

	for(int &x : l){
		x=1+rand()%20;
		cout<<x<<" ";
	}
	cout<<endl<<endl;
	vector<int>v=list_to_vector<int>(l);
	
	for(unsigned int i=0;i<v.size();i++) { 
		cout<<v[i]<<" ";
	}
	
	return 0;
}

