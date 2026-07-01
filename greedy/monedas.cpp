#include <iostream>
#include <vector>
#include <algorithm>

struct comp {
    bool operator () (float a, float b) {
        return a > b;
    }
};

void greedy(std::vector<float>& mon, float monto) {
    std::sort(mon.begin(), mon.end(), comp());

    float temp = monto;
    for (int i = 0; i < mon.size() && temp > 0; i++) {
        int cont = temp / mon[i];
        temp -= cont * mon[i];
        std::cout << mon[i] << ": " << cont << "\n";
    }
}

int main() {
    std::vector<float> mon = { 0.01, 0.02, 0.05, 0.10, 0.20, 0.50, 1 };

    float monto = 3.89;
    greedy(mon, monto);
}