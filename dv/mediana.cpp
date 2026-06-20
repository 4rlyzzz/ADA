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

void quick (std::vector<int>& ar, int left, int rigth, int mediana) {
    if(left >= rigth) {
        std::cout << "mediana = " << ar[left] << "\n";
        return;
    }

    int mid = partition(ar, left, rigth);

    if (mediana == mid) {
        std::cout << "mediana = " << ar[mid] << "\n";
        return;
    }
    else if (mediana < mid)
        quick(ar, left, mid - 1, mediana);
    else
        quick(ar, mid + 1, rigth, mediana);
}

int main() {
    std::vector<int> ar = {13, 1, 3, 5, 15, 4, 10, 6, 28, 30};
    int mediana = ar.size() / 2;
    
    quick(ar, 0, ar.size() - 1, mediana);

    for (auto &i : ar) 
        std::cout << i << " ";
}