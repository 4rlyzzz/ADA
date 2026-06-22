#include <iostream>
#include <vector>

void permutacional (int idx, std::vector<int>& mon, int vuelto, std::vector<int>& res, std::vector<int>& temp, int sumCurrent) {
    if(sumCurrent > vuelto) {
        return;
    } 
    if(sumCurrent == vuelto) {
        if(res.empty() || (int) temp.size() < (int) res.size()) {
            res = temp;
        }
        return;
    }

    for (int i = 0; i < mon.size(); i++) {
        temp.push_back(i);
        permutacional(i, mon, vuelto, res, temp, sumCurrent + mon[i]);
        temp.pop_back();
    }
}

void n_arios (int idx, std::vector<int>& mon, int vuelto, std::vector<int>& res, std::vector<int>& temp, int sumCurrent) {
    if(sumCurrent > vuelto) {
        return;
    }
    if(sumCurrent == vuelto) {
        if(res.empty() || (int) temp.size() < (int) res.size()) {
            res = temp;
        }
        return;
    }

    temp.push_back(idx);
    n_arios(idx, mon, vuelto, res, temp, sumCurrent + mon[idx]);
    temp.pop_back();
    n_arios(idx + 1, mon, vuelto, res, temp, sumCurrent);
}

int main() {
    std::vector<int> monedas = { 1, 2, 5 };
    int vuelto = 5;
    std::vector<int> res;
    std::vector<int> temp;

    permutacional(0, monedas, vuelto, res, temp, 0);

    for (int m : res) {
        //std::cout << m << " ";
        std::cout << monedas[m] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    ///
    res.clear(); 
    temp.clear(); 

    n_arios(0, monedas, vuelto, res, temp, 0);

    for (int m : res) {
        //std::cout << m << " ";
        std::cout << monedas[m] << " ";
    }
    std::cout << std::endl;
}