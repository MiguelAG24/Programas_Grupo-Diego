//------------------ Tablas de Multiplicar ------------------//
#include <iostream>
using namespace std;
main(){
	int inicio = 0, final = 0, res = 0;
	
	cout<<"Ingrese la tabla inicial (1): ";
	cin>>inicio;
	cout<<"Ingrese la tabla final (10): ";
	cin>>final;
	
	for(int rango=inicio;rango<=final;rango++){
	cout<<"Tabla del "<<rango<<endl;	
		for(int i=1;i<=10;i++){
			res=rango * i;
			cout<<rango<<" X "<<i<<" = "<<res<<endl;
		}
	cout<<"__________________"<<endl;	
	}
}
