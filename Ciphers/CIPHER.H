#ifndef CIPHER_H
#define CIPHER_H
#include <string.h>
#include <iostream>

using namespace std;

class Cipher
{
    public:
        Cipher(string message);
        Cipher();
        string encrypt(string message);
        string decrypt(string message);
        virtual ~Cipher();
        Cipher(const Cipher& other);

    protected:

    private:
        string _message;
        string _encryptM;
        string _decryptM;
        char _alphabet[];
        string key;
};

#endif // CIPHER_H
