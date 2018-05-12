// code_report Solution
// https://youtu.be/AKy69exa5Cc

#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main ()
{
   int n; cin >> n;
   multimap<int, int> m;
   while (n--) {
      int a, b; cin >> a >> b;
      m.insert ({ a, b });
   }

   priority_queue<int> ends;

   int x = 0, y = 0; // x = min_candies, y = max_students

   for (auto& e : m) {
      ends.push (-e.second);
      while (-ends.top () < e.first) ends.pop ();
      if (ends.size () > y) y = ends.size (), x = e.first;
   }

   cout << x << " " << y << endl;

   return 0;
}

// Alternate solution

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
   int n; cin >> n;
   vector<pair<int,bool>> v;
   while (n--) {
      int a, b; cin >> a >> b;
      v.push_back ({ a, true });
      v.push_back ({ b+1, false});
   }

   sort (v.begin (), v.end ());

   int x = 0, y = 0, sum = 0;

   for (auto& e : v) {
      sum += e.second ? 1 : -1;
      if (sum > y) y = sum, x = e.first;
   }

   cout << x << " " << y << endl;

   return 0;
}
