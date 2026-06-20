#include <iostream>
#include <vector>

void search(std::vector<int> &ar, int left, int right) {
    if (left > right)
        return;

    int mid = left + (right - left) / 2;

    if (ar[mid] == mid) {
        std::cout << "en el indice " << mid << " el valor es " << ar[mid] << "\n";
    } 
    if (left <= mid - 1) {
        search(ar, left, mid - 1);
    }
    if (mid + 1 <= right) {
        search(ar, mid + 1, right);
    }
}

int main() {
    std::vector<int> ar = {0, 1, 2, 5, 4, 10, 12, 3, 6, 1, 9, 11};

    search(ar, 0, ar.size() - 1);
}