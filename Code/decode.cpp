//
// Created by Matin Massoudi on 9/20/20.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

/**
 * Decodes input using insertion Sort.
 * @param inputString
 * @param index
 * @return
 */
static string insertionSortDecode(string inputString, int index)
{
    //variable declarations used for algorithm.
    string input = inputString;
    int n = input.length();
    string last = "";

    //Recover last v2.
    int counter = 0;
    string num = "";
    for (int i = 0; i < n; i++)
    {
        if(i==0){
            num = input[i];
            int j = 0;
            for(j = i+1; j < n; j++){
                if(isdigit(input[j])){
                    num+=input[j];
                }else{
                    break;
                }
            }
            i=j-1;

            for(int x = 0; x < stoi(num); x++){
                last+=input[i+2];
            }
        }

        if(input[i] == ' '){
            counter++;
        }

        if(counter == 2 && i != n-1){
            counter = 0;
            i+=1;
            num = input[i];
            int j = 0;
            for(j = i+1; j < n; j++){
                if(isdigit(input[j])){
                    num+=input[j];
                }else{
                    break;
                }
            }
            i=j-1;

            for(int x = 0; x < stoi(num); x++){
                last+=input[i+2];
            }

        }

    }


    //Store last into an array for easier sorting.
    int lastSize = last.size();
    char firstArray[lastSize];
    for (int i = 0; i < lastSize; i++)
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

    string finalOut = "";

    //Assembling original string
    int pos = next[index];
    for(int i = 0; i < lastSize; i++){
        finalOut+=last[pos];
        pos = next[pos];
    }


    return finalOut;
}


/**
 * Swap function that takes chars in an array and swaps them.
 * Used by partition function.
 * @param a
 * @param b
 */
void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Partition function used for quicksort.
 * @param arr
 * @param low
 * @param high
 * @return
 */
static int partition(char arr[], int low, int high)
{
    //Select last element as the pivot.
    char pivot = arr[high];
    int i = (low - 1);
    //Increment j and swap when j is less than the pivot.
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/**
 * Quicksort function that sorts char arrays recursively.
 * @param arr
 * @param low
 * @param high
 */
static void quickSort(char arr[], int low, int high)
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
 * Decodes input using insertion Sort.
 * @param inputString
 * @param index
 * @return
 */
static string quickSortDecode(string inputString, int index)
{
    //variable declarations used for algorithm.
    string input = inputString;
    int n = input.length();
    string last = "";

    //Recover last v2.
    int counter = 0;
    string num = "";
    for (int i = 0; i < n; i++)
    {
        if(i==0){
            num = input[i];
            int j = 0;
            for(j = i+1; j < n; j++){
                if(isdigit(input[j])){
                    num+=input[j];
                }else{
                    break;
                }
            }
            i=j-1;

            for(int x = 0; x < stoi(num); x++){
                last+=input[i+2];
            }
        }

        if(input[i] == ' '){
            counter++;
        }

        if(counter == 2 && i != n-1){
            counter = 0;
            i+=1;
            num = input[i];
            int j = 0;
            for(j = i+1; j < n; j++){
                if(isdigit(input[j])){
                    num+=input[j];
                }else{
                    break;
                }
            }
            i=j-1;

            for(int x = 0; x < stoi(num); x++){
                last+=input[i+2];
            }

        }

    }

    //Store last into an array for easier sorting.
    int lastSize = last.size();
    char firstArray[lastSize];
    for (int i = 0; i < lastSize; i++)
    {
        firstArray[i] = last[i];
    }

    //Sort last using quicksort.
    quickSort(firstArray, 0, lastSize-1);


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

    string finalOut = "";

    //Assembling original string
    int pos = next[index];
    for(int i = 0; i < lastSize; i++){
        finalOut+=last[pos];
        pos = next[pos];
    }


    return finalOut;
}


int main(int argc, char** argv)
{
    //testing
    //string input = "1 o 1   1 e 1 s 1 o 1 n 1 d 1 E 1 d 1 , 1 t 1 e 2 g 1 n 1 T 1 W 1 H 1   1 I 1   2 h 1 t 1 w 1 h 1   2 a 1   1 h 1 n 1 t 1 c 2 n 2   4 t 1 a 2 h 1 k 1   1 e 1 i 1 O 2 i 1   1 d 1 t 1 n 1 e 2 a 1 r 1 t 2   1 o 2   1 i 1  ";
    //cout << endl << "Testing Output: " << insertionSortDecode(input,0);


    //string encodingType = argv[1];
    string encodingType = "insertion";
    int indexInput = 0;
    string paramPass = "";
    int counter = 0;

    if(encodingType.compare("insertion") == 0)
    {
        string input = "";
        while (getline(cin, input)){
            if (input.length() != 0)
            {
                if(counter == 0)
                {
                    indexInput = stoi(input);
                    counter++;
                }else
                {
                    paramPass = input;
                    counter--;
                }

                if (counter == 0)
                {
                    cout << insertionSortDecode(paramPass, indexInput) << endl;
                }
            }else
            {
                cout << endl;
            }
        }
    }else if (encodingType.compare("quick") == 0)
    {
        string input = "";
        while (getline(cin, input)){
            if (input.length() != 0)
            {
                if(counter == 0)
                {
                    indexInput = stoi(input);
                    counter++;
                }else
                {
                    paramPass = input;
                    counter--;
                }

                if (counter == 0)
                {
                    cout << quickSortDecode(paramPass, indexInput) << endl;
                }
            }else
            {
                cout << endl;
            }
        }
    }else
    {
        cout << "Unknown decoding scheme!";
    }


    return 0;
}