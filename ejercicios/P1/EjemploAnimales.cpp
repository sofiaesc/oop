#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std; 

class Animal {
	string m_especie, m_nombre;
public:
	Animal(string especie, string nombre) {
		m_especie = especie;
		m_nombre = nombre;
	}
	string VerEspecie() { return m_especie; }
	string VerNombre() { return m_nombre; }
	virtual string Hablar() =0;
	virtual string HacerGracia() { return "no hace nada"; }
	virtual ~Animal() {}
};



void gran_funcion_que_hace_cosas_interesantes(vector<Animal*> &v) {
	do {
		int i = rand()%v.size();
		cout << "El " << v[i]->VerEspecie() 
			<< " " << v[i]->VerNombre() << " dice "
			<< v[i]->Hablar() << " y " 
			<< v[i]->HacerGracia() << endl;
	} while(cin.get()=='\n');
}


class Pulga {
	
};

class Perro : public Animal {
	Pulga *v;
public:
	Perro(string nombre) : Animal("perro",nombre) { 
		v = new Pulga[200];
	}
	string Hablar() { return "guau!"; }
	string HacerGracia() { return "da la patita y mueve la cola"; }
	~Perro() { 
		cout << "El perro se sacude las pulgas" << endl;
		delete [] v; 
	}
};

class Gato : public Animal {
public:
	Gato(string nombre) : Animal("gato",nombre) { }
	string Hablar() { return "miau!"; }
};

class Conejo: public Animal {
public:
	Conejo(string nombre) : Animal("conejo",nombre) { }
	string Hablar() { return "Que hay de nuevo viejo?"; }
	string HacerGracia() override { return "muerde una zanahoria"; }
};

class TortugaNinja : public Animal {
public:
	TortugaNinja(string nombre) : Animal("tortuga",nombre) { }
	string Hablar() { return "kawabunga!"; }
	string HacerGracia() { return "come pizza"; }
};

class Oso : public Animal {
public:
	Oso(string nombre) : Animal("oso",nombre) { }
	string Hablar() { return "skadoosh!"; }
	string HacerGracia() { return "baja el meñique derecho"; }
};



int main() {
	
	vector<Animal*> v;
	
	v.push_back(new Perro("Coraje"));
	v.push_back(new Perro("Dante"));
	v.push_back(new Gato("Bola de Nieve"));
	v.push_back(new TortugaNinja("Donatello"));
	v.push_back(new TortugaNinja("Michelangelo"));
	v.push_back(new TortugaNinja("Rafael"));
	v.push_back(new TortugaNinja("Leonardo"));
	v.push_back(new Oso("Po"));
	v.push_back(new Conejo("Bugs"));
	
	gran_funcion_que_hace_cosas_interesantes(v);
	
	for(size_t i=0;i<v.size();i++) delete v[i];
	
	
	return 0;
}

