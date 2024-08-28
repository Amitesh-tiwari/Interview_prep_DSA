The first line of input contains integers N and K 
separated by a space. The next lines contain N numbers
of positive integers A[] which denotes the room number
available to be used.
Output
Print the largest minimum distance that can be maintained
between the rooms.

Sample input
5 3
1 2 4 8 9

Sample output
3

//code
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int l = 1, r = a[n - 1] - a[0];
    while (l < r) {
        int mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            cnt += (a[i] - a[i - 1] - 1) / mid;
        }
        if (cnt > k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
    }
