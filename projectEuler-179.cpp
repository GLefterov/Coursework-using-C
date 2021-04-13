// Vectors in C++ are much alike vectors in math - they're infinite(only limited by RAM) indexed arrays.

// This algorithm goes the opposite way - instead of finding a number's divisors, we're searching their multipliers
// and then we're counting the multipliers(as divisors). This algorithm saves a lot of time and resources. Dividing every
// single number and then checking if its an integer would take up to 50% more resources(time, RAM).

// The nested loops go through all pairs(i, n) where i*n < 10 000 000, incrementing divisors[i*q].


//The following code is a solution to projecteuler.net problem 179.    https://projecteuler.net/problem=179
//@author G_Lefterov

#include <iostream>
#include <vector>

using namespace std;

int main()
{
//5 000 000 + 5 000 0000
 int limit = 10000000;

vector<int> divisors(limit, 0);

  //numbers that can be a divisor ...
  for (int i = 1; i <= limit / 2; i++)
    //all numbers multiples
    for ( int q = i; q <= limit; q += i)
      divisors[q]++;

      vector< int> count(limit + 1, 0);
  // count numbers whose bigger neighbors has the same number of divisors
  for ( int i = 2; i < limit; i++)
  {
    count[i] = count[i - 1];
    if (divisors[i] == divisors[i + 1])
      count[i]++;
  }

cout << count[9999999] << endl;




  return 0;
}
