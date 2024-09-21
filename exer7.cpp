#include <iostream>   
#include <fstream>    
#include <string>     
using namespace std;

void displayFileContent(const::string & filename) {
  ifstream file(filename); 
  string line;

  if (file.is_open()) {
    cout << "File content:" <<endl; 
    while (getline(file, line)) { 
    cout << line <<endl; 
    }
    file.close(); 
  } else {
    cout << "Failed to open the file." <<endl;
  }
}

int main() {
  ifstream inputFile("test.txt"); 
  ofstream outputFile("new_test.txt"); 

  if (inputFile.is_open() && outputFile.is_open()) { 
    string line; 
    string searchWord = "C++";
    string replaceWord = "CPP"; 

    cout << "Search word:" << searchWord <<endl; 
    cout << "Replace word:" << replaceWord <<endl; 
	cout << "\nBefore find and replace:" <<endl; 
    displayFileContent("test.txt"); 

    while (::getline(inputFile, line)) {
      size_t pos = line.find(searchWord); 

      while (pos != ::string::npos) { 
        line.replace(pos, searchWord.length(), replaceWord); 
        pos = line.find(searchWord, pos + replaceWord.length()); 
      }
      outputFile << line << "\n";
    }

    inputFile.close(); 
    outputFile.close(); 

    cout << "After find and replace:" <<endl; 
    displayFileContent("new_test.txt"); 

    cout << "\nWord replaced successfully." <<endl; 
  } else {
    cout << "\nFailed to open the files." <<endl; 
  }

  return 0;
}
