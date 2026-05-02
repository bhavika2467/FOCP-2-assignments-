#include <bits/stdc++.h>
using namespace std;
class MovieTicket {
private:
    unordered_map<int, unordered_set<int>> movieBookings;
    unordered_map<int, int> availableTickets;
public:
    MovieTicket() {}
    bool book(int user, int movie) {
        // initialize movie if not present
        if (availableTickets.find(movie) == availableTickets.end()) {
            availableTickets[movie] = 100;
        }
        // already booked
        if (movieBookings[movie].count(user)) {
            return false;
        }
        // sold out
        if (availableTickets[movie] == 0) {
            return false;
        }
        movieBookings[movie].insert(user);
        availableTickets[movie]--;
        return true;
    }
    bool cancel(int user, int movie) {
        if (movieBookings[movie].count(user) == 0) {
            return false;
        }
        movieBookings[movie].erase(user);
        availableTickets[movie]++;
        return true;
    }
    bool isBooked(int user, int movie) {
        return movieBookings[movie].count(user);
    }
    int available(int movie) {
        if (availableTickets.find(movie) == availableTickets.end()) {
            return 100;   }
        return availableTickets[movie];}};
int main() {
    int Q;
    cin >> Q;
    MovieTicket mt;
    while (Q--) {
        string query;
        cin >> query;
        if (query == "BOOK") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.book(X, Y) ? "true" : "false") << endl;}
        else if (query == "CANCEL") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.cancel(X, Y) ? "true" : "false") << endl;}
        else if (query == "IS_BOOKED") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.isBooked(X, Y) ? "true" : "false") << endl;}
        else if (query == "AVAILABLE_TICKETS") {
            int Y;
            cin >> Y;
            cout << mt.available(Y) << endl;}}
    return 0;}