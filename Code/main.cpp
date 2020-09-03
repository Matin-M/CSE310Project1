//
// Created by Matin Massoudi on 9/2/20.
//


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;


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

    //Sort pointer array:
    int j;
    int i;
    string* key;
    for (i = 1; i < n; i++)
    {
        key = stringPointers[i];
        j = i - 1;
        while (j >= 0 && (*stringPointers[j]).compare(*key) > 0)
        {
            stringPointers[j + 1] = stringPointers[j];
            j = j - 1;
        }
        stringPointers[j + 1] = key;
    }

    //debug

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



