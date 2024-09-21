#include <iostream>   

#include <fstream>    

#include <string> 
using namespace std;    

int main() {
  
  ifstream inputFile("test.txt");  // Opening the file named "test.txt" for reading

  if (inputFile.is_open()) {  
    string line;  
    int lineCount = 0; 

    while (std::getline(inputFile, line)) {  
      lineCount++;  
    }

    inputFile.close();  

    cout << "Number of lines in the file: " << lineCount << endl;  // Outputting the total line count
  } else {
    cout << "Failed to open the file." <<endl;  
  }

  return 0; 
}
