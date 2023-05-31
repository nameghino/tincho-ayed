#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

double leibniz(int n) {
	double numerador = pow(-1, n);
	double denominador = 2 * n + 1;
	return numerador / denominador;
}	

double sumatoria_leibniz(int hasta) {
	int i = 0;
	double a = 0;
	while (i < hasta) {
		a = a + leibniz(i);
		i = i + 1;
	}
	return a;
}

int main() {
	int veces = 0;
	char buf[32];
	cin >> veces;
	double a = sumatoria_leibniz(veces);
	snprintf(buf, sizeof(buf), "%.8f", a*4);
	cout << "hasta " << veces << " la aproximacion da " << buf << endl;
}
