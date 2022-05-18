#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
//------------------------------------------------
template <class T>
T Clamp(T &v, T mi, T ma)//v es un valor, a es el inicio y b es fin del rango
{  if(v<mi) v=mi;
   if(v>ma) v=ma;
   return v;
}
//------------------------------------------------
int main(void){
	srand(time(0));//para generar numeros al azar distintos
	//*** con caracteres ***
	char d;
	
	cout<<"Ingrese una letra entre al 'e' y la 'm': ";//muestro en pantalla rango y valor
	cin>>d;
	Clamp<char>(d,'e','m');//LLamo a la funcion que verifica que <d> este en rango
	cout<<"d= "<<d<<endl;
	//*** Con entros ***
	int pri=50, ult=100, dato=400;
	cout<<"*****"<<endl<<" pri= 50, ult= 100 "<<endl;//muestro en pantalla rango
	for(int k=0; k<10; k++){//Genero 10 numeros al azar
		dato= rand()%200;
		cout<<"valor generado= "<<setw(5)<<dato;//Muestro valor original
		Clamp(dato,pri,ult);//LLamo a la funcion con enteros
		cout<<"  - valor validado= "<<setw(5)<<dato<<endl;//Muesto valor validado
	}
	return 0;
}
