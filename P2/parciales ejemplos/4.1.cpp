#include <iostream>
#include <vector>
#include <fstream>
#include <list>
using namespace std;

template<typename T>
struct str_aux{
	T value;
	char pos;
};

template<typename T>
void ampliar(string archname,vector<str_aux<T>>v){
	ifstream archi(archname,ios::binary|ios::in);
	list<T>l_aux;
	T x;
	while(archi.read(reinterpret_cast<char*>(&x),sizeof(x))){
		l_aux.push_back(x);
	}
	archi.close();
	for(unsigned int i=0;i<v.size();i++) { 
		if(v[i].pos=='f'){
			l_aux.push_front(v[i].value);
		}
		if(v[i].pos=='b'){
			l_aux.push_back(v[i].value);
		}
	}
	ofstream archi2(archname,ios::binary);
	for(T &x : l_aux) { 
		archi2.write(reinterpret_cast<char*>(&x),sizeof(x));
	}
	archi2.close();
}

int main() {
	
	ofstream archi_x("ejemplito.dat",ios::binary);
	
	for(int i=0;i<5;i++) { 
		int x=1+rand()%10;
		cout<<x<<" ";
		archi_x.write(reinterpret_cast<char*>(&x),sizeof(x));
	}
	archi_x.close();
	
	vector<str_aux<int>>v;
	str_aux<int> a,b;
	a.pos='f';
	b.pos='b';
	a.value=12;
	b.value=14;
	v.push_back(a);
	v.push_back(b);
	cout<<endl<<endl;
	ampliar("ejemplito.dat",v);
	
	ifstream archi("ejemplito.dat",ios::binary|ios::in);
	int y;
	while(archi.read(reinterpret_cast<char*>(&y),sizeof(y))){
		cout<<y<<" ";
	}
	
	return 0;
}

