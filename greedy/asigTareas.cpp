#include <iostream>
#include <vector>
#include <algorithm>

struct comp {
    bool operator () (std::pair<int,int> a, std::pair<int,int> b) {
        if (a.second != b.second)
            return a.second < b.second;
        return a.first > b.first;
    }
};

// mayor beneficio en plazos de tarea
void greedy (std::vector<std::pair<int,int>>& ben_plazo) {
    std::vector<std::pair<int,int>> temp = ben_plazo;
    std::sort(temp.begin(), temp.end(), comp());

    for (int i = 0, j = 0; j < ben_plazo.size(); j++) {
        if(i + 1 != temp[j].second) {
            continue;
        }
        std::cout << temp[j].first << " " << temp[j].second << "\n";
        i++;
    }
}

int main() {
    std::vector<std::pair<int,int>> ben_plazo = { {50,2}, {10,1}, {15,2}, {30,1} };

    greedy(ben_plazo);
    std::cout << "\n";
}