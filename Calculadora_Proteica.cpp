//--------- CALCULADORA PROTEICA ---------//
#include <iostream>
using namespace std;

// Función para calcular la cantidad de proteínas recomendadas
double calcularProteinasRecomendadas(double peso, double altura) {
    // Supongamos una regla general de 0.8 a 1 gramo de proteína por cada kilogramo de peso
    return peso * 0.8;
}

int main() {
	
    double peso, altura;
    cout << "Ingrese su peso (kg): ";
    cin >> peso;
    cout << "Ingrese su altura (metros): ";
    cin >> altura;

    // Calcular la cantidad de proteínas recomendadas
    double proteinasRecomendadas = calcularProteinasRecomendadas(peso, altura);

    // Mostrar la cantidad de proteínas recomendadas
    cout << "La cantidad recomendada de proteinas a consumir es: " << proteinasRecomendadas << " gramos por dia." << endl;

    return 0;
}

