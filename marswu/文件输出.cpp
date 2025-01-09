#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream ofile;
    ofile.open("/home/username/Desktop/test.txt");
    if (!ofile) {
        cerr << "Error: Could not create file." << endl;
        return 1;
    }
    ofile << "zkx is nanniang";
    ofile.close();
    cout << "File created successfully!" << endl;
    return 0;
}
