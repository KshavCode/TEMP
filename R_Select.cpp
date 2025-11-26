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

int randomisedSelect(vector<int> &A, int p, int r, int i)
{
    if (p == r){
        return A[p];
    }
    int q = randomisedPartition(A, p, r);

    int k = q - p + 1;
    if (i == k){
        return A[q];
    }
    else if (i < k){
        return randomisedSelect(A, p, q - 1, i);
    }
    else{
        return randomisedSelect(A, q + 1, r, i - k);
    }
}

int main()
{
    vector<int> A = {20, 13, 4, 11, 6, 17, 8, 19, 2};
    int n = A.size();
    int i = 7;

    int result = randomisedSelect(A, 0, n - 1, i);

    cout << i << "-th smallest element: " << result << "\n";
    cout << "Number of comparisons: " << comparisons << "\n";

    return 0;
}
