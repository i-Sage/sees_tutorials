#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAX_STUDENTS = 10;
const int NUM_SCORES = 3;

// Function Prototypes
void Read(string names[], float scores[][NUM_SCORES], int& count);
void Average(float scores[][NUM_SCORES], float mean[], int count);
void PrintResult(string names[], float scores[][NUM_SCORES], float mean[], int count);

// Main Function
int main() {
    string names[MAX_STUDENTS];
    float scores[MAX_STUDENTS][NUM_SCORES];
    float mean[MAX_STUDENTS];
    int count = 0;

    Read(names, scores, count);
    Average(scores, mean, count);
    PrintResult(names, scores, mean, count);

    return 0;
}

// Read data from CSV file
void Read(string names[], float scores[][NUM_SCORES], int& count) {
    ifstream input;
    const string FILE_IN = "scores.csv";

    input.open(FILE_IN);
    if (!input) {
        cout << "\nCan't find input file: " << FILE_IN;
        cout << "\nExiting program, bye bye\n";
        exit(1);
    }

    string line;
    getline(input, line); // Skip header

    while (getline(input, line) && count < MAX_STUDENTS) {
        stringstream ss(line);
        string name, score;
        getline(ss, name, ',');
        names[count] = name;

        for (int i = 0; i < NUM_SCORES; ++i) {
            getline(ss, score, ',');
            scores[count][i] = stof(score);
        }

        ++count;
    }

    input.close();
}

// Compute average scores for each student
void Average(float scores[][NUM_SCORES], float mean[], int count) {
    for (int i = 0; i < count; ++i) {
        float sum = 0;
        for (int j = 0; j < NUM_SCORES; ++j) {
            sum += scores[i][j];
        }
        mean[i] = sum / NUM_SCORES;
    }
}

// Print the result in a tabular format
void PrintResult(string names[], float scores[][NUM_SCORES], float mean[], int count) {
    cout << left << setw(5) << "S/N" << setw(15) << "Name"
         << setw(10) << "Score1" << setw(10) << "Score2"
         << setw(10) << "Score3" << setw(10) << "Mean" << endl;

    cout << string(60, '-') << endl;

    for (int i = 0; i < count; ++i) {
        cout << left << setw(5) << (i + 1)
             << setw(15) << names[i];

        for (int j = 0; j < NUM_SCORES; ++j) {
            cout << setw(10) << fixed << setprecision(2) << scores[i][j];
        }

        cout << setw(10) << fixed << setprecision(2) << mean[i] << endl;
    }
}
