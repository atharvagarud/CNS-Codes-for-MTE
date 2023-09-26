#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
 
// Function to generate a random key of the same length as the message
string generateRandomKey(int length) {
    string key;
    for (int i = 0; i < length; ++i) {
        key += (char)(rand() % 26 + 'A'); // Assuming uppercase letters
    }
    return key;
}
 
// Function to perform Vernam cipher encryption
string vernamEncrypt(const string& message, const string& key) {
    string ciphertext;
    for (size_t i = 0; i < message.length(); ++i) {
        char encryptedChar = message[i] ^ key[i];
        ciphertext += encryptedChar;
    }
    return ciphertext;
}
 
// Function to perform Vernam cipher decryption
string vernamDecrypt(const string& ciphertext, const string& key) {
    string decryptedText;
    for (size_t i = 0; i < ciphertext.length(); ++i) {
        char decryptedChar = ciphertext[i] ^ key[i];
        decryptedText += decryptedChar;
    }
    return decryptedText;
}
 
int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));
 
    string message;
    cout << "Enter the message to encrypt: ";
    getline(cin, message);
 
    // Generate a random key of the same length as the message
    string key = generateRandomKey(message.length());
 
    // Encrypt the message
    string ciphertext = vernamEncrypt(message, key);
    cout << "Encrypted message: " << ciphertext << endl;
 
    // Decrypt the message using the same key
    string decryptedText = vernamDecrypt(ciphertext, key);
    cout << "Decrypted message: " << decryptedText << endl;
 
    return 0;
}
