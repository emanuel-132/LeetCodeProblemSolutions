#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Algoritmo de Ordenamiento por Ciclos (O(n) tiempo, O(1) espacio)
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Buscar el primer índice que no coincide
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};

int main() {
    Solution sol;
    int cantidad, valor;
    vector<int> nums;

    cout << "--- Primer Entero Positivo Faltante ---" << endl;
    cout << "Cuantos numeros quieres ingresar?: ";
    cin >> cantidad;

    cout << "Ingresa los " << cantidad << " numeros (pueden ser negativos o desordenados):" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> valor;
        nums.push_back(valor);
    }

    int resultado = sol.firstMissingPositive(nums);

    cout << "\n--------------------------------------" << endl;
    cout << "El primer entero positivo que falta es: " << resultado << endl;
    cout << "--------------------------------------" << endl;

    return 0;
}