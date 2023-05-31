#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int main() {

    // leibnitz
    // 1 - 1/3 + 1/5 - 1/7 + 1/9... = pi/4

    // acumulador donde vamos guardando la aproximacion
    double a = 0;

    // contador para saber en que iteracion estamos
    double i = 0;

    // aca voy a guardar el string para comparar, porque comparar entre numeros reales es muy hinchahuevos
    char cmp[32];
    char buf[64]; 
    
    // la condicion de salida del loop es encontrar la aproximacion de pi con 6 decimales correctos
    // yo soy mas de hacer while(true) y resolver el fin del ciclo adentro
    while(true) {

        // la pagina que referencia el TP a la serie de leibniz tiene la formula
        // pow(base, exponente) esta definido en el encabezado cmath
        a += pow(-1, i) / ((2 * i ) + 1);

        // snprintf te sirve para formatear strings. no se que version de C++ estan usando, esto es lo que se hacia en 2005.
        snprintf(buf, sizeof(buf), "#%8.0lf -> %.6lf", i, 4*a);
        snprintf(cmp, sizeof(cmp), "%.6lf", 4*a);

        // para ir viendo como progresa la aproximacion
        if (int(i) % 100000 == 0) {
            cout << buf << " (" << cmp << ")" << endl;
        }
        
        // aca comparo el string que hice arriba con el resultado que buscamos para saber si hay que terminar
        // strncmp compara los strings y te devuelve un entero segun que string va primero
        // si es negativo, el primer string va primero -> strncmp("A", "B") va a devolver -1 o algo asi
        // si es positivo, el segundo string va primero -> strncmp("B", "A") va a devolver 1 o algo asi
        // si es cero, son iguales -> strcnmp("A", "A") va a devolver 0
        if (strncmp(cmp, "3.141592", 8) == 0) {
            // si son iguales, fin de loop, salimos!
            break;
        }

        // a la siguiente iteracion
        i += 1;
    }
    cout << buf << " (" << cmp << ")" << endl;
    return 0;
}