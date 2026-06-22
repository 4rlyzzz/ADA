#include <iostream>
#include <vector>
#include <algorithm>

struct comp {
    bool operator () (int& a, int& b) {
        return a < b;
    }
};

struct comp_2 {
    bool operator () (int& a, int& b) {
        return a > b;
    }
};

// maximizar numero de programas almacenados
void greedy (std::vector<int>& prog, int disk) {
    std::sort(prog.begin(), prog.end(), comp());

    int temp = 0;
    for (int i = 0; i < prog.size(); i++) {
        if(temp + prog[i] > disk)
            continue;
        temp += prog[i];
        std::cout << prog[i] << " ";
    }
}

// maximizar la capacidad maxima
void greedy_2 (std::vector<int>& prog, int disk) {
    std::sort(prog.begin(), prog.end(), comp_2());

    int temp = 0;
    for (int i = 0; i < prog.size(); i++) {
        if(temp + prog[i] > disk) 
            continue;
        temp += prog[i];
        std::cout << prog[i] << " ";
    }
}

int main() {
    std::vector<int> programs1 = { 10, 25, 5, 50 };
    int disk1 = 30;

    greedy(programs1, disk1);
    std::cout << "\n\n";
    greedy_2(programs1, disk1);
}