In the bustling city of Puzzleville, a young prodigy 
named Zoey stumbled upon a mysterious challenge left 
by a renowned puzzle master. Determined to solve it, 
she attempted to arrange the pieces in unique combinations
that would sum up to a magic number provided by the 
puzzle master. The rules were simple: no piece could
be used more than once in a combination. 
Zoey's mission was to crack the puzzle and reveal the 
secret prize.

To help Zoey, we need to find the number of unique 
combinations that are possible. Here's how we can 
approach this problem:

1. **Input**:
   - The first line contains two positive integers: 
   \(N\), representing the number of pieces, and \(K\), 
   representing the magic number.
   - The next line contains \(N\) positive integers, 
   \(A[]\), representing the pieces.

2. **Output**:
   - Print the number of combinations that are possible.

3. **Constraints**:
   - \(2 \leq N \leq 10^5\)
   - \(2 \leq K \leq N\)

Now, let's break down the solution:

//code

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int countCombinations(vector<int>& pieces, int targetSum,
 int currentIndex, int currentSum) {
    // Base case: if the current sum equals the target sum, 
    //return 1
    if (currentSum == targetSum) {
        return 1;
    }

    // Base case: if the current index exceeds the number 
    //of pieces, return 0
    if (currentIndex >= pieces.size()) {
        return 0;
    }

    // Recursive case: try including the current piece
    // in the combination
    int includeCount = countCombinations(pieces, targetSum, 
    currentIndex + 1, currentSum + pieces[currentIndex]);

    // Recursive case: try excluding the current piece
    // from the combination
    int excludeCount = countCombinations(pieces, targetSum, 
    currentIndex + 1, currentSum);

    // Return the total count of combinations
    return includeCount + excludeCount;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> pieces(N);
    for (int i = 0; i < N; ++i) {
        cin >> pieces[i];
    }

    int combinationsCount = countCombinations(pieces, K, 0, 0);

    cout << combinationsCount << endl;

    return 0;
}
