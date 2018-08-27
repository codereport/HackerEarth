// code_report Solution
// https://youtu.be/Ndc1EMq25R0

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define FORI(s,n) for(int i = s; i < n; i++)
using pii = pair<int, int>;

int main () {
   int t; cin >> t;
   while (t--) {
      int n; cin >> n;
      vector<pii> v (n);
      FORI (0, n) cin >> v[i].second >> v[i].first;
      sort (v.begin (), v.end ());
      multiset<int> m;
      auto ans = m.size ();
      for (auto e : v) {
         m.insert (e.second);
         m.erase (m.begin (), m.upper_bound (e.first));
         ans = max (ans, m.size ());
      }
      cout << ans << endl;
   }

   return 0;
}
