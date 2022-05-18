#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;

struct athlete{
	float meters;
	string name;
};

bool sort_by_time(athlete a,athlete b){
	return (a.meters<b.meters);
}

bool sort_by_name(athlete a,athlete b){
	return (a.name<b.name);
}


int generate_series(string archive_name){

	// r e a d :
	
	ifstream read_archive(archive_name);
	vector<athlete>v;
	string aux_str;
	
	while(getline(read_archive,aux_str)){
		stringstream ss(aux_str);
		float aux_met; ss>>aux_met;
		string aux_name; getline(ss,aux_name);
		ss.ignore();
		
		athlete aux_ath;
		aux_ath.meters=aux_met;
		aux_ath.name=aux_name;
		
		v.push_back(aux_ath);
	}
	
	read_archive.close();
	
	// s o r t :
	
	sort(v.begin(),v.end(),sort_by_time);
	
	ofstream write_archive(archive_name, ios::in);
	
	for(unsigned int i=0;i<v.size();i++) { 
		write_archive<<v[i].meters<<" "<<v[i].name<<endl;
	}
	
	write_archive.close();
	
	// s e r i e s :
	
	ofstream series_archive(archive_name,ios::in);
	
	float series_count=(v.size()/8.0);
	int series_count_int=(v.size()/8);
	if(series_count-series_count_int!=0){series_count=series_count+1;}
	series_archive.close();
	
	
	for(int i=0;i<series_count;i++) {
		stringstream ss;
		ss<<"series"<<i+1<<".txt";
		ofstream aux_archive(ss.str());
		
		vector<athlete>aux_vector;
		for(unsigned int j=i;j<v.size();j=j+series_count) { 
			aux_vector.push_back(v[j]);
		}
		
		sort(aux_vector.begin(),aux_vector.end(),sort_by_name);
		
		for(unsigned int j=0;j<aux_vector.size();j++) { 
			aux_archive<<aux_vector[j].meters<<" "<<aux_vector[j].name<<endl;
		}
		aux_archive.close();
	}
	
	return series_count;
	
}

int main() {
	
	int s_c=generate_series("athletes.txt");
	cout<<"archivos generados: "<<s_c;
	
	return 0;
}

