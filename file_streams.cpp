#include <fstream>
#include <string>
#include <iostream>
using std::string;
using std::cout;

//you cannot open another file to an already opened filestream. 
int main(int argc, char** argv) {

    std::ifstream in(argv[1]);
    string word;
    while(in >> word){
        cout << word;
    }
    return 0;
}
