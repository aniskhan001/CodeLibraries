/***
Fractional Knapsack using Greedy approach
Complexity : O(n long n)
***/

#include <bits/stdc++.h>

using namespace std;

double do_the_math(int capacity, vector < pair<int, int> > vw) {
    double value = 0.0;

    // sorting pair using profit calculation.. profit = value/weight
    sort( vw.begin(), vw.end(), [](pair<int, int> a, pair<int, int> b) {
         return (double) a.first/a.second > (double) b.first/b.second;
    });

    for (int i=0; i<vw.size() && capacity; ++i) {
        if (vw[i].second < capacity) {
            capacity -= vw[i].second;
            value += vw[i].first;
        } else {
            value += capacity * (double) vw[i].first/vw[i].second;
            capacity = 0;
        }
    }
    return value;
}

int main() {
    int n, capacity;
    cin >> n >> capacity;
    vector < pair<int, int> > vw(n); // value, weight

    for (int i=0; i<n; ++i)
        std::cin >> vw[i].first >> vw[i].second;

    double res = do_the_math(capacity, vw);
    std::cout << fixed << setprecision(5) << res << std::endl;

    return 0;
}
