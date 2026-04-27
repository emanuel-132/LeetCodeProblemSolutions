#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        // Si la aguja es más larga que el pajar, jamás la encontrará
        if (m > n) return -1;

        // Recorremos el haystack hasta donde sea posible que quepa la aguja
        for (int i = 0; i <= n - m; i++) {
            // Comparamos la subcadena que empieza en 'i' con el 'needle'
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    
    // Haystack fijo
    string haystack = "sadbutsad";
    string needle;

    cout << "Haystack actual: \"" << haystack << "\"" << endl;
    cout << "Ingresa la palabra a buscar (needle): ";
    cin >> needle;

    int resultado = sol.strStr(haystack, needle);

    if (resultado != -1) {
        cout << "¡Encontrado! La primera ocurrencia esta en el indice: " << resultado << endl;
    } else {
        cout << "La aguja no se encuentra en el pajar (-1)." << endl;
    }

    return 0;
}