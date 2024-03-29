//----------------- MULTIPLICACION MANUAL GRAFICA ----------------- //
#include <iostream>

using namespace std;

// Funci�n para obtener el n�mero de d�gitos de un n�mero entero
int obtenerNumeroDigitos(int numero) {
    int contador = 0;
    while (numero != 0) {
        numero /= 10;
        contador++;
    }
    return contador;
}

// Funci�n para imprimir espacios
void imprimirEspacios(int n) {
    for (int i = 0; i < n; ++i) {
        cout << " ";
    }
}

// Funci�n para imprimir un n�mero
void imprimirNumero(int numero, int longitudMaxima) {
    int longitud = obtenerNumeroDigitos(numero);
    imprimirEspacios(longitudMaxima - longitud);
    cout << numero;
}

int main() {
    // Pedir al usuario que ingrese los n�meros a multiplicar
    int multiplicando, multiplicador;
    cout << "Ingrese el multiplicando: ";
    cin >> multiplicando;
    cout << "Ingrese el multiplicador: ";
    cin >> multiplicador;

    // Calcular el resultado de la multiplicaci�n
    int resultado = multiplicando * multiplicador;

    // Calcular la longitud m�xima entre los n�meros y el resultado
    int longitudMaxima = max(obtenerNumeroDigitos(multiplicando), obtenerNumeroDigitos(multiplicador));
    longitudMaxima = max(longitudMaxima, obtenerNumeroDigitos(resultado));

    // Imprimir la multiplicaci�n gr�fica
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

    // Imprimir la l�nea horizontal debajo de los resultados parciales
    for (int i = 0; i < longitudMaxima + espacioExtra; ++i) {
        cout << "---------";
    }
    cout << endl;

    // Imprimir el resultado final
    imprimirNumero(resultado, longitudMaxima);
    cout << endl;

    return 0;
}

