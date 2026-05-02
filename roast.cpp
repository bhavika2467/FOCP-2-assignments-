#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

// Function to replace {name} with user name
string addName(string roast, string name)
{
    int pos = roast.find("{name}");
    roast.replace(pos, 6, name);
    return roast;
}

int main()
{
    // Store 20 roast lines
    vector<string> roasts = {
        "{name}, even Wi-Fi disconnects near you.",
        "{name}, your brain has too many tabs open.",
        "{name}, even Google has no answers for you.",
        "{name}, your future said try again later.",
        "{name}, you run slower than Windows update.",
        "{name}, even calculator gets confused by you.",
        "{name}, laziness would give you an award.",
        "{name}, your shadow left for brighter company.",
        "{name}, alarm clock is tired of you.",
        "{name}, loading screen moves faster than you.",
        "{name}, even turtle calls you slow.",
        "{name}, your jokes need software updates.",
        "{name}, even mirror laughs sometimes.",
        "{name}, your ideas need charging.",
        "{name}, even clouds move faster.",
        "{name}, homework fears being near you.",
        "{name}, your phone battery works harder.",
        "{name}, even keyboard skips your typing.",
        "{name}, your luck is always offline.",
        "{name}, even traffic moves better than you."
    };

    char choice = 'y';

    while (choice == 'y' || choice == 'Y')
    {
        string name;
        cout << "\nEnter name: ";
        cin >> name;

        // Shuffle roasts so no repeat until all used
        unsigned seed = time(0);
        shuffle(roasts.begin(), roasts.end(), default_random_engine(seed));

        // Show all roasts one by one
        for (int i = 0; i < roasts.size(); i++)
        {
            cout << "\nRoast " << i + 1 << ": ";
            cout << addName(roasts[i], name) << endl;

            // Ask if user wants next roast
            cout << "Next roast? (y/n): ";
            cin >> choice;

            if (choice == 'n' || choice == 'N')
                break;
        }

        // Ask for another friend
        cout << "\nRoast another friend? (y/n): ";
        cin >> choice;
    }

    cout << "\nProgram Ended.\n";

    return 0;
}