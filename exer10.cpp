#include <iostream>   // Including the input/output stream library
#include <fstream>    // Including the file stream library
#include <string>     // Including the string handling library
using namespace std;
// Function to display the content of a file
void displayFileContent(const string & filename) {
  ifstream file(filename); // Open file with given filename for reading
  string line; // Declare a string to store each line of text

  if (file.is_open()) { // Check if the file was successfully opened
    cout << "File content:" <<endl; // Displaying a message indicating file content
    while (getline(file, line)) { // Read each line from the file
    cout << line <<endl; // Display each line of the file
    }
    file.close(); // Close the file
  } else {
    cout << "Failed to open the file." <<endl; // Display an error message if file opening failed
  }
}

// Function to encrypt a file using a simple algorithm (incrementing ASCII values)
void encryptFile(const string & inputFile, const string & outputFile) {
  ifstream input(inputFile); // Open input file for reading
  ofstream output(outputFile); // Open or create output file for writing

  if (input.is_open() && output.is_open()) { // Check if both files were successfully opened
    char ch; // Declare a character variable to read characters from the input file

    while (input.get(ch)) { // Loop through each character in the input file
      ch++; // Simple encryption algorithm: Increment ASCII value by 1
      output.put(ch); // Write the encrypted character to the output file
    }

    input.close(); // Close the input file
    output.close(); // Close the output file

    cout << "File encrypted successfully.\n" <<endl; // Display a success message
  } else {
    cout << "Failed to open the files.\n" <<endl; // Display an error message if file opening failed
  }
}

int main() {
  string inputFile = "test.txt"; // Input file
  displayFileContent("test.txt"); // Display content of "test.txt"
  cout <<endl; // Output a newline for formatting

  string outputFile = "encrypted_test.txt"; // Output file for encrypted content
  encryptFile(inputFile, outputFile); // Encrypt "test.txt" and write to "encrypted_test.txt"
  displayFileContent("encrypted_test.txt"); // Display content of "encrypted_test.txt"
  cout <<endl; // Output a newline for formatting

  return 0; // Return 0 to indicate successful execution
}
