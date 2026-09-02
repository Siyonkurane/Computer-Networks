#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data, generator;

    cout << "Enter The Data Bits: ";
    cin >> data;

    cout << "Enter The Generator Bits: ";
    cin >> generator;

    int generatorLength = generator.length();

    // Append zeros
    string zeroAppended = data;

    for (int i = 0; i < generatorLength - 1; i++)
    {
        zeroAppended += '0';
    }

    
    string temp = zeroAppended;

    
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

    
    string codeword = data + remainder;

    cout << endl <<"-----{ CRC Sender Side }-----" << endl;
    cout << "Given Data Bits            : " << data << endl;
    cout << "Generator bits {Divisor}   : " << generator << endl;
    cout << "Appended Zeros {Divisor-1} : " << zeroAppended << endl;
    cout << "Redundant bits Received    : " << remainder << endl;
    cout << "Codeword Obtained          : " << codeword << endl;

    return 0;
}

// Output :

// -----{ CRC Sender Side }-----
// Given Data Bits            : 1011000101
// Generator bits {Divisor}   : 10011
// Appended Zeros {Divisor-1} : 10110001010000
// Redundant bits Received    : 1011
// Codeword Obtained          : 10110001011011