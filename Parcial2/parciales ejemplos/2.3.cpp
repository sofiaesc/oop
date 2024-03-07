#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct client{
	char name[15];
	char last_name[15];
	int dni;
	float balance;
};

class bills{
	vector<client>v;
	
public:
	void save_to_binary(){
		ofstream saving_archive("client_bills.dat",ios::binary);
		for(unsigned int i=0;i<v.size();i++) { 
			saving_archive.write(reinterpret_cast<char*>(&(v[i])),sizeof(v[i]));
		}
	}
	void load_from_binary(){
		ifstream reading_archive("client_bills.dat",ios::binary|ios::in);
		client aux;
		while(reading_archive.read(reinterpret_cast<char*>(&aux),sizeof(aux))){
			v.push_back(aux);
		}
	}
	void add_client(client aux_client){
		v.push_back(aux_client);
	}
	void delete_client(int aux_dni){
		for( auto it=v.begin(); it!=v.end(); ++it ){ 	
			if ((*it).dni==aux_dni){
				v.erase(it);
			}
		}
	}
	client return_client(int i){
		return v[i];
	}
};

int main() {
	
	return 0;
}

