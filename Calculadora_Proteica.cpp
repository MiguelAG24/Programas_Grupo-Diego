//--------- CALCULADORA PROTEICA ---------//
#include <iostream>
using namespace std;

// Funci�n para calcular la cantidad de prote�nas recomendadas
double calcularProteinasRecomendadas(double peso, double altura) {
    // Supongamos una regla general de 0.8 a 1 gramo de prote�na por cada kilogramo de peso
    return peso * 0.8;
}

int main() {
	
    double peso, altura;
    cout << "Ingrese su peso (kg): ";
    cin >> peso;
    cout << "Ingrese su altura (metros): ";
    cin >> altura;

    // Calcular la cantidad de prote�nas recomendadas
    double proteinasRecomendadas = calcularProteinasRecomendadas(peso, altura);

    // Mostrar la cantidad de prote�nas recomendadas
    cout << "La cantidad recomendada de proteinas a consumir es: " << proteinasRecomendadas << " gramos por dia." << endl;

    return 0;
}

