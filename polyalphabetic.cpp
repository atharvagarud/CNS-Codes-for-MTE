#include <iostream>
#include <string>
using namespace std;
string vigenere_cipher(string text, string key)
{
    for (int i = 0; i < text.length(); i++)
    {
        if (isalpha(text[i]))
        {
            char base = isupper(text[i]) ? 'A' : 'a';
            char key_char = key[i % key.length()];
            int shift;
            if(base == 'A')
                shift = toupper(key_char) - base;
            else
                shift = tolower(key_char) - base;
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }
    return text;
}
string vigenere_cipher_decrypt(string text, string key)
{
    for (int i = 0; i < text.length(); i++)
    {
        if (isalpha(text[i]))
        {
            char base = isupper(text[i]) ? 'A' : 'a';
            char key_char = key[i % key.length()];
            int shift;
            if(base == 'A')
                shift = toupper(key_char) - base;
            else
                shift = tolower(key_char) - base;
            text[i] = (text[i] - base - shift + 26) % 26 + base;
        }
    }
    return text;
}
int main()
{
    string text, key;
    cout << "Enter the Vigenère key: ";
    cin >> key;
    cout << "Enter text to encrypt with Vigenère Cipher: ";
    cin.ignore();
    getline(cin, text);
    string encrypted_text = vigenere_cipher(text, key);
    cout << "Encrypted text: " << encrypted_text << endl;
    string decrypted_text = vigenere_cipher_decrypt(encrypted_text, key);
    cout << "Decrypted text: " << decrypted_text << endl;
    return 0;
}
