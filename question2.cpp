#include <bits/stdc++.h>
using namespace std;
int countPrimes(int n) {
    int count = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            count++; 
            while (n % i == 0) {
                n /= i; }}}
    if (n > 1) count++;
    return count;}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int k = countPrimes(n);
        cout << (1 << k) << endl; } }