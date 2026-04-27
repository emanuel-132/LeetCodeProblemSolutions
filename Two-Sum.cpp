#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapa;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complemento = target - nums[i];
            
            if (mapa.find(complemento) != mapa.end()) {
                return {mapa[complemento], i};
            }
            mapa[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;
    
    // Valores disponibles
    vector<int> nums = {2, 7, 11, 15};
    int target;

    cout<< "Valores actuales: {2, 7, 11, 15}\n";

    // Valor a buscar
    cout << "Ingresa el numero (target) que quieres buscar: ";
    cin >> target;

    vector<int> resultado = sol.twoSum(nums, target);

    if (!resultado.empty()) {
        cout << "Indices: [" << resultado[0] << ", " << resultado[1] << "]" << endl;
    } else {
        cout << "No se encontro ninguna combinacion para ese numero." << endl;
    }

    return 0;
}