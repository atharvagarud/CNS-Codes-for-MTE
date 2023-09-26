#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
// Function to perform Rail Fence cipher encryption
string railFenceEncrypt(const string& message, int railCount) {
    vector<string> rails(railCount, "");
    int currentRail = 0;
    bool downDirection = true;
    for (char c : message) {
        rails[currentRail] += c;
        if (currentRail == 0)
            downDirection = true;
        else if (currentRail == railCount - 1)
            downDirection = false;
        if (downDirection)
            currentRail++;
        else
            currentRail--;
    }
    string ciphertext;
    for (const string& rail : rails) {
        ciphertext += rail;
    }
    return ciphertext;
}
 
// Function to perform Rail Fence cipher decryption
string railFenceDecrypt(const string& ciphertext, int railCount) {
    vector<string> rails(railCount, "");
    int currentRail = 0;
    bool downDirection = true;
    // Calculate the length of each rail
    vector<int> railLengths(railCount, 0);
    int railIndex = 0;
    for (char c : ciphertext) {
        railLengths[railIndex]++;
        if (railIndex == 0)
            downDirection = true;
        else if (railIndex == railCount - 1)
            downDirection = false;
        if (downDirection)
            railIndex++;
        else
            railIndex--;
    }
    int currentIndex = 0;
    for (int railIndex = 0; railIndex < railCount; ++railIndex) {
        rails[railIndex] = ciphertext.substr(currentIndex, railLengths[railIndex]);
        currentIndex += railLengths[railIndex];
    }
    string plaintext;
    currentRail = 0;
    downDirection = true;
    for (int i = 0; i < ciphertext.length(); ++i) {
        plaintext += rails[currentRail][0];
        rails[currentRail].erase(0, 1);
        if (currentRail == 0)
            downDirection = true;
        else if (currentRail == railCount - 1)
            downDirection = false;
        if (downDirection)
            currentRail++;
        else
            currentRail--;
    }
    return plaintext;
}
int main() {
    string message;
    int railCount;
    cout << "Enter the message to encrypt: ";
    getline(cin, message);
    cout << "Enter the number of rails: ";
    cin >> railCount;
    string ciphertext = railFenceEncrypt(message, railCount);
    cout << "Encrypted message: " << ciphertext << endl;
    string decryptedText = railFenceDecrypt(ciphertext, railCount);
    cout << "Decrypted message: " << decryptedText << endl;
    return 0;
}
