#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

string timestring() {
    string currtime;
    time_t timestamp;
    time(&timestamp);
    currtime = ctime(&timestamp);
    currtime[24] = '\0';
    currtime.pop_back();
    return currtime;
}

string filepath() {
    string dbpath;
    string rootpath = getenv("HOME");
    string actualpath = string(rootpath) + "/dbfs.conf";
    ifstream inFile(actualpath);
    getline(inFile, dbpath);
    inFile.close();
    return dbpath;


}

int readdb() {
    string outputot;
    string line;
    string currtime;
    sleep(1);
    system("clear");
    cout << "The Live DB is currently...\n";
    ifstream ogFile(filepath());
    while (std::getline(ogFile, line)) {
        std::cout << line << '\n';
    }
    sleep(3);
    ogFile.close();

}
int writedb() {
    string outputot;
    string line;
    string currtime;
    ofstream outFile(filepath(), ios::app);
    system("clear");
    cout << "Type what you would like to place inside the database\n";
    getline(cin, outputot);

    outFile << timestring() +  " " + outputot + "\n";
    outFile.close();
    system("clear");
    cout << "Now printing new version of Database\n";
    cout << "\n";
    ifstream inFile(filepath());
    while (std::getline(inFile, line)) {
        std::cout << line << '\n';
    }
    inFile.close();
    return 0;
}

int main() {
    cout << "Welcome to Database from Scratch (DBFS)!\n";
    if (filepath() != "") {
        ifstream check(filepath());
        if (check.peek() == ifstream::traits_type::eof()) {
            cout << "Nothing found in Database, continuing...  \n";
            return 1;
        }
        else {
            readdb();
        }
    }
    else {
        cout << "The database config file seems to not have a file path set. Please make sure you have the file path for the database on line 1 of ~/dbfs.conf. \n";
        return 1;
    }

    writedb();
}