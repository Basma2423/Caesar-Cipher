#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;


// Program Name: Caesar_Cipher.cpp
// Program Description: encrypt or decrypt a text using Caesar Cipher.
// Last Modification Date: 28/3/2022
// Author : Basma Mahmoud

////////////////////////////////////////////////////////////////////////////////////////

void caesar();

////////////////////////////////////////////////////////////////////////////////////////
int main()
{

    caesar();


}
void caesar()
{
    int choice;
    void caesar_cipher(), decrypt_caesar_cipher();

    while (true)
    {
        for (int i = 0; i < 10; i++)
            cout << "*";

        cout << "\nHello User!\n What do u like to do today?\n";
        cout << "1- Cipher a message. \n 2- Decipher a message \n 3- End" << endl;

        for (int i = 0; i < 10; i++)
            cout << "*";

        cout << "\nUr Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            caesar_cipher();
            break;
        }


        else if (choice == 2)
        {
            decrypt_caesar_cipher();
            break;
        }

        else if (choice == 3)
        {
            cout << "\nHave a nice day!";
            break;
        }

        else
            cout << "Please Enter 1, 2 or 3!" << endl;
    }

}




void print_operated_chars_and_keep_spaces(string text, int shifts)
{
    int ascii_before, ascii_after;
    int checked_ascii_after(int ascii_before, int ascii_after);

    for (int i = 0; i < text.length(); i++)
    {
        ascii_before = int(text[i]);
        ascii_after = ascii_before + shifts;


        //keep the spaces

        if (ascii_before == 32)
            ascii_after = 32;



        cout << char(checked_ascii_after(ascii_before, ascii_after));

    }
}


void caesar_cipher()
{
    string text;
    int shifts;

    cout << "\nEnter the text u want to encrypt: " << endl;
    cin.ignore();
    getline(cin, text);
    cout << "Enter +ve value for number of shifts in the right direction,and -ve value for number of shifts in the left one: " << endl;
    cin >> shifts;

    if (shifts > 26 || shifts < -26)
        shifts = shifts % 26;


    cout << "The Encrypted Text is: ";
    print_operated_chars_and_keep_spaces(text, shifts);


}



void decrypt_caesar_cipher()
{
    string text;
    int shifts;

    cout << "\nEnter the encrypted text: " << endl;
    cin.ignore();
    getline(cin, text);
    cout << "Enter how many times the text was shifted\n +ve value for shifts in the right direction,and -ve value for shifts in the left one: " << endl;
    cin >> shifts;

    //Decrypting by changing the shifting direction

    shifts = -shifts;


    print_operated_chars_and_keep_spaces(text, shifts);




}




int checked_ascii_after(int ascii_before, int ascii_after)
{

    if (isupper(ascii_before))
    {
        //if it exceeds Z it returns to A
        if (ascii_after > 90)
            ascii_after = 64 + (ascii_after - 90);

        //if it is lower than A, it continues from Z
        //at shifting in the left direction
        if (ascii_after < 65)
            ascii_after = 91 - (65 - ascii_after);
    }


    if (islower(ascii_before))
    {
        //if it exceeds z it returns to a
        if (ascii_after > 122)
            ascii_after = 96 + (122 - ascii_after);

        //if it is lower than a, it continues from z
        //at shifting in the left direction
        if (ascii_after < 97)
            ascii_after = 123 - (97 - ascii_after);


    }
    return ascii_after;
}

