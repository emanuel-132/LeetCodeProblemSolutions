#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanos = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            // Si el valor actual es menor que el siguiente, restamos
            if (i + 1 < n && romanos[s[i]] < romanos[s[i + 1]]) {
                total -= romanos[s[i]];
            } 
            // Si es igual o mayor (o es el último), sumamos
            else {
                total += romanos[s[i]];
            }
        }
        return total;
    }
};

int main() {
    Solution sol;
    string s;

    cout << "--- Traducción de Numeros Romanos ---" << endl;
    cout << "Ingresa un numero romano: ";
    cin >> s;

    int resultado = sol.romanToInt(s);

    cout << "El valor entero de " << s << " es: " << resultado << endl;

    return 0;
}
