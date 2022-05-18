#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;

int main() {
	
	float x;
	vector<float>v;
	ifstream archi("termometro.txt");
	while(archi>>x){
		v.push_back(x);
	}
	archi.close();
	
	// ordenar en forma ascendente:
	sort(v.begin(),v.end());
	
	// temperatura promedio:
	float sum;
	for(unsigned int i=0;i<v.size();i++) { 
		sum+=v[i];
	}
	float prom=sum/v.size();
	
	// mayor y menor de todos los datos:
	float mayor=*max_element(v.begin(),v.end());
	float menor=*min_element(v.begin(),v.end());
	
	// guardar en binario:
	ofstream archi2("termometro.dat",ios::binary);
	for(unsigned int i=0;i<v.size();i++) { 
		float dif;
		if(v[i]-prom>=0){
			dif=v[i]-prom;
		} else{
			dif=prom-v[i];
		}
		stringstream ss;
		ss<<v[i]<<" "<<dif<<endl;
		string resultado=ss.str();
		char aux[20];
		strcpy(aux,resultado.c_str());
		archi2.write(reinterpret_cast<char*>(&aux),sizeof(aux));
	}
	
	return 0;
}

