#include <iostream>
#include <string>

using namespace std;

string caesar_cipher(string text, int shift) {
    for (char &c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + shift) % 26 + base;
        }
    }
    return text;
}

string caesar_cipher_decrypt(string text, int shift) {
    return caesar_cipher(text, 26 - shift);
}

int main() {
    string text;
    int shift;

    cout << "Enter text to encrypt with Caesar Cipher: ";
    getline(cin, text);
    cout << "Enter the shift value (integer): ";
    cin >> shift;

    string encrypted_text = caesar_cipher(text, shift);
    cout << "Encrypted text: " << encrypted_text << endl;

    string decrypted_text = caesar_cipher_decrypt(encrypted_text, shift);
    cout << "Decrypted text: " << decrypted_text << endl;

    return 0;
}