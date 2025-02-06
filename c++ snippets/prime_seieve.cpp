<<<<<<< HEAD

 void prime_sieve(vector<int>&sieve){

    sieve[1]=0;
    sieve[0]=0;

    int n=sieve.size();

    for(int i=2;i<n;i++){
        if(sieve[i]){
            for(int j=i*i;j<n;j+=i){
                sieve[j]=0;
=======
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
>>>>>>> 5ecea4b67825238b58935cafd45f05f7a057f5a2
            }
        }
    }
 // in main funciotn   -> int n=1e5;
//                       vector<int>sieve(n,1);

<<<<<<< HEAD
 }
=======
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
>>>>>>> 5ecea4b67825238b58935cafd45f05f7a057f5a2
