// code_report Solution
// 

#include <algorithm>
#include <iostream>
#include <set>
#include <map>

using namespace std;

int main () {

   int n, max_side = 0; cin >> n;
   map<int, set<int>> m;
   for (int i = 0; i < n; ++i) {
      int a, b; cin >> a >> b;
      m[a].insert (b);
   }

   auto ans = make_pair (numeric_limits<int>::max (),
                         numeric_limits<int>::max ());

   for (auto it = m.begin (); it != m.end (); ++it) {
      int x1 = it->first;
      const auto& ys = m[x1];
      for (auto y1 = ys.begin (); y1 != ys.end (); ++y1) {
         for (auto y2 = next (y1); y2 != ys.end (); ++y2) {
            int side = *y2 - *y1;
            if (side < max_side ||
               (side == max_side && *y1 >= ans.second)) continue;
            int x2 = x1 + side;
            if (m[x2].count (*y1) && m[x2].count (*y2)) {
               max_side = side;
               ans = { x1, *y1 };
            }
         }
      }
   }

   if (max_side) cout << ans.first << ' ' << ans.second << endl;
   else          cout << -1 << endl;

   return 0;
}
