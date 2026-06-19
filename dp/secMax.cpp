#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

void pd (std::vector<int>& ar) {
    std::vector<int> ar_temp = ar;
    std::sort(ar_temp.begin(), ar_temp.end());
    int size = ar.size(); 

    std::vector<std::vector<int>> v(size + 1, std::vector<int>(size + 1, 0));
    
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if(ar[i - 1] == ar_temp[j - 1])
                v[i][j] = 1 + v[i - 1][j - 1];
            else 
                v[i][j] = std::max(v[i - 1][j], v[i][j - 1]);
        }
    }

    // print
    for (int i = 0; i <= size; i++){
        for (int j = 0; j <= size; j++)
            std::cout << v[i][j] << "\t";
        std::cout << "\n";
    }
    std::cout << "\n";


    std::stack<int> res;
    for (int i = size, j = size; i > 0 && j > 0; ) {
        if(ar[i - 1] == ar_temp[j - 1]) {
            res.push(ar[i - 1]);
            i--, j--;
        }
        else {
            if(v[i - 1][j] >= v[i][j - 1])
                i--;
            else
                j--;
        }
    }

    // print
    while (!res.empty()) {
        std::cout << res.top() << " ";
        res.pop();
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> ar = { 11, 17, 5, 8, 6, 4, 7, 12, 3 };

    pd(ar);
}