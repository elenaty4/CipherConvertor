#include "Caesar.h"
#include <string.h>
#include <Cipher.h>

using namespace std;

Caesar::Caesar(string message, int key)
{
    _message = message;
    _key = key;
}

string Caesar::encrypt(string message)
{
    //To encrypt in Caesar, all of the words in the alphabet move up by the key number
    _encryptM = _message;
    int letterPos; //the number position that corresponds to the letter. Ex. A is 0, B is 1, C is 2
    char letter;
    for(int i = 0; i < _encryptM.size(); i++)
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
                //now we must move the letter by the key
                letterPos = j + _key;
                if(letterPos >= NUM_LETTERS)
                {
                    //start the letter shift from 0th position again
                    int shift = letterPos - NUM_LETTERS;
                    letterPos = 0 + shift;
                }
                _encryptM[i] = _ALPHABET[letterPos]; //add it to the encrypt message
            }

            //for capital letters
            alpha = _ALPHA_CAP[j];
            if(letter == alpha)
            {
                letterFound = true;
                //now we must move the letter by the key
                letterPos = j + _key;
                if(letterPos >= NUM_LETTERS)
                {
                    //start the letter shift from 0th position again
                    int shift = letterPos - NUM_LETTERS;
                    letterPos = 0 + shift;
                }
                _encryptM[i] = _ALPHA_CAP[letterPos]; //add it to the encrypt message
            }
            j++;
        }
    }
    return _encryptM;
}

string Caesar::decrypt(string message)
{
    //doing the reverse of encrypt
    _decryptM = message;
    int letterPos; //the number position that corresponds to the letter. Ex. A is 0, B is 1, C is 2
    char letter;
    for(int i = 0; i < _decryptM.size(); i++)
    {
        letter = _decryptM[i];
        //Find where the letter is located in the ALPHABET
        bool letterFound = false;
        int j = 0;
        char alpha;
        while(!letterFound && j < NUM_LETTERS)
        {
            //for lower case
            alpha = _ALPHABET[j];
            if(letter == alpha)
            {
                letterFound = true;
                //now we must move the letter by the key
                letterPos = j - _key;
                if(letterPos < 0)
                {
                    //start the letter shift from 25th position again
                    letterPos = NUM_LETTERS + letterPos; //26 + a negative int
                }
                _decryptM[i] = _ALPHABET[letterPos]; //add it to the encrypt message
            }

            //for capital letters
            alpha = _ALPHA_CAP[j];
            if(letter == alpha)
            {
                letterFound = true;
                //now we must move the letter by the key
                letterPos = j - _key;
                if(letterPos < 0)
                {
                    //start the letter shift from 25th position again
                    letterPos = NUM_LETTERS + letterPos;
                }
                _decryptM[i] = _ALPHA_CAP[letterPos]; //add it to the encrypt message
            }
            j++;
        }
    }
    return _decryptM;
}

Caesar::~Caesar()
{
    //dtor
    cout << endl;
    cout << "deleting csr memory" << endl;
}
