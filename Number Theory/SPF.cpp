#include <bits/stdc++.h>
using namespace std;

class SPF {
    int MAX_N;
    vector<int> spf;

    // Build the SPF table: spf[i] will hold the smallest prime factor of i.
    void generate() {
        spf.assign(MAX_N+1, 0);

        // Initially assume each number is its own smallest prime factor
        for(int i = 1; i <= MAX_N; i++) {
            spf[i] = i;
        }

        // Sieve: for each prime i, mark its multiples’ SPF if not already marked
        for(int i = 2; i * i <= MAX_N; i++) {
            if(spf[i] == i) {
                for(int j = i * i; j <= MAX_N; j += i) {
                     // first time we visit j, record i as its smallest prime factor
                    if(spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

  public:
    SPF(int n) {
        MAX_N = n;
        generate();
    }

    // Return smallest prime factor of n, or –1 if out of range.
    int getSmallestPrimeFactor(int n) const {
        if (n < 2 || n > MAX_N) return -1;
        return spf[n];
    }

    // Return the vector of all prime factors of n, or {} if out of range.
    vector<int> getPrimeFactors(int n) const {
        if (n < 2 || n > MAX_N) return {};
        vector<int> factors;
        factors.reserve(32);
        while (n > 1) {
            factors.push_back(spf[n]);
            n /= spf[n];
        }
        return factors;
    }
};

int main() {
    int LIMIT = 100000;
    SPF factors(LIMIT);

    cout << factors.getSmallestPrimeFactor(5) << "\n";         
    for (auto p : factors.getPrimeFactors(40)) std::cout << p << " "; 
    cout << endl;
}
