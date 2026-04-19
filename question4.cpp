#include <iostream>
using namespace std;
string solve(int n, int arr[]) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] < arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;}} }
    int alex = 0, bob = 0,lastA = -1, lastB = -1,turn = 0;
    for(int i = 0; i < n; i++) {
        if(turn == 0) { 
            if(arr[i] != lastA) {
                alex += arr[i];
                lastA = arr[i];
                turn = 1;}  }
        else { 
            if(arr[i] != lastB) {
                bob += arr[i];
                lastB = arr[i];
                turn = 0; }}}
    if(alex > bob) return "Alex";
    else return "Bob";}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];}
        cout << solve(n, arr) << endl; } }