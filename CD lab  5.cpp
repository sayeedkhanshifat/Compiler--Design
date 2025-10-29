#include <iostream>
using namespace std;

double average(double arr[], int n)
{
    double sum = 0, avg;
    int i;

    for (i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    avg = sum / n;
    return avg;
}

int main()
{
    int i, n;
    cout << "Enter number of elements: ";
    cin >> n;

    double arr[n];
    cout << "Enter " << n << " numbers: ";

    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    double avg = average(arr, n);
    cout << "Average = " << avg << endl;

    return 0;
}
