#include <iostream>
#include <cstdlib>
#include <typeinfo>

using namespace std;
//Interface *********************************
template<typename T>
class vectorDinamico{
private:
	int tam;
	T *p;
public:
	vectorDinamico(int t);//a)Constructor
	vectorDinamico(int t,T(*pf)());//a)Constructor
	~vectorDinamico();// b)Destructor
	T &operator[](int);//c) Operador []
	void operator+=(T);//d)Operador +=
	int ver_tam(){return tam;};
};
//Implementacion ----------------------------
template <typename T>
vectorDinamico<T>::vectorDinamico(int lar){
	tam= lar;
	p= new T [tam];
}

template <typename T>
vectorDinamico<T>::vectorDinamico(int lar,T(*pf)()){
	tam= lar;
	p= new T [tam];
    for(int x=0; x < tam; x++)
			*(p+x)= pf();
}

int _int(){return rand()%100;}
float _float(){return rand()%100+rand()%100/100.0;}
char _char(){return char(rand()%26+65);}

// Item b
//Implementacion ----------------------------
template <typename T>
vectorDinamico<T>::~vectorDinamico(){
	delete []p;
}
// Item c
//Implementacion ----------------------------
template <typename T>
T & vectorDinamico<T>::operator[](int indice){
	return *(p+indice);
}
// Item d//Implementacion ----------------------------
template <typename T>
void vectorDinamico<T>::operator+=(T elemento){
	T *aux = new T [tam+1];//Declaro vector auxiliar
	for(int x=0; x < (tam); x++)//Recorro aux asignando los valores de p
		*(aux+x)= *(p+x);
	tam++;//Incremento en 1 el tamaño
	*(aux+tam-1)= elemento;//Asigno en la ultima posicion
	delete []p;//Borro el vector viejo
	p= aux;//Asigno a p el vector auxiliar
}

int main(int argc, char *argv[]) {
	vectorDinamico<int> v(10);
	v[7]=12345678;
	
	int n;
	for(int k= 0; k < v.ver_tam(); k++)
		cout<<v[k]<<", ";
		cout<<endl;
		cout<<"\nIngrese un numero: "; cin>> n;
		v += n; //agrego con el += sobrecargado
		cout<<"Arreglo agregando el "<<n<<endl;
		for(int k= 0; k < v.ver_tam(); k++)
			cout<<v[k]<<", ";
		cout<<endl<<endl<<endl;
		//**************************************
	vectorDinamico<float> v2(10,_float);
		float n2;
		for(int k= 0; k < v2.ver_tam(); k++)
			cout<<v2[k]<<", ";
		cout<<"\nIngrese un float: "; cin>> n2;
		v2 += n2;
		cout<<"Arreglo agregando el "<<n2<<endl;
		for(int k= 0; k < v2.ver_tam(); k++)
			cout<<v2[k]<<", ";
	return 0;
}

