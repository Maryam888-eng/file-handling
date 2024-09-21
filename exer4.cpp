#include <iostream>     // Including the input/output stream library
#include <fstream>      // Including the file stream library
#include <string>       // Including the string handling library
#include <sstream>     
using namespace std;
int main() {
  ifstream inputFile("test.txt"); 

  if (inputFile.is_open()) {  
    string line;       
    int wordCount = 0;        

    while (getline(inputFile, line)) {  
      stringstream ss(line);  
      string word;  

      while (ss >> word) {  
        wordCount++;  
      }
    }

    inputFile.close();  

    cout << "Number of words in the said file: " << wordCount <<endl;  
  } else {
    cout << "Failed to open the file." << endl; 
  }

  return 0;  
}
