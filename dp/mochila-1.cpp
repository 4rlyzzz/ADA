#include <iostream>
#include <vector>

void pd (std::vector<int>& peso, std::vector<int>& benef, int capacidad) {
    int size_i_obj = peso.size();
    std::vector<std::vector<int>> v(size_i_obj + 1, std::vector<int>(capacidad + 1, 0));

    for (int i = 1; i <= size_i_obj; i++){
        for (int j = 1; j <= capacidad; j++){
            int peso_temp = peso[i - 1];
            int benef_temp = benef[i - 1];

            if(j < peso_temp)
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = std::max(v[i - 1][j], benef_temp + v[i - 1][j - peso_temp]);
        }
    }

    // print
    for (int i = 0; i <= size_i_obj; i++){
        for (int j = 0; j <= capacidad; j++)
            std::cout << v[i][j] << "\t";
        std::cout << "\n";
    }
    std::cout << "\n";

    int j = capacidad;
    //std::vector<int> res(size_i_obj, 0);
    for (int i = size_i_obj; i > 0; i--){
        if(v[i][j] == v[i - 1][j])
            continue;
        else {
            //res[i - 1] = 1;
            std::cout << "obj" << i << "= " << peso[i-1] << "\n";
            j -= peso[i - 1];
        }
    }
}

int main() {
    //std::vector<int>  peso = {3, 7, 4, 2, 1, 6};
    //std::vector<int> benef = {12, 3, 7, 4, 3, 8};
    std::vector<int> peso = {2, 3, 4};
    std::vector<int> benef = {1, 2, 5};
    //int capacidad = 15;
    int capacidad = 6;

    pd(peso, benef, capacidad);
}