#include <iostream>
#include <vector>

int inf = 99999;

void pd (std::vector<int> &monedas, int cambio) {
    int size_i_moneda = monedas.size();
    std::vector<std::vector<int>> v(size_i_moneda + 1, std::vector<int>(cambio + 1, inf));

    for (int i = 0; i <= size_i_moneda; i++) {
        v[i][0] = 0;
    }

    for (int i = 1; i <= size_i_moneda; i++) {
        for (int j = 1; j <= cambio; j++) {
            int moneda_temp = monedas[i - 1];

            if(j < moneda_temp)
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = std::min(v[i - 1][j], 1 + v[i][j - moneda_temp]);
        }
    }

    // print
    for (int i = 0; i <= size_i_moneda; i++){
        for (int j = 0; j <= cambio; j++)
            std::cout << v[i][j] << "\t";
        std::cout << "\n";
    }
    std::cout << "\n";

    int j = cambio;
    for (int i = size_i_moneda; i > 0 && j > 0; ) {
        if(v[i][j] == v[i - 1][j])
            i--;
        else {
            std::cout << "moneda = " << monedas[i - 1] << "\n";
            j -= monedas[i - 1];
        }
    }
}

int main() {
    std::vector<int> monedas = { 1, 2, 5, 10, 20, 50, 100 };
    int cambio = 390;

    pd(monedas, cambio);
}