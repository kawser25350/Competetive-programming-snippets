#include <bits/stdc++.h>
using namespace std;

int main() {
    mt19937_64 rng(random_device{}());
    auto rnd = [&](long long l, long long r) { return l + rng() % (r - l + 1); };

    vector<int> sizes = {1, 2, 10, 200000}; // লোয়ার কর্নার + ম্যাক্স লিমিট
    cout << sizes.size() << '\n';
    for (int n : sizes) {
        cout << n << '\n';

        // 1. Array:
        for (int i = 0; i < n; i++) cout << rnd(1, 1e9) << " \n"[i == n - 1];

        // 2. String (lowercase 'a'-'z' বা '0'-'1' চাইলে 'a','z' বদলে '0','1' দাও):
        // string s(n, ' '); for (char &c : s) c = rnd('a', 'z'); cout << s << '\n';

        // 3. Single Char:
        // cout << (char)rnd('a', 'z') << '\n';

        // 4. Permutation (1 to n):
        // vector<int> p(n); iota(p.begin(), p.end(), 1); shuffle(p.begin(), p.end(), rng);
        // for (int i = 0; i < n; i++) cout << p[i] << " \n"[i == n - 1];
    }
}