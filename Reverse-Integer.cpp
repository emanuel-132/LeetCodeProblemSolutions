#include <iostream>
#include <climits> // Librería para para INT_MAX e INT_MIN

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            // Verificación de desbordamiento positivo
            // Si rev > INT_MAX/10, al multiplicar por 10 desbordará.
            // Si rev == INT_MAX/10, desbordará si pop > 7.
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;

            // Verificación de desbordamiento negativo
            // Si rev < INT_MIN/10, al multiplicar por 10 desbordará.
            // Si rev == INT_MIN/10, desbordará si pop < -8.
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;

            rev = rev * 10 + pop;
        }
        return rev;
    }
};

int main() {
    Solution sol;
    int x;

    cout << "Ingresa un numero entero: ";
    cin >> x;

    int resultado = sol.reverse(x);

    if (resultado == 0 && x != 0) {
        cout << "Error: Desbordamiento de 32 bits (0)" << endl;
    } else {
        cout << "Numero invertido: " << resultado << endl;
    }

    return 0;
}