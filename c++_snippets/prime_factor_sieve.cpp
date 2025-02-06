void prime_factor_sieve(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n; i++) v[i] = i;
    for (int i = 2; i * i < n; i++) {
        if (v[i] == i) {
            for (int j = i * i; j < n; j += i) {
                if (v[j] == j) {
                    v[j] = i;
                }
            }
        }
    }
}

vector<int> find_prime_factors(int x, vector<int>& sieve) {
    vector<int> factors;
    while (x != 1) {
        factors.PB(sieve[x]);
        x /= sieve[x];
    }
    return factors;

}
   // main functions works
  // int n = 1e5;
  //   vector<int> sieve(n);

  //   prime_factor_sieve(sieve);

  //   vector<int> ans = find_prime_factors(45, sieve);
