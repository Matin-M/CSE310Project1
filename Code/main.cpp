//
// Created by Matin Massoudi on 9/2/20.
//


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

/**
 * Encode string using insertion sort method.
 * @param input
 * @return
 */
static string insertionSortEncode(string input)
{
    //variable declarations.
    string originalInput = input;
    string returnVal = "";
    int n = input.length();
    string stringArray[n];

    cout << "The input was: " << originalInput;

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

    //Find position of original string in pointerArray.
    int originalIndex;
    for(int i = 0; i < n; i++)
    {
        if((*stringPointers[i]).compare(originalInput) == 0)
        {
            originalIndex = i;
            break;
        }
    }

    //Tally last row of string column and store into array.
    int freq[n];
    int incrementor;
    for(int i = 0; i < n; i++)
    {
        char last = (*stringPointers[i])[n-1];
        incrementor = 0;
        for(int j = i+1; j < n; j++)
        {
            if(last == (*stringPointers[j])[n-1])
            {
                incrementor++;
            } else
            {
                break;
            }
        }
        i+=incrementor;

        freq[i] = incrementor+1;
        cout << endl;
        cout << incrementor+1 << " ";
    }

    cout << endl << "Sorted Array Matrix: " << endl;

    //debug
    for(int i = 0; i < n; i++)
    {
        cout << *stringPointers[i] << endl;
    }

    cout << "Orignal Index: " << originalIndex << endl;

    return returnVal;
}

int main() {
    string input = "";
    cin >> input;
    cout << "The output was: " <<  insertionSortEncode(input);
    return 0;
}



