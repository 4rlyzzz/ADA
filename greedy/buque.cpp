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
        std::cout << "contenedor " << i << ": " << pesos[i] << "\n";
    }
}

// maximizar las toneldas cargadas
void greedy_2 (std::vector<int>& pesos, int buqueSize) {
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
        std::cout << "contenedor " << i << ": " << pesos[i] << "\n";

    }
}

int main() {
    int buqueSize = 30;

    std::vector<int> p1 = { 10, 25, 5, 50 };
    std::vector<int> p2 = { 20, 10, 25, 3 };
    std::vector<int> p3 = { 8, 7, 6, 5, 4, 3, 2 };

    greedy(p3, buqueSize);
    std::cout << "\n";
    greedy_2(p3, buqueSize);
}