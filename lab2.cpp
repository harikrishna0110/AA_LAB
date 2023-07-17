//Implement Randomized Primality Testing using Fermat's Theorem
#include <bits/stdc++.h>
using namespace std;


/* Iterative Function to calculate (a^n)%p in O(logy) */
int power(unsigned long long int a, unsigned long long int n, int p)
{
   unsigned int res = 1;    // Initialize result
   a = a % p; // Update 'a' if 'a' >= p


   while (n > 0)
   {
       // If n is odd, multiply 'a' with result
       if (n & 1)
           res = (res*a) % p;


       // n must be even now
       n = n>>1; // n = n/2
       a = (a*a) % p;
   }
   return res;
}


/*Recursive function to calculate gcd of 2 numbers*/
// int gcd(int a, int b)
// {
//  if(a < b)
//      return gcd(b, a);
//  else if(a%b == 0)
//      return b;
//  else return gcd(b, a%b);


// }


//ietrative gcd code
int gcd(int a, int b)
{
   int r;
   while(b > 0)
   {
       r=a%b;
       a=b;
       b=r;
   }
  
   return a;
}


// If n is prime, then always returns true, If n is
// composite than returns false with high probability
// Higher value of k increases probability of correct
// result.
bool isPrime(unsigned long long int n, int k)
{
// Corner cases
if (n <= 1 || n == 4) return false;
if (n <= 3) return true;


// Try k times
while (k>0)
{
   // Pick a random number in [2..n-2]
   // Above corner cases make sure that n > 4
   int a = 2 + rand()%(n-3);
   //cout << (rand() % (ub - lb + 1)) + lb << " ";


   // Checking if a and n are co-prime
   if (gcd(n, a) != 1)
       return false;


  
   if (power(a, n-1, n) != 1)
       return false;


   k--;
   }


   return true;
}


// Driver Program to test above function
int main()
{
   int k = 3;
   isPrime(1000000007, k)? cout << " true\n": cout << " false\n";
   isPrime(5, k)? cout << " true\n": cout << " false\n";
   return 0;
}










