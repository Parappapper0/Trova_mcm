#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std; 

int getPrimeLimit(vector<int>& v) {

    int max = 0;

    for (int i = 0; i < v.size(); i++)
        if (v.at(i) > max)
            max = v.at(i);

    return max;
}

vector<int> findPrimes(int limit) {

    bool prime;
    vector<int> primes;

    for (int i = 2; i <= limit; i++) {

        prime = true;
        for (int j = 0; j < primes.size(); j++)

            if (i % primes.at(j) == 0) {

                prime = false;
                break;
            }
        if (prime)
            primes.push_back(i);
    }

    return primes;
}

int solve() {
    int N;
    cin >> N;
    vector<int> V(N);
    for (int& x : V) {
        cin >> x;
    }

    int risposta = 1;
    int limit = getPrimeLimit(V);
    vector<int> primes = findPrimes(limit);

    map<int, int> currentFactors;
    map<int, int> allFactors;

    for (int& number : V) {

        currentFactors.clear();

        for (int i = 0; i < primes.size() && number != 1; i++) {

            if (primes.at(i) > (int)sqrt(number)) {
                currentFactors[number]++;
                break;
            }

            if (number % primes.at(i) == 0) {

                currentFactors[primes.at(i)]++;
                number /= primes.at(i);
                i--;
            }
        }

        for (auto i = currentFactors.begin(); i != currentFactors.end(); i++) {

            allFactors[i->first] = max(i->second, allFactors[i->first]);
        }
    }

    for (auto i = allFactors.begin(); i != allFactors.end(); i++) {

        risposta *= (int)pow(i->first, i->second);
    }

    return risposta;
}

int main() {
    int T;

    freopen("caramelle_input_1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}