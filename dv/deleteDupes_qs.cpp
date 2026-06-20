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

std::vector<int> delDupes(std::vector<int>& ar, int left, int right){
    quick(ar, left, right);

    std::vector<int> res;
    res.push_back(ar[0]);

    for (int i = 1; i < ar.size(); i++) {
        if(ar[i] != ar[i - 1])
            res.push_back(ar[i]);
    }
    return res;
}

int main() {
    std::vector<int> ar = {4, 2, 9, 2, 4, 1, 9, 5, 3, 3, 4, 7, 7, 4};

    ar = delDupes(ar, 0, ar.size() - 1);

    for (auto &i : ar) 
        std::cout << i << " ";
}