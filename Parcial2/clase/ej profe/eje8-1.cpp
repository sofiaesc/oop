#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	//Decaro un vector dinamico de 15 posiciones
	vector<int> v(15);
	srand(time(0));
	for(size_t i=0;i<v.size();i++)
		v[i]=rand()%20;
	//***
	cout<<"a.1 utilizando el operador []"<<endl;
	for(size_t i=0;i<v.size();i++)
		cout<< v[i] << " ";
	cout<< endl;
	cout<<"a.2 utilizando iteradores"<<endl;
	for( vector<int>::iterator it=v.begin(); it!=v.end(); ++it )
		cout<< *it << " ";
	cout<< endl;
	//***
	cout<<"a.3 utilizando el for basado en rangos"<<endl;
	for( int x : v )
		cout<< x << " ";
	cout<< endl;
	//***
	cout<< "b.1 Max: " << *max_element(v.begin(),v.end()) << endl;
	cout<< "b.1 Min: " << *min_element(v.begin(),v.end()) << endl;
	//
	int sum = accumulate(v.begin(),v.end(),0);
	cout<< "b.2 Suma: " << sum << endl;
	//***
	cout<< "b.3 Media (promedio): " << float(sum)/v.size() << endl;
	cout<< "b.3 Mediana: " << v[v.size()/2] << endl;
	//***
	cout<<"Ingrese un numero que este en el vector: ";
	int x;
	cin>> x;
	/*auto: el compilador determina el tipo que sustituirá a la palabra
	clave auto como si estuviera utilizando las reglas para la deducción
	de argumento de plantilla a partir de una llamada de función.*/
	auto it = find(v.begin(),v.end(),x);
	if (it==v.end())
		cout<< "No esta" << endl;
	else
		cout<< "Esta en la posicion " << it-v.begin() << endl;
	return 0;
}

