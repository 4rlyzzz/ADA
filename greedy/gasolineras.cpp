#include <iostream>
#include <vector>
#include <algorithm>

struct comp {
    bool operator () (int a, int b) {
        return a > b;
    }
};

void greedy (std::vector<int>& gas, int disTotal, int distMax) {
    std::vector<int> tt = gas;

    int temp = 0;
    for (int j = 0; j < gas.size(); j++) {
        if(temp + tt[j] < distMax) {
            temp += tt[j];
            
            continue;
        }
        std::cout << "paro en la gasolinera " << j << " - " << gas[j] << "(" << tt[j] << ")" << std::endl;
        temp = 0;

        for (int k = j + 1; k < gas.size(); k++) {
            tt[k] = tt[k] - tt[j];
        }
    }
}

int main () {
    std::vector<int> gas = {100, 250, 380, 520, 640, 780, 900};
    int disTotal = 1000;
    int distMax = 400;

    greedy(gas, disTotal, distMax);
}