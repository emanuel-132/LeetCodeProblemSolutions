#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> resultado = {-1, -1};
        
        // Buscar el limite izquierdo
        resultado[0] = buscarLimite(nums, target, true);
        
        // Si no existe el primero, no tiene sentido buscar el segundo
        if (resultado[0] != -1) {
            resultado[1] = buscarLimite(nums, target, false);
        }
        
        return resultado;
    }

private:
    int buscarLimite(vector<int>& nums, int target, bool buscarIzquierda) {
        int inicio = 0;
        int fin = nums.size() - 1;
        int indice = -1;

        while (inicio <= fin) {
            int medio = inicio + (fin - inicio) / 2;

            if (nums[medio] == target) {
                indice = medio; // Guarda la posicion encontrada
                if (buscarIzquierda) {
                    fin = medio - 1; // Se intenta encontrar uno mas a la izquierda
                } else {
                    inicio = medio + 1; //Intenta encontrar uno mas a la derecha
                }
            } else if (nums[medio] < target) {
                inicio = medio + 1;
            } else {
                fin = medio - 1;
            }
        }
        return indice;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target;

    cout << "Arreglo: [5, 7, 7, 8, 8, 10]" << endl;
    cout << "Ingresa el numero a buscar: ";
    cin >> target;

    vector<int> res = sol.searchRange(nums, target);

    cout << "Rango: [" << res[0] << ", " << res[1] << "]" << endl;

    return 0;
}