#include <iostream>
#include <vector>

int partition (std::vector<int>& ar, int left, int rigth) {
    int valPivot = ar[left];
    int i = left + 1, j = rigth;

    while (i <= j) {
        while (i <= rigth && ar[i] <= valPivot)
            i++;
        while (j > left && ar[j] > valPivot)
            j--;

        if (i < j)
            std::swap(ar[i], ar[j]);
    }
    std::swap(ar[left], ar[j]);
    return j;
}

void quick (std::vector<int>& ar, int left, int rigth, int k_esimo) {
    if(left >= rigth) {
        std::cout << "k_esimo = " << ar[left] << "\n";
        return;
    }

    int mid = partition(ar, left, rigth);

    if (k_esimo == mid) {
        std::cout << "k_esimo = " << ar[mid] << "\n";
        return;
    }
    else if (k_esimo < mid)
        quick(ar, left, mid - 1, k_esimo);
    else
        quick(ar, mid + 1, rigth, k_esimo);
}

int main() {
    std::vector<int> ar = {13, 1, 3, 5, 15, 4, 10, 6, 28, 30};
    int k_esimo = 6;
    
    quick(ar, 0, ar.size() - 1, k_esimo);

    for (auto &i : ar) 
        std::cout << i << " ";
}