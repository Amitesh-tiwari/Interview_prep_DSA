Problem Statement: Given a geometric Progression (G.P) 
sequence with some inputs as:-

a, first term
r, common ratio
n, number of terms

//code
float SumofGP(float a, float r, int n)
{
  float sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum = sum + a;
    a = a * r;
  }
  return sum;
}