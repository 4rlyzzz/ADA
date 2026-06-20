#include <iostream>
#include <vector>

int partition(std::vector<int> &ar, int left, int right) {
    int valPivot = ar[left];
    int i = left + 1, j = right;

    while (i <= j) {
        while (i <= right && ar[i] <= valPivot)
            i++;
        while (j > left && ar[j] > valPivot)
            j--;

        if (i < j)
            std::swap(ar[i], ar[j]);
    }
    std::swap(ar[left], ar[j]);
    return j;
}

void quick(std::vector<int> &ar, int left, int right) {
    if (left >= right) 
        return;

    int mid = partition(ar, left, right);

    quick(ar, left, mid - 1);
    quick(ar, mid + 1, right);
}

int main() {
    std::vector<int> ar = {13, 1, 3, 5, 15, 4, 10, 6, 28, 30};

    quick(ar, 0, ar.size() - 1);

    for (auto &i : ar) 
        std::cout << i << " ";
}