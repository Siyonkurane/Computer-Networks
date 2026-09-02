#include <iostream>
#include <string>
using namespace std;

int main()
{
    string codeword, generator;

    cout << "Enter The Received Codeword: ";
    cin >> codeword;

    cout << "Enter The Generator Bits: ";
    cin >> generator;

    int generatorLength = generator.length();

    
    string temp = codeword;

    
    for (int i = 0; i <= temp.length() - generatorLength; i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < generatorLength; j++)
            {
                if (temp[i + j] == generator[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    
    string remainder = temp.substr(
        temp.length() - (generatorLength - 1)
    );

    
    bool error = false;

    for (char bit : remainder)
    {
        if (bit == '1')
        {
            error = true;
            break;
        }
    }

    cout << endl <<"-----{ CRC Receiver Side }-----" << endl;
    cout << "The Received Codeword is : " << codeword << endl;
    cout << "The Generator Bits are   : " << generator << endl;
    cout << "CRC Remainder Obtained   : " << remainder << endl;

    if (error)
    {
        cout << "Error Detection     : YES" << endl;
        cout << endl <<"Error is Present!!!" << endl;
    }
    else
    {
        cout << "Error Detection     : NO" << endl;
        cout << "No error detected." << endl;
    }

    return 0;
}

// Output :

// -----{ CRC Receiver Side }-----
// The Received Codeword is : 110110001011
// The Generator Bits are   : 1011
// CRC Remainder Obtained   : 110
// Error Detection     : YES

// Error is Present!!!