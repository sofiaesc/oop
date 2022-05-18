#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <ctime>
using namespace std;

template<typename T>
list<T> vector_to_list(vector<T> v){
	
	list<T>l;
	for(T &x : v){
		l.push_back(x);
	}
	
	/* ALTERNATIVE 2 - ITERATOR FOR:
	
		for(auto it=v.begin();it!=v.end();it++){
			
			l.push_back(*it);
		} 
	
	*/
	
	return l;
}

int main() {
	
	srand(time(0));
	
	vector<int>v;
	for(int i=0;i<10;i++){
		int x=rand()%(100)+1;
		v.push_back(x);
		cout<<x<<" ";
	}
	
	cout<<endl<<endl;
	
	list<int>l=vector_to_list<int>(v);
	
	for(auto it=l.begin();it!=l.end();it++){
		cout<<*it<<" ";
	} 
	
	/* ALTERNATIVE 2 - EASIER FOR: 
	
	for(int &x : l){
	cout<<x<<" ";
	}
	
	*/
	
	return 0;
}

