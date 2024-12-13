void primesieve(int n, vector<int>& pr) {
    vector<bool> prime(n + 1, true);
    memset(prime.data(), true, prime.size());

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            pr.push_back(p);
        }
    }
}
