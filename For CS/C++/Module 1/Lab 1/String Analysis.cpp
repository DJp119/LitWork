#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void analyzeString(const string &input) {
    int totalCharacters = input.length();
    int uppercaseCount = 0;
    int lowercaseCount = 0;
    int digitCount = 0;
    int symbolCount = 0;

    for (char character : input) {
        if (isupper(character)) {
            uppercaseCount++;
        } else if (islower(character)) {
            lowercaseCount++;
        } else if (isdigit(character)) {
            digitCount++;
        } else {
            symbolCount++;
        }
    }

    double uppercasePercentage = static_cast<double>(uppercaseCount) / totalCharacters * 100;
    double lowercasePercentage = static_cast<double>(lowercaseCount) / totalCharacters * 100;
    double digitPercentage = static_cast<double>(digitCount) / totalCharacters * 100;
    double symbolPercentage = static_cast<double>(symbolCount) / totalCharacters * 100;

    cout << fixed << setprecision(3);
    cout << uppercasePercentage << "%" << endl;
    cout << lowercasePercentage << "%" << endl;
    cout << digitPercentage << "%" << endl;
    cout << symbolPercentage << "%" << endl;
}

int main() {
    string input;
    cin >> input;
    analyzeString(input);

    return 0;
}
