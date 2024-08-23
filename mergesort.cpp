#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

void merge(int l, int m, int h) {
    int n1 = m - l + 1;
    int n2 = h - m;

    int a[n1], b[n2];
    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        b[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr[k++] = a[i++];
        } else {
            arr[k++] = b[j++];
        }
    }
    while (i < n1) {
        arr[k++] = a[i++];
    }
    while (j < n2) {
        arr[k++] = b[j++];
    }
}

void merge_sort(int l, int h) {
    if (l < h) {
        int mid = l + (h - l) / 2;
        merge_sort(l, mid);
        merge_sort(mid + 1, h);
        merge(l, mid, h);
    }
}

int main() {
    int n;
    cin >> n;
    
    arr.resize(n); // Resize the vector to accommodate n elements

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
