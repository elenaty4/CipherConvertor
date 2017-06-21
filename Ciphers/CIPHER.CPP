#include "Cipher.h"
#include <string.h>

using namespace std;

Cipher::Cipher(string message)
{
    _message = message;
}

Cipher::Cipher() //default constructor is needed
{

}

string Cipher::encrypt(string message)
{
    return _encryptM;
}

string Cipher::decrypt(string message)
{

    return _decryptM;
}

Cipher::~Cipher()
{
    cout << endl;
    cout << "deleting memory" << endl;
}

Cipher::Cipher(const Cipher& other)
{
    //copy ctor
}
