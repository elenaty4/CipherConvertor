#include "SimpleSub.h"
#include <string.h>

using namespace std;

SimpleSub::SimpleSub(string message, string key)
{
    _message = message;
    _key = key;
}


string SimpleSub::encrypt(string message)
{
    _encryptM = message;
    char letter;
    for(int i=0; i < _encryptM.size(); i++)
    {
        letter = _encryptM[i];
         //Find where the letter is located in the ALPHABET
        bool letterFound = false;
        int j = 0;
        char alpha;
        while(!letterFound && j < NUM_LETTERS)
        {
            //for lower case letters
            alpha = _ALPHABET[j];
            if(letter == alpha)
            {
                letterFound = true;
                //find the corresponding letter in _key
                _encryptM[i] = _key[j];
            }

            //for capital letters
            alpha = _ALPHA_CAP[j];
            if(letter == alpha)
            {
                letterFound = true;
                _encryptM[i] = _key[j];
            }
            j++;
        }
    }
    return _encryptM;
}

string SimpleSub::decrypt(string message)
{
    _decryptM = message;
    char element;
    for(int i=0; i < _decryptM.size(); i++)
    {
        element = _decryptM[i];
        bool charFound = false;
        int j = 0;
        char keyChar;
        while(!charFound && j < NUM_LETTERS)
        {
            keyChar = _key[j];
            if(element == keyChar)
            {
                charFound = true;
                //find the corresponding letter in the alphabet arrays
                _decryptM[i] = _ALPHABET[j];
            }
            j++;
        }
    }

    return _decryptM;
}

SimpleSub::~SimpleSub()
{
    //dtor
}
