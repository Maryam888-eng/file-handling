#include <iostream>   // Including the input/output stream library
#include <fstream>    // Including the file stream library
#include <string>     // Including the string handling library
#include <vector>     // Including the vector container
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
vector<string> inputFiles = {
    "test1.txt",
    "test2.txt",
    "test3.txt",
    "test4.txt"
  };
  cout << "Content of test1.txt, test2.txt, test3.txt, text4.txt: " <<endl;

  displayFileContent("test1.txt"); 
  displayFileContent("test2.txt"); 
  displayFileContent("test3.txt"); 
  displayFileContent("test4.txt");

  string outputFile = "merged_test_file.txt";

  ofstream mergedFile(outputFile); 

  if (mergedFile.is_open()) { 
    for (const auto & inputFile: inputFiles) {
    ifstream inputFileStream(inputFile); 

      if (inputFileStream.is_open()) {
      string line;

        while (getline(inputFileStream, line)) { 
          mergedFile << line << "\n"; 
        }

        inputFileStream.close(); 
      } else {
        cout << "Failed to open input file: " << inputFile <<endl;
      }
    }

    mergedFile.close();
    cout << "\nFiles merged successfully." <endl;
    cout << "\nContent of the merged file:" <<endl;
    displayFileContent("merged_test_file.txt"); 
  } else {
    cout << "Failed to open the output file." <<endl; 
  }

  return 0; 
}
