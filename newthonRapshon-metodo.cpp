//Librerias a utilizar
#include <iostream>
#include <iomanip> // setprecision 
#include <math.h>
#include<cstdlib>

using namespace std;

int main(){
	//Se definen las variables a utilizar en el Programa
	int i, n;
	float xi,xr, fx, fprima,error,ErrorIteracion;

	cout<<"Programa para el calculo de raiz a traves de Newthon Raphson"<<endl;
	//Se pide las iteraciones a realizar
	cout<<"¿Cuantas iteraciones desea?"<<endl; cin>>n;
	//Se pide el valor inicial para comenzar a correr el programa
	cout<<"¿Valor inicial x0?"<<endl; cin>>xi;
	//Se pide el error con el que se trabajara
	cout<<"¿Error a usar?"<<endl; cin>>error;

	//Se crea un bucle for para comenzar a calcular las aproximaciones
	for(i=0; i<=n; i++){
		//Se crea la función donde sera evaluada el valor inicial
		fx = (pow(xi,3))+(4*(pow(xi,2)))-10;
		//Se derivada la funcion que se va a utilizar 
		fprima = (3*(pow(xi,2)))+(8*xi);
		//Se realiza la formula de Newthon Raphson 
		xr = xi-(fx/fprima);
		//Se calcula el error 
		ErrorIteracion= fabs(((xr-xi)/xr)*100);

		//Se crea el header de la tabla 
		if(i==0){
			cout <<"\tIteracion\t  Xn \t\t\tf(Xn) \t\tf'(Xn) \t\tXn+1 \t\tError"<<endl;
		}

		//Si el valor de Error que vamos obteniendo es menor al error que se le ingreso, el programa finaliza
		if(ErrorIteracion<error){
			//Se imprime la ultima iteracion que ya coincide con el error que se ingreso
			cout << "\t"<<i+1<< "\t\t"<<xi<< "\t\t\t"<<fx<< "\t\t"<<fprima<< "\t\t"<<xr<< "\t\t"<<ErrorIteracion<<endl;
			cout << "\nLa raiz aproximada de la funcion es: " << xr;
			std::cin.get();
			break;
		}
		
		//Se define los decimales que utilizaremos
		cout <<setprecision(4);
		//Se imprimen los valores que vamos obteniendo
		cout << "\t"<<i+1<< "\t\t"<<xi<< "\t\t\t"<<fx<< "\t\t"<<fprima<< "\t\t"<<xr<< "\t\t"<<ErrorIteracion<<endl;
		//Se indica el nuevo valor de xi para seguir evaluando
		xi=xr;
	}
	//Presionar para finalizar el programa
	std::cin.get();
	return 0;
}

