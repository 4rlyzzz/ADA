#include <iostream>
#include <vector>
#include <algorithm>

struct comp {
    bool operator () (int a, int b) {
        return a < b;
    }
};

struct comp_2 {
    bool operator () (int a, int b) {
        return a > b;
    }
};

// maximizar el numero de contenedores
void greedy (std::vector<int>& pesos, int buqueSize) {
    std::vector<int> tempPesos = pesos;
    
    std::sort(pesos.begin(), pesos.end(), comp());
    for (auto& i : pesos) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    int temp = 0;
    for (int i = 0; i < pesos.size(); i++) {
        if(temp + pesos[i] > buqueSize)
            continue;
        temp += pesos[i];
        
        //std::cout << "contenedor " << i << ": " << pesos[i] << "\n";
        // 8, 2, 6, 3, 4, 5, 7
        for (int j = 0; j < pesos.size(); j++) {
            if(pesos[i] == tempPesos[j])
                std::cout << "contenedor " << j << ": " << pesos[i] << "\n";
        }
    }
}

// maximizar las toneldas cargadas
void greedy_2 (std::vector<int>& pesos, int buqueSize) {
    std::vector<int> tempPesos = pesos;


    std::sort(pesos.begin(), pesos.end(), comp_2());
    for (auto& i : pesos) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    int temp = 0;
    for (int i = 0; i < pesos.size(); i++) {
        if(temp + pesos[i] > buqueSize) 
            continue;
        temp += pesos[i];
        //std::cout << "contenedor " << i << ": " << pesos[i] << "\n";

        // 8, 2, 6, 3, 4, 5, 7
        for (int j = 0; j < pesos.size(); j++) {
            if(pesos[i] == tempPesos[j])
                std::cout << "contenedor " << j << ": " << pesos[i] << "\n";
        }

    }
}

int main() {
    int buqueSize = 17;

    std::vector<int> p1 = { 10, 25, 5, 50 };
    std::vector<int> p2 = { 20, 10, 25, 3 };
    std::vector<int> p3 = { 8, 2, 6, 3, 4, 5, 7 };
    
    greedy(p3, buqueSize);
    std::cout << "\n";

    p3 = { 8, 2, 6, 3, 4, 5, 7 };
    greedy_2(p3, buqueSize);
}