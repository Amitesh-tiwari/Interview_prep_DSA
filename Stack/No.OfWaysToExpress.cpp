You are the Librarian of the Ninja library. There are ‘N’
books available in the library and ‘B’ ninjas want to 
read the books. You know the number of pages in each book 
and you have to allocate the books to the ‘B’ ninjas in
such a way that the maximum number of pages allocated
to a ninja is minimum.

Note

A book will be allocated to exactly one ninja. 
At least one book has to be allocated to a ninja.
Allotment of the books should be done in a contiguous
manner. For example, a ninja can not be allocated book 2 
and book 4, skipping book 3.
The task is to return the minimum of the maximum number 
of pages allocated to a ninja


//code

#include <bits/stdc++.h> 

bool isPossible(vector<int> &pages, int n, int b, int maxPages) {
    int studentsRequired = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (pages[i] > maxPages) {
            return false;
        }

        if (currentSum + pages[i] > maxPages) {
            studentsRequired++;
            currentSum = pages[i];

            if (studentsRequired > b) {
                return false;
            }
        } else {
            currentSum += pages[i];
        }
    }

    return true;
}

int allocateBooks(vector<int> &pages, int n, int b)
{
	if (b > n)
        return -1;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += pages[i];
    int low = 0, high = sum, res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(pages, n, b, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}
