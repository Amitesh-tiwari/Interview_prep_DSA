Given an array A of N positive integers and integer M. 
Your task is to pick M integers from Array A to an Array B 
such that the fucntion F given below gives the least 
possible value.

F(B) = Max(B) - Min(B)

//code
int MinimizeF(int A[], int N, int M)
{
  int min = INT_MAX;
  sort(A, A + N);
  for (int i = 0; i <= N - M; i++)
  {
    if (A[i + M - 1] - A[i] < min)
    {
      min = A[i + M - 1] - A[i];
    }
  }
  return min;
}