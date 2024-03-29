//----------- NUMEROS ENTEROS CON DECIMAL A LETRAS -----------//
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Función para convertir unidades a palabras
string convertirUnidad(int num, bool incluir_cien) {
    string unidades[] = {"", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
    if (num == 1 && incluir_cien) {
        return "ciento";
    } else {
        return unidades[num];
    }
}

// Función para convertir nombres especiales de centenas
string convertirCentenaEspecial(int num) {
    string especiales[] = {"", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};
    return especiales[num - 1];
}

// Función para convertir números del 10 al 19 a palabras
string convertirEspecial(int num) {
    string especiales[] = {"diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho", "diecinueve"};
    return especiales[num - 10];
}

// Función para convertir decenas a palabras
string convertirDecena(int num) {
    string decenas[] = {"", "diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
    return decenas[num];
}

// Función para convertir números compuestos de dos cifras a palabras
string convertirDosCifras(int num) {
    if (num < 10) {
        return convertirUnidad(num, false);
    } else if (num >= 10 && num < 20) {
        return convertirEspecial(num);
    } else {
        int decena = num / 10;
        int unidad = num % 10;
        if (unidad == 0) {
            return convertirDecena(decena);
        } else {
            return convertirDecena(decena) + " y " + convertirUnidad(unidad, false);
        }
    }
}

// Función para convertir números a palabras
string convertirNumeroAPalabras(double num) {
    string palabras;
    int parte_entera = static_cast<int>(num);
    int parte_decimal = round((num - parte_entera) * 100);

    if (parte_entera >= 200 && parte_entera <= 999) {
        int centenas = parte_entera / 100;
        palabras = convertirCentenaEspecial(centenas) + " ";
        parte_entera %= 100;
    }

    if (parte_entera == 500) {
        palabras = "quinientos";
    } else if (parte_entera == 900) {
        palabras = "novecientos";
    } else {
        int millones = parte_entera / 1000000;
        parte_entera %= 1000000;
        int miles = parte_entera / 1000;
        parte_entera %= 1000;
        int centenas = parte_entera / 100;
        parte_entera %= 100;
        int decenas = parte_entera / 10;
        int unidades = parte_entera % 10;

        if (millones > 0) {
            palabras += convertirDosCifras(millones) + " millones ";
        }
        if (miles > 0) {
            palabras += convertirDosCifras(miles) + " mil ";
        }
        if (centenas > 0) {
            palabras += convertirUnidad(centenas, true) + " ";
        }
        if (decenas > 0 || unidades > 0) {
            if (decenas == 2 && unidades > 0) {
                palabras += "veinti" + convertirUnidad(unidades, false);
            } else {
                palabras += convertirDosCifras(decenas * 10 + unidades);
            }
        }
    }

    if (parte_decimal > 0) {
        palabras += " punto ";
        if (parte_decimal < 10) {
            palabras += "cero " + convertirUnidad(parte_decimal, false);
        } else {
            int decimas = parte_decimal / 10;
            int centesimas = parte_decimal % 10;
            palabras += convertirUnidad(decimas, false) + " " + convertirUnidad(centesimas, false);
        }
    }

    palabras += " ";
    return palabras;
}

int main() {
    double numero;
    cout << "Ingrese un numero con decimal: ";
    cin >> numero;

    cout << "El numero en palabras es: " << convertirNumeroAPalabras(numero) << endl;

    return 0;
}

