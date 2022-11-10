#ifndef FILEREADER_10NOV22
#define FILEREADER_10NOV22

#include <fstream>
#include <string>
using namespace std;

class FileReader {
    protected:
        ifstream lector;
        bool file_exist;
        string line;
    public:
        FileReader();
        FileReader(string);
        bool openFile(string);
        void closeFile();
        string getLine();
        bool end_of_file();
        void createFile(string);
};

#endif