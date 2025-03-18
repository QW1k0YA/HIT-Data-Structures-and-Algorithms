#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quicksort(vector<int> &a,long long l, long long r)
{
    long long i = l;
    long long j = r;
    long long mid = a[l + (r - l) / 2];
    do
    {
        while (a[i] < mid) i++;
        while (a[j] > mid) j--;
        if (i <= j)
        {
            int temp;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (i < r) quicksort(a,i, r);
    if (j > l) quicksort(a,l, j);
}


int main() {
    int n;
    cout << "Enter the number of positive integers in set A (n >= 2): ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter " << n << " positive integers for set A: ";
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    quicksort(A,0, A.size()-1);

    int sum1 = 0, sum2 = 0;
    vector<int> A1, A2;

    for(int i = 0;i < n/2;i++)
    {
        A1.push_back(A[i]);
        sum1 += A[i];
    }
    for(int i = n/2;i < n;i++)
    {
        A2.push_back(A[i]);
        sum2 += A[i];
    }
    ///若为奇数，中间的给A2(大的数组)

    int diff = abs(sum1 - sum2);

    cout << "Elements in A1: ";
    for (int num : A1) {
        cout << num << " ";
    }
    cout << "Sum: " << sum1 << endl;

    cout << "Elements in A2: ";
    for (int num : A2) {
        cout << num << " ";
    }
    cout << "Sum: " << sum2 << endl;

    cout << "Absolute difference between sums of two subsets: " << diff << endl;

    return 0;
}
