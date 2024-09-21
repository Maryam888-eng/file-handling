#include <iostream>   
#include <fstream>   
#include <string>    
using namespace std; 
int main() {
  ifstream inputFile("test.txt");    
  ofstream outputFile("test_copy.txt");  

  if (inputFile.is_open() && outputFile.is_open()) {  
  string line;

    while (std::getline(inputFile, line)) {  
      outputFile << line << "\n";  
    }

    inputFile.close(); 
    outputFile.close();  

    std::cout << "File copied successfully." << endl; 
  } else {
    std::cout << "Failed to open the files." << endl;
  }

  return 0;  
}
