
//What do we need to include?
#include <iostream>
#include <string>
#include <fstream>

//No using namespace std;!!!!
using std::cout;
using std::endl;
using std::string;

//function to write num to any ostream
void writeToAnyOstream(int num, std::ostream& out) {
    out << num << endl;
}

int main() {
    // Write an int to the user's console.
    int myNum = 42;
    cout << "The answer is: " << myNum << endl;

    // Write an int to a file.
    // Must initialize your own ofstream object linked to your file
    // class basic_ofstream : public basic_ostream<_CharT,_Traits>
    std::ofstream out_stream("out.txt");

    out_stream << "The answer is: " << myNum << endl;
    
    // Write method to take any ostream
    std::ofstream out("Out.txt");
    out << "my favorite num is ";
    writeToAnyOstream(22, out);
   
    return 0;
}
