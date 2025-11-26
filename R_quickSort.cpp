#include <bits/stdc++.h>
using namespace std;

int comparisons = 0;

int partition(vector<int> &A, int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        comparisons++;
        if (A[j] <= x)
        {
            i = i + 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return (i + 1);
}

int randomisedPartition(vector<int> &A, int p, int r)
{
    int j = p + rand() % (r - p + 1);
    swap(A[r], A[j]);
    return partition(A, p, r);
}

void quickSort(vector<int> &A, int p, int r)
{
    if (p < r)
    {
        int q = randomisedPartition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main()
{
    vector<int> A = {10, 7, 8, 9, 1, 5};
    int n = A.size();

    quickSort(A, 0, n - 1);

    cout << "Sorted array : ";
    for (int x : A)
        cout << x << " ";
    cout << "\n";

    cout << "Number of comparisons: " << comparisons << "\n";

    return 0;
}
