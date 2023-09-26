#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string monoalphabetic_cipher(string text, unordered_map<char, char> &key) {
    for (char &c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = isupper(c) ? toupper(key[tolower(c)]) : key[c];
        }
    }
    return text;
}

string monoalphabetic_cipher_decrypt(string text, unordered_map<char, char> &key) {
    unordered_map<char, char> decryption_key;
    for (auto &pair : key) {
        decryption_key[pair.second] = pair.first;
    }
    return monoalphabetic_cipher(text, decryption_key);
}

int main() {
    string text;
    unordered_map<char, char> key;

    cout << "Enter the substitution key (26 unique characters): ";
    cin >> text;
    cout << "Enter text to encrypt with Monoalphabetic Cipher: ";
    cin.ignore();
    getline(cin, text);

    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char substitution;
            cout << "Enter substitution for '" << c << "': ";
            cin >> substitution;
            key[tolower(c)] = substitution;
        }
    }

    string encrypted_text = monoalphabetic_cipher(text, key);
    cout << "Encrypted text: " << encrypted_text << endl;

    string decrypted_text = monoalphabetic_cipher_decrypt(encrypted_text, key);
    cout << "Decrypted text: " << decrypted_text << endl;

    return 0;
}
