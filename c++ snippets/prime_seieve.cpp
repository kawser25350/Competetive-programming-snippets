#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<bool> prime; // Declare prime vector globally

void primesieve(int n, vector<int>& pr) {
    prime.resize(n + 1, true);

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
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

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> primes;
    primesieve(n, primes);

    cout << "Prime numbers up to " << n << " are: ";
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
