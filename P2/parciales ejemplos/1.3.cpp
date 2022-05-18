#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// COPY REFERENCE:  < >   <<    >>

struct Card{
	int number;
	char suit[10];
};

class Deck{
	vector<Card>v;
public:
	void Save_Cards(){
		ofstream saving_binary("deck_of_cards.dat",ios::binary|ios::trunc);
		for(unsigned int i=0;i<v.size();i++) { 
			saving_binary.write(reinterpret_cast<char*>(&(v[i])),sizeof(v[i]));
		}
		saving_binary.close();
	}
	void Load_Cards(){
		ifstream loading_binary("deck_of_cards.dat",ios::binary|ios::in|ios::out);
		Card loading_card;
		while(loading_binary.read(reinterpret_cast<char*>(&loading_card),sizeof(loading_card))){
			v.push_back(loading_card);
		}
		loading_binary.close();
	}
	void Add_Card(int number_to_add,char suit_to_add[10]){
		Card card_to_add;
		card_to_add.number=number_to_add;
		strcpy(card_to_add.suit,suit_to_add);
		v.push_back(card_to_add);
	}
	void Delete_Card(int number_to_delete,char suit_to_delete[10]){
		for(auto it=v.begin(); it!=v.end(); ++it ) { 
			if(((*it).number==number_to_delete) && ((*it).suit==suit_to_delete)){
				v.erase(it);
			}
		}
	}
	Card Return_Card(int p){
		return v[p];
	}
};



int main() {
	
	ifstream ex1_bin("deck_of_cards.dat",ios::binary|ios::in|ios::out);
	
	Deck mazo_de_cartas;
	char m1[10];char m2[10];
	strcpy(m1,"hola");
	strcpy(m2,"chau");
	 
	mazo_de_cartas.Add_Card(2,m1);
	mazo_de_cartas.Add_Card(1,m1);
	mazo_de_cartas.Add_Card(3,m2);
	mazo_de_cartas.Add_Card(4,m2);
	
	mazo_de_cartas.Save_Cards();
	
	Card loading_card;
	while(ex1_bin.read(reinterpret_cast<char*>(&loading_card),sizeof(loading_card))){
		cout<<loading_card.number<<" "<<loading_card.suit<<endl;
	}
	ex1_bin.close();
	
	mazo_de_cartas.Delete_Card(3,m2);
	mazo_de_cartas.Save_Cards();
	
	cout<<endl;
	
	ifstream ex2_bin("deck_of_cards.dat",ios::binary|ios::in|ios::out);
	
	Card load_card;
	while(ex2_bin.read(reinterpret_cast<char*>(&load_card),sizeof(load_card))){
		cout<<load_card.number<<" "<<load_card.suit<<endl;
	}
	
	cout<<endl;
	
	Card card_to_return=mazo_de_cartas.Return_Card(2);
	cout<<card_to_return.number<<" "<<card_to_return.suit<<endl;
	ex2_bin.close();
	return 0;
}

