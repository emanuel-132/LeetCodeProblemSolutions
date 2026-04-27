#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int inicio = 0;
        int fin = nums.size() - 1;

        while (inicio <= fin) {
            // Se calcula el medio de esta forma para evitar overflow
            int mitad = inicio + (fin - inicio) / 2;

            if (nums[mitad] == target) {
                return mitad;
            } else if (nums[mitad] < target) {
                inicio = mitad + 1;
            } else {
                fin = mitad - 1;
            }
        }

        // Si no se encuentra, 'inicio' es la posicion de insercion
        return inicio;
    }
};

int main() {
    Solution sol;
    
    // Arreglo ordenado 
    vector<int> nums = {1, 3, 5, 6, 7, 9};
    int target;

    cout << "Arreglo: [1, 3, 5, 6, 7, 9]" << endl;
    cout << "Ingresa el numero a buscar o insertar: ";
    cin >> target;

    int resultado = sol.searchInsert(nums, target);

    cout << "El indice es: " << resultado << endl;

    return 0;
}