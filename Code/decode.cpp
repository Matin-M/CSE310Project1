//
// Created by Matin Massoudi on 9/20/20.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

static string insertionSortDecode(string inputString, int index)
{
    //variable declarations used for algorithm.
    string input = inputString;
    string originalInput = inputString;
    int n = input.length();
    string last = "";

    //Recover Last
    for(int i = 2; i < n; i+=4)
    {
        for(int j = 0; j<(input[i-2]-48); j++)
        {
            last += input[i];
        }
    }

    return last;
}

int main(int argc, char** argv)
{
    string input = "";
    getline(cin, input);
    cout << insertionSortDecode(input,0);

    //Input parsing disabled for current testing.
    //Store insertion/quick argument in encodingType.
    /*
    string encodingType = argv[1];

    if(encodingType.compare("quick") == 0)
    {
        string input = "";
        while (getline(cin, input)){

        }
    }else if (encodingType.compare("insertion") == 0)
    {
        string input = "";
        while (getline(cin, input)){

        }
    }else
    {
        cout << "Unknown encoding scheme!";
    }
     */



    return 0;
}