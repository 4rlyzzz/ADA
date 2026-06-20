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

std::vector<int> delDupes (std::vector<int> &ar, int left, int right) {
    merge(ar, left, right);

    std::vector<int> res;
    res.push_back(ar[0]);

    for (int i = 1; i < ar.size(); i++) {
        if(ar[i] != ar [i - 1])
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