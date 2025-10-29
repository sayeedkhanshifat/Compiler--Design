#include <iostream>
using namespace std;

void findMinMax(double arr[], int size) {
    double min = arr[0];
    double max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "Minimum value = " << min << endl;
    cout << "Maximum value = " << max << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    double arr[n];
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    findMinMax(arr, n);

    return 0;
}

