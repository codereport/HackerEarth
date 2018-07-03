// code_report Solution
// 

// Ugly solution

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

// Modern C++ Solution by Denis

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <iterator>
#include <iostream>

template <typename I, typename P, typename F>
// requires ForwardIterator<I> &&
//          StrictWeakOrdering<P> &&
//          RangeFunction<F>
F group_equal (I f, I l, P p, F action) {
   while (f != l) {
      I cur_end = std::upper_bound (f, l, *f, p);
      action (f, cur_end);
      f = cur_end;
   }
   return action;
}

template <typename I, typename F>
F for_all_pairs (I f, I l, F action) {
   for (; f != l; ++f) {
      for (I runner = std::next (f); runner != l; ++runner) {
         action (*f, *runner);
      }
   }
   return action;
}

void largest_square (std::vector<std::pair<int, int>>& dots) {
   // Sort, first by x, than by y.
   std::sort (dots.begin (), dots.end ());

   int max_side = 0;
   std::pair<int, int> ans = { 0, 0 };

   auto process_dots_on_one_line = [&](auto f, auto l) mutable {
      for_all_pairs (f, l, [&](auto xdot, auto ydot) mutable {
         int side = ydot.second - xdot.second;
         if (side < max_side ||
            (side == max_side && xdot.second >= ans.second)) return;

         auto third_dot = xdot;
         third_dot.first += side;

         auto fourth_dot = ydot;
         fourth_dot.first += side;

         if (!std::binary_search (dots.begin (), dots.end (), third_dot) ||
            !std::binary_search (dots.begin (), dots.end (), fourth_dot))
            return;

         max_side = side;
         ans = xdot;
      });
   };

   group_equal (dots.begin (), dots.end (),
      [](auto x, auto y) { return x.first < y.first; },
      process_dots_on_one_line);

   if (max_side == 0) std::cout << -1 << std::endl;
   else std::cout << ans.first << ' '
      << ans.second << std::endl;
}

auto read_input () {
   int n; std::cin >> n;
   std::vector<std::pair<int, int>> v (n);
   for (int i = 0; i < n; ++i) {
      int a, b;
      std::cin >> a >> b;
      v[i] = { a, b };
   }

   return v;
}

int main () {
   auto v = read_input ();
   largest_square (v);
   return 0;
}
