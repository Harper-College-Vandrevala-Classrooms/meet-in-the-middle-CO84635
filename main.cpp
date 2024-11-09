#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: " << endl;
    cin >> filename;

    ifstream file(filename);
    if(!file.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string line;
    vector<double> data;

    while(getline(file, line)) {
        stringstream ss(line);
        string value;

        while (getline(ss, value, ',')) {
            data.push_back(stod(value));
        }
    }
    
    file.close();

    if (data.empty()) {
        cout << "There is no data in the CSV!" << endl;
        return 1;
    }

    sort(data.begin(), data.end());
    double median;

    if (data.size() % 2 == 0) {
        median = (data[data.size() / 2 - 1] + data[data.size() / 2]) / 2.0;
    } else {
        median = data[data.size() / 2];
    }

    cout <<"The median of the dataset is " << median << "." << endl;

    return 0;
}
