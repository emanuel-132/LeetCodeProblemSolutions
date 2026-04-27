#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int k = 0; // Índice para los elementos que se quedan
        
        for (int i = 0; i < nums.size(); i++) {
            // Si el número que quiero eliminar no está 
            if (nums[i] != val) {
                nums[k] = nums[i]; // Se mueve para alfrente
                k++; // Aumenta el conteo
            }
        }
        return k; // Devuelve cantidad de los que quedan
    }
};

int main() {
    Solution sol;
    
    //Valores disponibles
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2, 5, 6, 7, 7};
    int val;

    cout << "Arreglo actual: ";
    for(int n : nums) cout << n << " ";
    
    cout << "\n\nIngresa el numero que quieres eliminar (val): ";
    cin >> val;

    int k = sol.removeElement(nums, val);

    // Resultados
    cout << "\nResultado k = " << k << endl;
    cout << "Arreglo modificado (primeros " << k << " elementos): ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}