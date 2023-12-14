// Purpose: Document Comparator
// Author(s): Seif Khaled
// Date: Dec 13, 2023

#include <iostream>
#include <fstream>  // for file input/output operations
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <thread> // for the typing animation
#include <chrono> // for the typing animation

/* --- Define Color Codes --- */
#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"
#define WHITE   "\x1B[37m"

using namespace std;

class StringSet {
private:
    set<string> strings;

    // helper function to tokenize a string
    vector<string> tokenize(const string& str) {
        vector<string> tokens;
        string token;
        for (char ch : str) {
            if (isalnum(ch)) {
                token += tolower(ch);
            } else if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        }
        if (!token.empty()) {
            tokens.push_back(token);
        }
        return tokens;
    }

public:
    // constructor to read from a file
    StringSet(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << RED << "Error: Unable to open file '" << filename << RESET << endl; // error handling for user input
            return;
        }

        string word;
        while (file >> word) {
            vector<string> tokens = tokenize(word);
            strings.insert(tokens.begin(), tokens.end());
        }
    }

    // constructor to handle string input
    StringSet(const string& inputString, bool isString) {
        if (isString) {
            vector<string> tokens = tokenize(inputString);
            strings.insert(tokens.begin(), tokens.end());
        } else {
            // handle other cases if needed
        }
    }

    StringSet() {} // default constructor

    // function to add a string to the set
    void addString(const string& str) {
        vector<string> tokens = tokenize(str);
        strings.insert(tokens.begin(), tokens.end());
    }

    // function to remove a string from the set
    void removeString(const string& str) {
        vector<string> tokens = tokenize(str);
        for (const auto& token : tokens) {
            strings.erase(token);
        }
    }

    // function to clear the set
    void clearSet() {
        strings.clear();
    }

    // function to get the size of the set
    int size() const {
        return strings.size();
    }

    // function to display the set
    void display() const {
        for (const auto& str : strings) {
            cout << str << " ";
        }
        cout << endl;
    }

    // overload + operator for union
    StringSet operator+(const StringSet& other) const {
        StringSet resultSet = *this;
        resultSet.strings.insert(other.strings.begin(), other.strings.end());
        return resultSet;
    }

    // overload * operator for intersection
    StringSet operator*(const StringSet& other) const {
        StringSet resultSet;
        for (const auto& str : strings) {
            if (other.strings.find(str) != other.strings.end()) {
                resultSet.strings.insert(str);
            }
        }
        return resultSet;
    }

    // function to compute binary cosine coefficient
    double similarity(const StringSet& other) const {
        StringSet intersectionSet = *this * other;
        int intersectionSize = intersectionSet.size();
        int unionSize = size() + other.size() - intersectionSize;
        if (unionSize == 0) {
            return 0.0; // to avoid division by zero
        }

        double dotProduct = static_cast<double>(intersectionSize);
        double magnitudeSet1 = sqrt(static_cast<double>(size()));
        double magnitudeSet2 = sqrt(static_cast<double>(other.size()));

        return dotProduct / (magnitudeSet1 * magnitudeSet2);
    }
};

// function for typing animation in the output
void typeText(const string& text, int millisecondsPerChar) {
    for (char c : text) {
        cout << MAGENTA << c << RESET << flush;
        this_thread::sleep_for(chrono::milliseconds(millisecondsPerChar));
    }
}

int main() {
    cout << GREEN   " ____         ____                                      _             \n"
                    "|  _ \\  ___  / ___|___  _ __ ___  _ __   __ _ _ __ __ _| |_ ___  _ __ \n"
                    "| | | |/ _ \\| |   / _ \\| '_ ` _ \\| '_ \\ / _` | '__/ _` | __/ _ \\| '__|\n"
                    "| |_| | (_) | |__| (_) | | | | | | |_) | (_| | | | (_| | || (_) | |   \n"
                    "|____/ \\___/ \\____\\___/|_| |_| |_| .__/ \\__,_|_|  \\__,_|\\__\\___/|_|   \n"
                    "      By: Seif Khaled            |_|                                   \n" << RESET;

    int delay = 35; // adjust the delay (the less the faster)

    string document1 = "Enter the name of document 1: ";
    typeText(document1, delay);

    getline(cin, document1);
    document1 += ".txt"; // automatically add ".txt" extension

    string document2 = "Enter the name of document 2: ";
    typeText(document2, delay);

    getline(cin, document2);
    document2 += ".txt"; // automatically add ".txt" extension

    StringSet set1(document1);
    StringSet set2(document2);

    cout << "Set 1: ";
    set1.display();

    cout << "Set 2: ";
    set2.display();

    StringSet unionSet = set1 + set2;
    cout << "Union: ";
    unionSet.display();

    StringSet intersectionSet = set1 * set2;
    cout << "Intersection: ";
    intersectionSet.display();

    double similarity = set1.similarity(set2);
    cout << "Similarity between set 1 and set 2: " << similarity << endl;

    int delayThxMsg = 70; // another delay for the thanks message at the end

    string thxMsg = "Thank you for using my program.\nExiting ...\n";
    typeText(thxMsg, delayThxMsg);

    return 0;
}

// Version: v1.0 > Base DoComparator. [Dec 5, 2023]
// Version: v1.1 > Add ASCII Art Title and Colors. [Dec 6, 2023]
// Version: v1.2 > Add Typing Animation in Some Outputs. [Dec 6, 2023]
// Version: v1.2.1 > Fix some bugs. [Dec 13, 2023]