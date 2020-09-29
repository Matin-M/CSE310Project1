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

    //Store last into an array for easier sorting.
    int lastSize = last.size();
    char firstArray[lastSize];
    for (int i = 0; i < n; i++)
    {
        firstArray[i] = last[i];
    }

    //Sort last using insertion sort.
    int j;
    int i;
    char key;
    for (i = 1; i < lastSize; i++)
    {
        key = firstArray[i];
        j = i - 1;
        while (j >= 0 && (firstArray[j] > key))
        {
            firstArray[j + 1] = firstArray[j];
            j = j - 1;
        }
        firstArray[j + 1] = key;
    }


    //Declaring variables for next array computation.
    int next[lastSize];
    bool isUsed[lastSize];
    //Init all values to true.
    for (int i = 0; i < lastSize; i++)
    {
        isUsed[i] = true;
    }

    //Computing next array.
    for (int i = 0; i < lastSize; i++)
    {
        char first = firstArray[i];
        for (int j = 0; j < lastSize; j++)
        {
            if((first == last[j]) && isUsed[j])
            {
                next[i] = j;
                isUsed[j] = false;
                break;
            }
        }
    }

    //Debugging.
    cout << endl;
    for (int i = 0; i < lastSize; i++)
    {
        cout << next[i] << " ";
    }


    return last;
}

//UNCOMMENT BEFORE TESTING  AND SUBMISSION!!!
//int main(int argc, char** argv)
int main()
{
    string input = "1 d 1 n 1 c 3 a";
    //getline(cin, input);
    cout << endl << "insertion output: " << insertionSortDecode(input,3);

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