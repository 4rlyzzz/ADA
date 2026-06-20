#include <iostream>
#include <vector>

void mergesort (std::vector<int>& ar, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> l(n1), r(n2);

    for (int i = 0; i < n1; i++)
        l[i] = ar[left + i];
    for (int j = 0; j < n2; j++)
        r[j] = ar[mid + j + 1];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(l[i] <= r[j]) {
            ar[k] = l[i];
            i++;
        } else {
            ar[k] = r[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        ar[k] = l[i];
        i++, k++;
    }
    while(j < n2) {
        ar[k] = r[j];
        j++, k++;
    }
}

void merge(std::vector<int> &ar, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    merge(ar, left, mid);
    merge(ar, mid+1, right);

    mergesort(ar, left, mid, right);
}

int main() {
    std::vector<int> ar = {9, 1, 3, 5, 0, 4, 2, 6, 8, 7};

    merge(ar, 0, ar.size() - 1);

    for (auto &i : ar)
        std::cout << i << " ";
}