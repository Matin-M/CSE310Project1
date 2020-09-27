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
 * Encode string using insertion sort algorithm.
 * @param input
 * @return
 */
static string insertionSortEncode(string inputString)
{
    //variable declarations used for algorithm.
    string input = inputString;
    string originalInput = inputString;
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

    //Sort pointer array using insertion sort.
    int j;
    int i;
    string* key;
    for (i = 1; i < n; i++)
    {
        key = stringPointers[i];
        j = i - 1;
        //Find and swap pointers within array of pointers.
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
        //Find consecutive characters, and tally. Store tally result into an array, then move on
        //To next char sequence.
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

    }

    //Concat stores result of decoded string.
    //Concat results with return string returnVal.
    string concat = "";
    for(int i = 0; i < n; i++)
    {
        if (freq[i] != -1)
        {
            //Remove last space.
            if ((freq[i] != -1) && (i == n-1))
            {
                concat += to_string(freq[i])+" "+lastChars[i];
            }else {
                concat += to_string(freq[i])+" "+lastChars[i]+" ";
            }

        }
    }

    //Concatenate the index of original string with the decoded output, then return.
    return to_string(originalIndex)+"\n"+concat;
}


/**
 * Swap function that takes two pointers and swaps their addresses.
 * Used by partition function.
 * @param a
 * @param b
 */
void swap(string** a, string** b)
{
    string* t;
    t = *a;
    *a = *b;
    *b = t;
}

/**
 * Partition function used for quicksort.
 * @param arr
 * @param low
 * @param high
 * @return
 */
static int partition(string* arr[], int low, int high)
{
    //Select last element as the pivot.
    string* pivot = arr[high];
    int i = (low - 1);
    //Increment j and swap when j is less than the pivot.
    for (int j = low; j <= high - 1; j++)
    {
        if ((*arr[j]).compare(*pivot) < 0)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/**
 * Quicksort function that sorts an array of string pointers recursively.
 * @param arr
 * @param low
 * @param high
 */
static void quickSort(string* arr[], int low, int high)
{
    if (low < high)
    {
        //Divide and recursive conquer step.
        int part = partition(arr, low, high);
        quickSort(arr, low, part - 1);
        quickSort(arr, part + 1, high);
    }
}

/**
 * Encode string using quicksort algorithm.
 * @param input
 * @return
 */
static string quickSortEncode(string inputString)
{
    //variable declarations used for algorithm.
    string input = inputString;
    string originalInput = inputString;
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

    //Sort pointer array using quicksort.
    quickSort(stringPointers, 0, n-1);

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
        //Find consecutive characters, and tally. Store tally result into an array, then move on
        //To next char sequence.
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

    }

    //Concat stores result of decoded string.
    //Concat results with return string returnVal.
    string concat = "";
    for(int i = 0; i < n; i++)
    {
        if (freq[i] != -1)
        {
            //Remove last space.
            if ((freq[i] != -1) && (i == n-1))
            {
                concat += to_string(freq[i])+" "+lastChars[i];
            }else {
                concat += to_string(freq[i])+" "+lastChars[i]+" ";
            }

        }
    }

    //Concatenate the index of original string with the decoded output, then return.
    return to_string(originalIndex)+"\n"+concat;
}




int main(int argc, char** argv)
{
    //Store insertion/quick argument in encodingType.
    string encodingType = argv[1];

    if(encodingType.compare("quick") == 0)
    {
        //Display each line of encoded text, using the insertion sort method.
        string input = "";
        while (!getline(cin, input).eof()){
            if (input.length() != 0)
            {
                cout << quickSortEncode(input) << endl;
            }else
            {
                cout << endl;
            }
        }
    }else if (encodingType.compare("insertion") == 0)
    {
        //Display each line of encoded text, using the quicksort method.
        string input = "";
        while (!getline(cin, input).eof()){
            if (input.length() != 0)
            {
                cout << insertionSortEncode(input) << endl;
            }else
            {
                cout << endl;
            }
        }
    }else
    {
        cout << "Unknown encoding scheme!";
    }



    return 0;
}



