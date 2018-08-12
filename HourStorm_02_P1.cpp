// code_report Solution
// https://youtu.be/LV6DTbLBL8M

#include <algorithm>
#include <iostream>

using namespace std;

int main ()
{
   int x, y, s, t, c = 0;
   cin >> x >> y >> s >> t;

   for (int i = 0, j = t; i <= t; ++i, --j) {
      if (j >= y && j <= y + s) {
         c += min (max (0, i - x + 1), s + 1);
      }
   }

   cout << c << endl;

   return 0;
}
