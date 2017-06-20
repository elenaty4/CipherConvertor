#ifndef CAESAR_H
#define CAESAR_H
#include <string.h>
#include <Cipher.h>

using namespace std;

class Caesar: public Cipher
{
    public:
        Caesar(string message, int key);
        string encrypt(string message);
        string decrypt(string message);
        virtual ~Caesar();

    protected:

    private:
        string _message;
        string _encryptM;
        string _decryptM;
        const string _ALPHABET = "abcdefghijklmnopqrstuvwxyz";
        const string _ALPHA_CAP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const int NUM_LETTERS = 26;
        int _key;
};
#endif // CAESAR_H
