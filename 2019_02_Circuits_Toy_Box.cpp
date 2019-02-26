// code_report Solution
// Video Link: https://youtu.be/9eBNy3wKcKc
// Problem Link: https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/toy-box-5044b3ed/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> v(m + 1);
    while (n--) {
        int p, b; cin >> p >> b;
        v[b] = max(v[b], p);
    }
    cout << accumulate(begin(v), end(v), 0);
    return 0;
}
