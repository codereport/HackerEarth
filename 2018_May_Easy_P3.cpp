// code_report
// 

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void magic_potion (int n, long long k, const vector<int>& v)
{
   int beg = 0, end = 0, x = n; // x = minimum deleted
   long long sum = 0, y = 0;    // y = count of arrays

   auto calc = [&]() 
   {
      long long zl = 0, zr = 0; // zl = zeroes to the left, zr = zero to the right
      int a_orig = beg; 

      while (beg < n && v[beg] == 0) zl++, beg++;
      while (end < n && v[end] == 0) zr++, end++;

      y += (zl + 1) * (zr + 1);
      x = min (x, n - (end - a_orig));
   };

   while (end < n)
   {
      while (end < n && sum < k) sum += v[end], end++;
      if (sum == k) calc ();
      while (beg <= end && sum >= k) {
         sum -= v[beg], beg++;
         if (sum == k) calc ();
      }
   }

   cout << y << " " << x << endl;
}

int main ()
{
   int n; long long k; cin >> n >> k;
   vector<int> v (n);
   for (int i = 0; i < n; i++) cin >> v[i];

   magic_potion (n, k, v);

   return 0;
}
