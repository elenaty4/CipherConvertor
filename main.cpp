#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include "Cipher.h"
#include "Caesar.h"
#include "SimpleSub.h"

using namespace std;

int main()
{
    cout << "Welcome to the Cipher converter program" << endl;
    const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int NUM_DIGITS = 10;
    bool willDecrypt = false;
    bool willEncrypt = false;

    //Encrypt or Decrypt prompt
    do{
        cout << "Please enter a letter to indicate whether you want to encrypt a message or decrypt a message" << endl;
        cout << "A - encrypt" << endl;
        cout << "B - decrypt" << endl;
        string input;
        getline(cin, input);

        //Selections are NOT case sensitive
        if(input == "A" || input == "a")
        {
            willEncrypt = true;

        }
        else if (input == "B" || input == "b")
        {
            willDecrypt = true;
        }
        else
        {
            //Input is invalid
            cout << "That selection does not exist. Please try again" << endl;
        }

    }while(!willEncrypt && !willDecrypt);

    //Ask if they want to use a file or just input the words
    bool validInput = false;
    do
    {
        cout << "Do you want to use a .txt file or do you want to enter the message?" << endl;
        cout << "A - Use a file" << endl;
        cout << "B - Create a message" << endl;
        string input;
        getline(cin, input);

        //Selections are NOT case sensitive
        if(input == "A" || input == "a")
        {
            validInput = true;

            //ENTER FILE NAME

            bool validInput2 = false;
            do{
                cout << "Please enter a file name. Numbers and punctuation will not be encrypted or decrypted in the file" << endl;
                char fileName[100];
                cin >> fileName;
                ifstream file(fileName);
                //check if file exists
                if(!file)
                {
                    cout << "That file does not exist. Please try again" << endl;
                }
                else
                {
                    validInput2 = true;
                    //ask about selecting a cipher
                    bool validInput3 = false;
                    do{
                        cout<< endl;
                        cout<< "Now select a Cipher" << endl;
                        cout<< "A - Caesar" << endl;
                        cout<< "B - Simple Substitution" << endl;
                        string cipher;
                        cin >> cipher;

                        if(cipher == "A" || cipher == "a")
                        {
                            //Caesar class is called
                            Caesar *csr;
                            validInput3 = true;

                            //Key prompt
                            bool validNum = false;
                            int key;
                            do{
                                cout << "Please enter a number between 1 and 25. This will be the KEY to the cipher" <<endl;
                                cin >> key;
                                if(key >= 1 && key <= 25)
                                {
                                    validNum = true;
                                }
                                else
                                {
                                    validNum = false;
                                    cout << "That number is invalid. Please try again" <<endl;
                                }
                            }while(!validNum);

                            //check if encrypt or decrypt

                            string line;
                            if(willEncrypt)
                            {
                                cout << endl;
                                while(getline(file, line))
                                {
                                    csr = new Caesar(line, key);
                                    cout << csr->encrypt(line) << endl;
                                }
                            }
                            else if(willDecrypt)
                            {
                                cout << endl;
                                while(getline(file, line))
                                {
                                    csr = new Caesar(line, key);
                                    cout << csr->decrypt(line) << endl;
                                }
                            }
                            delete csr;
                        }
                        else if(cipher == "B" || cipher == "b")
                        {
                            //Simple Substitution class is called
                            SimpleSub *ssub;
                            validInput3 = true;
                            string key;
                            bool validKey = false;
                            bool repeatedLetter = false;
                            do{
                                cout << "Please enter 26 characters in any order you like. For example, "<<
                                "'qwertyuiopasdfghjklzxcvbnm'.\nYou can't repeat the same characters. \nThis will be the key to the cipher."
                                << endl;
                                cin >> key;

                                 //check if the length is 26
                                if(key.size() == 26)
                                {
                                    //check if the characters are not repeated
                                    char letter;
                                    for(int i=0; i < key.size(); i++)
                                    {
                                        int j = i+1;
                                        letter = key[i];
                                        //iterate through the alphabet
                                        while(!repeatedLetter && j < key.size())
                                        {
                                            char letter2 = key[j];
                                            if(letter == letter2)
                                            {
                                                repeatedLetter = true;
                                                validKey = false;
                                                cout << "There is a character repeated in this input. Please try again" << endl;
                                            }
                                            j++;
                                        }
                                    }
                                    if(!repeatedLetter)
                                    {
                                        validKey = true;
                                    }
                                }
                                else
                                {
                                    validKey = false;
                                    cout << "That input does not have 26 characters. Please try again" <<endl;
                                }
                            }while(!validKey);

                            //check if encrypt or decrypt
                            string line;
                            if(willEncrypt)
                            {
                                cout << endl;
                                while(getline(file, line))
                                {
                                    ssub = new SimpleSub(line, key);
                                    cout << ssub->encrypt(line) << endl;
                                }
                            }
                            else if(willDecrypt)
                            {
                                cout << endl;
                                while(getline(file, line))
                                {
                                    ssub = new SimpleSub(line, key);
                                    cout << ssub->encrypt(line) << endl;
                                }
                            }
                            delete ssub;
                        }
                    }while(!validInput3);
                }
            }while(!validInput2);
        }
        else if (input == "B" || input == "b")
        {
            //ENTER MESSAGE
            validInput = true;
            string message = "";
            cout<< "Please enter a message. Numbers and punctuation will not be encrypted or decrypted" << endl;
            getline(cin,message);

            bool validInput2 = false;
            do{
                cout<< endl;
                cout<< "Now select a Cipher" << endl;
                cout<< "A - Caesar" << endl;
                cout<< "B - Simple Substitution" << endl;
                string cipher;
                getline(cin,cipher);

                if(cipher == "A" || cipher == "a")
                {
                    //Caesar class is called
                    Caesar *csr;
                    validInput2 = true;
                    //Key prompt
                    bool validNum = false;
                    do{
                        cout << "Please enter a number between 1 and 25. This will be the KEY to the cipher" <<endl;
                        int key;
                        cin >> key;
                        if(key >= 1 && key <= 25)
                        {
                            validNum = true;
                            csr = new Caesar(message, key);
                        }
                        else
                        {
                            validNum = false;
                            cout << "That number is invalid. Please try again" <<endl;
                        }
                    }while(!validNum);

                    //check if encrypt or decrypt
                    if(willEncrypt)
                    {
                        cout << endl;
                        cout << csr->encrypt(message) << endl;
                    }
                    else if(willDecrypt)
                    {
                        cout << endl;
                        cout << csr->decrypt(message) << endl;
                    }
                    delete csr;
                }
                else if(cipher == "B" || cipher == "b")
                {
                    //Simple Substitution class is called
                    SimpleSub *ssub;
                    validInput2 = true;
                    string key;
                    bool validKey = false;
                    bool repeatedLetter = false;
                    do{
                        cout << "Please enter 26 characters in any order you like. For example, "<<
                        "'qwertyuiopasdfghjklzxcvbnm'.\nYou can't repeat the same characters. \nThis will be the key to the cipher."
                        << endl;
                        cin >> key;
                        //check if the length is 26
                        if(key.size() == 26)
                        {
                            //check if the characters are not repeated
                            char letter;
                            for(int i=0; i < key.size(); i++)
                            {
                                int j = i+1;
                                letter = key[i];
                                //iterate through the alphabet
                                while(!repeatedLetter && j < key.size())
                                {
                                    char letter2 = key[j];
                                    if(letter == letter2)
                                    {
                                        repeatedLetter = true;
                                        validKey = false;
                                        cout << "There is a character repeated in this input. Please try again" << endl;
                                    }
                                    j++;
                                }
                            }
                            if(!repeatedLetter)
                            {
                                validKey = true;
                                ssub = new SimpleSub(message, key);
                            }
                        }
                        else
                        {
                            validKey = false;
                            cout << "That input does not have 26 characters. Please try again" <<endl;
                        }
                    }while(!validKey);

                    //check if encrypt or decrypt
                    if(willEncrypt)
                    {
                        cout << endl;
                        cout << ssub->encrypt(message) << endl;
                    }
                    else if(willDecrypt)
                    {
                        cout << endl;
                        cout << ssub->decrypt(message) << endl;
                    }
                    delete ssub;
                }
                else{
                    validInput2 = false;
                    cout << "Invalid selection. Please try again" << endl;
                }
            }while(!validInput2);
        }
        else
        {
            //Input is invalid
            cout << "That selection does not exist. Please try again" << endl;
        }

    }while(!validInput);
    return 0;
}
