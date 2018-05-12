// code_report Solution
// 

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
