#include <bits/stdc++.h>
using namespace std;
class Bank {
private:
    unordered_map<string, long long> accounts;
public:
    bool create(string user, long long amount) {
        if (accounts.find(user) == accounts.end()) {
            accounts[user] = amount;
            return true;
        } else {
            accounts[user] += amount;
            return false;}}
    bool debit(string user, long long amount) {
        if (accounts.find(user) == accounts.end() || accounts[user] < amount) {
            return false;}
        accounts[user] -= amount;
        return true;}
    bool credit(string user, long long amount) {
        if (accounts.find(user) == accounts.end()) {
            return false;}
        accounts[user] += amount;
        return true;}
    long long balance(string user) {
        if (accounts.find(user) == accounts.end()) {
            return -1;
        }
        return accounts[user];
    }
};
int main() {
    int Q;
    cin >> Q;
    cin.ignore();
    Bank bank;
    while (Q--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string operation, user;
        long long amount;
        ss >> operation;
        if (operation == "CREATE") {
            ss >> user >> amount;
            cout << (bank.create(user, amount) ? "true" : "false") << endl;}
        else if (operation == "DEBIT") {
            ss >> user >> amount;
            cout << (bank.debit(user, amount) ? "true" : "false") << endl;}
        else if (operation == "CREDIT") {
            ss >> user >> amount;
            cout << (bank.credit(user, amount) ? "true" : "false") << endl;}
        else if (operation == "BALANCE") {
            ss >> user;
            cout << bank.balance(user) << endl;}}
    return 0;
}