#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
void del_maxmin(vector<T>&v){
	
	T val_max = *max_element(v.begin(),v.end());
	auto it_aux=remove(v.begin(),v.end(),val_max);
	v.erase(it_aux);
	
	T val_min = *min_element(v.begin(),v.end());
	auto it_aux2=remove(v.begin(),v.end(),val_min);
	v.erase(it_aux2);
}

int main() { 
	
	vector<int>v_i = {2,1,3,3,2,6,5,8,2,7,4,1,8};	
	vector<string>v_s = {"a","d","f","a","z","s","z","d"};
	
	cout<<"ORIGINALES:"<<endl;
	
	for(int &x : v_i){
		cout<<x<<" ";
	}
	cout<<endl;
	for(string &x : v_s){
		cout<<x<<" ";
	}
	
	del_maxmin<int>(v_i);
	del_maxmin<string>(v_s);
	cout<<endl<<endl<<"MODIFICADOS:"<<endl;
	
	for(int &x : v_i){
		cout<<x<<" ";
	}
	cout<<endl;
	for(string &x : v_s){
		cout<<x<<" ";
	}
	
	return 0;
}

