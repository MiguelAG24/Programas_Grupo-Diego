//--------------- CONSULTA DE PRECIOS ---------------//
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	
    double precioProducto;
    const double aumentoPrecioOriginal = 75;

    // Pedir al usuario ingresar el precio del producto
    cout << "Ingrese el precio del producto: Q. ";
    cin >> precioProducto;

    // Calcular el precio original
    double precioOriginal = precioProducto + aumentoPrecioOriginal;

    // Calcular el precio de oferta
    double precioOferta = precioProducto - (precioProducto * 0.15);

    // Mostrar los resultados
    cout << fixed << setprecision(2);
    cout << "Precio original: Q. " << precioOriginal << endl;
    cout << "OFERTAS POR SEMANA SANTA! TODO PRODUCTO CUENTA CON EL 15% DE DESCUENTO! "<<endl;
    cout << "Precio de super oferta: Q. " << precioOferta << endl;
    cout<< "----------------------------------"<<endl;
    return 0;
}

