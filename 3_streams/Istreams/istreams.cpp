
#include <iostream>
#include <fstream>
#include <vector>

using std::cout;    using std::endl;
using std::string; using std::cin;

//read numbers from a file
void readNumbers() {
    // Create our ifstream and make it open the file
    // Receives a string from the stream and converts it to data
    std::ifstream in("res/numbers.txt");

    // Something to store values we get from the stream
    int value;
        // Extract next number from input
        while (true) {
        // If input is in a fail state, either a value couldn't
        // be converted, or we are at the end of the file.
            in >> value;
            if (in.fail()) break;
            //print whatever we read
            cout << "Value: " << value << endl;
        }
}

//read a single word at a time from a file
void readHaikuWord() {
    // Create our ifstream and make it open the file
    std::ifstream in("res/haiku.txt");
     // Something to store values we get from the stream
    std::string word;
        // Extract next word from input
        // If input is in a fail state, either a value couldn't
        // be converted, or we are at the end of the file.
        //print whatever we read
    while (true) {
        in >> word;
        if (in.fail())
            break;
        cout << "Read word: " << word << endl;
    }
}

void readHaikuLine() {
    // Create our ifstream and make it open the file
    std::ifstream in("res/haiku.txt");
    // Something to store the lines as we get them form the stream
    std::string line;
        // If input is in a fail state, either a value couldn't
        // be converted, or we are at the end of the file.
        //print whatever we read
    while (true) {
        std::getline(in, line);
        if (in.fail()) 
            break;
        cout << "Read line :" << line << endl;
    }
}



//function for us to play around with cin
void playground(){
    string line;
    std::ifstream in("res/haiku.txt");
    while(std::getline(in, line)){
        if(in.eof()){
        cout << "eof" << endl;
         // break;
        }
        else if (in.fail()) {
            cout << "fail" << endl;
            // break;
        }
        else cout << line << endl;
        cout << in.eof() << in.fail() << endl;
    }
    cout << in.eof() << in.fail() << endl;

}

int main() {

    playground();
    readNumbers();
    cout << "============" << endl;
    readHaikuWord();
    cout << "============" << endl;
    readHaikuLine();
    return 0;
}


