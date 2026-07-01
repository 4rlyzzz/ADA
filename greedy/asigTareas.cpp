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

    int i = 1;
    for (int j = 0; j < ben_plazo.size(); j++) {
        if(i != temp[j].second) {
            continue;
        }

        for (int k = 0; k < ben_plazo.size(); k++) {
            if(ben_plazo[k].first == temp[j].first && ben_plazo[k].second == temp[j].second) {
                std::cout << "tarea" << k + 1 << " - " << temp[j].first << " " << temp[j].second << "\n";
            }
        }

        i++;
    }
}

int main() {
    std::vector<std::pair<int,int>> ben_plazo = { {50,2}, {10,1}, {15,2}, {30,1} };

    greedy(ben_plazo);
    std::cout << "\n";
}