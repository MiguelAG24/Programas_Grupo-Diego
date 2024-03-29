//----------------- MULTIPLICACION MANUAL GRAFICA ----------------- //
#include <iostream>

using namespace std;

// Función para obtener el número de dígitos de un número entero
int obtenerNumeroDigitos(int numero) {
    int contador = 0;
    while (numero != 0) {
        numero /= 10;
        contador++;
    }
    return contador;
}

// Función para imprimir espacios
void imprimirEspacios(int n) {
    for (int i = 0; i < n; ++i) {
        cout << " ";
    }
}

// Función para imprimir un número
void imprimirNumero(int numero, int longitudMaxima) {
    int longitud = obtenerNumeroDigitos(numero);
    imprimirEspacios(longitudMaxima - longitud);
    cout << numero;
}

int main() {
    // Pedir al usuario que ingrese los números a multiplicar
    int multiplicando, multiplicador;
    cout << "Ingrese el multiplicando: ";
    cin >> multiplicando;
    cout << "Ingrese el multiplicador: ";
    cin >> multiplicador;

    // Calcular el resultado de la multiplicación
    int resultado = multiplicando * multiplicador;

    // Calcular la longitud máxima entre los números y el resultado
    int longitudMaxima = max(obtenerNumeroDigitos(multiplicando), obtenerNumeroDigitos(multiplicador));
    longitudMaxima = max(longitudMaxima, obtenerNumeroDigitos(resultado));

    // Imprimir la multiplicación gráfica
    cout << endl;
    imprimirNumero(multiplicando, longitudMaxima + 1);
    cout << endl;
    cout << "x";
    imprimirNumero(multiplicador, longitudMaxima);
    cout << endl;
    cout << "---------" << endl;

    int multiplicadorDigito;
    int espacioExtra = 0;
    int resultadoParcial;

    int multiplicadorCopia = multiplicador;
    while (multiplicadorCopia != 0) {
        multiplicadorDigito = multiplicadorCopia % 10;
        resultadoParcial = multiplicando * multiplicadorDigito;
        imprimirNumero(resultadoParcial, longitudMaxima + espacioExtra);
        espacioExtra--; //se agregan signos menos para que los resultados se corran un espacio. 
        cout << endl;
        multiplicadorCopia /= 10;
    }

    // Imprimir la línea horizontal debajo de los resultados parciales
    for (int i = 0; i < longitudMaxima + espacioExtra; ++i) {
        cout << "---------";
    }
    cout << endl;

    // Imprimir el resultado final
    imprimirNumero(resultado, longitudMaxima);
    cout << endl;

    return 0;
}

