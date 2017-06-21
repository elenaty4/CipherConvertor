#ifndef SIMPLESUB_H
#define SIMPLESUB_H
#include "Cipher.h"
#include <string.h>

using namespace std;

class SimpleSub: public Cipher
{
    public:
        SimpleSub(string message, string key);
        string encrypt(string message);
        string decrypt(string message);
        virtual ~SimpleSub();

    protected:

    private:
        string _message;
        string _encryptM;
        string _decryptM;
        const string _ALPHABET = "abcdefghijklmnopqrstuvwxyz";
        const string _ALPHA_CAP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const int NUM_LETTERS = 26;
        string _key;
};

#endif // SIMPLESUB_H
