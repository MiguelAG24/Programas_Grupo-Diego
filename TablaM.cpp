//------------ Tabla de Multiplicar ------------//
#include <iostream>
using namespace std;
main(){
	int tabla = 0, res = 0;
	
	cout<<"Ingrese tabla que desea consultar: "<<endl;
	cin>>tabla;
	
	for(int i=1; i<=10; i++){
	res = tabla * i;
	cout<<tabla<<" X "<<i<<" = "<<res<<endl;
	}	
}
