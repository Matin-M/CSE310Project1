//
// Created by Matin Massoudi on 9/2/20.
//


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

static string testingFunc(string input)
{
    string returnVal = "";
    int n = input.length();
    string* pointerArray[n];
    pointerArray[0] = &returnVal;

    string arrayString[3] = {"a","b","c"};
    pointerArray[1] = arrayString;

    string test = "sdf";
    test[2] = 'a';

    return *(pointerArray[1]+1);
}

static string insertionSortEncode(string input)
{
    //Method declarations.
    string returnVal = "";
    int n = input.length();
    string stringArray[n];

    //Shift and store strings within StringArray.
    stringArray[0] = input;
    for(int i = 1; i < n; i++)
    {
        char temp = input[0];
        int j;
        for(j = 0; j < n-1; j++)
        {
            input[j] = input[j+1];
        }
        input[j] = temp;

        stringArray[i] = input;
    }

    //Assign pointers to each string element within stringArray.
    string* stringPointers[n];
    for(int i = 0; i < n; i++)
    {
        stringPointers[i] = &stringArray[i];
    }

    //debug
    cout << "N is: "<< n << endl;

    for(int i = 0; i < n; i++){
        cout << *stringPointers[i] << endl;
    }

    return returnVal;
}

int main() {
    string input = "";
    cin >> input;
    cout << "The output was: " <<  insertionSortEncode(input);
    return 0;
}



