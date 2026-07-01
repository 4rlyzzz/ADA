#include <iostream>
#include <vector>
#include <algorithm>

struct comp {
    bool operator () (std::pair<int, float> a, std::pair<int, float> b){
        if(a.first == b.first){
            return a.second > b.second;
        }        
        return a.first < b.first;
    }
};

// maximizar ganancias del camarero
void greedy(std::vector<std::pair<int, float>>& camarero) {
    std::sort(camarero.begin(), camarero.end(), comp());
    
    int i = 1;
    for (int j = 0; j < camarero.size(); j++) {
        if (camarero[j].first >= i) {
            std::cout << camarero[j].first << " " << camarero[j].second << "\n";
            i += camarero[j].first;
        }
    }
}

int main() {
    std::vector<std::pair<int, float>> camarero{{3, 0.33f}, {5,0.2f}, {2, 0.5f}, {8, 0.125f}, {2, 0.5f}, {1, 1.0f}, {9, 0.1f}};

    greedy(camarero);
}