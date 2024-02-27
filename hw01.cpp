// Zoe Dauphinee, homework 1, Caesar Cypher

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

char decrypt_char(char letter, int rotate_by);
void decrypt_line(string& line, int rotate_by);

int main() {
    // open file, check to make sure file opens
    ifstream encrypted_file("encrypted.txt");
    if(!encrypted_file) {
        cerr << "failed to open encrypted.txt\n";
        exit(1);
    }

    // read in the decryption number
    int rotate_by;
    encrypted_file >> rotate_by;

    string line;
    vector<string> lines;
    // get rid of newline character
    getline(encrypted_file, line);
    // decrypt line then store as a string in the vector
    while(getline(encrypted_file, line)) { 
        decrypt_line(line, rotate_by);
        lines.push_back(line); 
    }

    // close file
    encrypted_file.close();

    // print decrypted vector in reverse order
    for (size_t index = lines.size(); index > 0; --index) {
        cout << lines[index - 1] << endl;
    }
}

// takes in char and rotation distance, returns decrypted char
char decrypt_char(char letter, int rotate_by) {
    // if rotate_by > 0 --> move backwards
    if (rotate_by > 0) {
        while (rotate_by > 0) {
            if (letter == 'A') {
                letter = 'Z';
                --rotate_by; 
            }
            else {
                letter -= 1;
                --rotate_by;
            }
        }
    }
    // if rotate_by < 0 --> move forwards
    else if (rotate_by < 0) {
        while (rotate_by < 0) {
            if (letter == 'Z') {
                letter = 'A';
                ++rotate_by;
            }
            else {
                letter += 1;
                ++rotate_by;
            }
        }
    }
    return letter;
}

// takes in line and rotation distance, calls decryption function for each char
void decrypt_line(string& line, int rotate_by) {
    for (size_t index = 0; index < line.size(); ++index) {
        if (line[index] >= 'A' && line[index] <= 'Z') {
            line[index] = decrypt_char(line[index], rotate_by);
        }
    }
}