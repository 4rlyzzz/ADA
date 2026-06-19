#include <iostream>
#include <vector>

void binaria(int idx, std::vector<int> &pesos, std::vector<int> &benef, int capacidad,
             std::vector<int> &res, std::vector<int> &temp,
             int capTemp, int &benMax, int currentBen) {

    if(capTemp > capacidad)
        return;
    if(idx >= pesos.size()) {
        if(currentBen > benMax){
            benMax = currentBen;
            res = temp;
        }
        return;
    }

    temp.push_back(idx);
    binaria(idx + 1, pesos, benef, capacidad, res, temp, capTemp + pesos[idx], benMax, currentBen + benef[idx]);
    temp.pop_back();
    binaria(idx + 1, pesos, benef, capacidad, res, temp, capTemp, benMax, currentBen);
}

void combinatoria(int idx, std::vector<int> &pesos, std::vector<int> &benef, int capacidad,
                  std::vector<int> &res, std::vector<int> &temp,
                  int capTemp, int &benMax, int currentBen) {
    if(capTemp > capacidad)
        return;
    else {
        if(currentBen > benMax){
            benMax = currentBen;
            res = temp;
        }
    }

    for (int i = idx; i < pesos.size(); i++){
        temp.push_back(idx);
        combinatoria(i + 1, pesos, benef, capacidad, res, temp, capTemp + pesos[idx], benMax, currentBen + benef[idx]);
        temp.pop_back();
    }
}

int main() {
    /* 
    std::vector<int> pesos = { 1, 3, 4, 5, 2 };
    std::vector<int> beneficios = { 1, 4, 5, 7, 3 };
    int capacidad = 7;

    std::vector<int> pesos = { 2, 3, 4 };
    std::vector<int> beneficios = { 4, 5, 6 };
    int capacidad = 5;

    std::vector<int> pesos = {1,11,21,23,33};
    std::vector<int> beneficios = {11,21,31,33,43};
    int capacidad = 61;
    */
    std::vector<int>  pesos = {3, 7, 4, 2, 1, 6};
    std::vector<int> beneficios = {12, 3, 7, 4, 3, 8};
    int capacidad = 15;

    std::vector<int> res;
    std::vector<int> temp;
    int benMax = 0;

    binaria(0, pesos, beneficios, capacidad, res, temp, 0, benMax, 0);

    int pesoTotal = 0;
    
    for (int i : res) {
        std::cout << "Objeto [" << i << "] -> Peso: " << pesos[i] 
                  << ", Beneficio: " << beneficios[i] << std::endl;
        pesoTotal += pesos[i];
    }
    std::cout << "\nCapacidad total usada: " << pesoTotal << "/" << capacidad << std::endl;
    std::cout << "Beneficio maximo total: " << benMax << std::endl;

    ///////////

    res.clear(); 
    temp.clear(); 
    benMax = 0;

    combinatoria(0, pesos, beneficios, capacidad, res, temp, 0, benMax, 0);

    pesoTotal = 0;
    
    for (int i : res) {
        std::cout << "Objeto [" << i << "] -> Peso: " << pesos[i] 
                  << ", Beneficio: " << beneficios[i] << std::endl;
        pesoTotal += pesos[i];
    }
    std::cout << "\nCapacidad total usada: " << pesoTotal << "/" << capacidad << std::endl;
    std::cout << "Beneficio maximo total: " << benMax << std::endl;

}