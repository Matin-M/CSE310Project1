//
// Created by Matin Massoudi on 9/2/20.
//


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
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
    int n = input.length();
    string stringArray[n];

    cout << "The original input was: " << originalInput;

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

    //Create a string of only the last chars. Used for final output.
    string lastChars = "";
    for(int i = 0; i < n; i++)
    {
        lastChars += (*stringPointers[i])[n-1];
    }

    //Set every element in frequency to default value -1.
    int freq[n];
    for(int i = 0; i < n; i++)
    {
        freq[i] = -1;
    }

    //Tally last row of string column and store into array.
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

        //Assign positions to incrementor.
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

    //Concat results with return string returnVal.
    string concat = "";
    for(int i = 0; i < n; i++)
    {
        if (freq[i] != -1)
        {
            //Remove last space.
            if ((freq[i] != -1) && (i == n-1))
            {
                concat += to_string(freq[i])+lastChars[i];
            }else {
                concat += to_string(freq[i])+lastChars[i]+" ";
            }

        }
    }


    return to_string(originalIndex)+"\n"+concat;
}

int main() {
    string input = "";
    cin >> input;
    cout << insertionSortEncode(input);
    return 0;
}



