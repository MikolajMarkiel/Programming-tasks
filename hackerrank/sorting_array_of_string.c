/*
Task found at:
https://www.hackerrank.com/challenges/sorting-array-of-strings/problem?isFullScreen=true

Author of solution: Mikolaj Markiel

To sort a given array of strings into lexicographically increasing order or into an order in which 
the string with the lowest length appears first, a sorting function with a flag indicating the type 
of comparison strategy can be written. The disadvantage with doing so is having to rewrite 
the function for every new comparison strategy. A better implementation would be to write a sorting 
function that accepts a pointer to the function that compares each pair of strings. Doing this will 
mean only passing a pointer to the sorting function with every new comparison strategy.

Given an array of strings, you need to implement a  function which sorts the strings according to 
a comparison function, i.e, you need to implement the function :

void string_sort(const char **arr,const int cnt, int (*cmp_func)(const char* a, const char* b)){
    
}
The arguments passed to this function are:

an array of strings : 
length of string array: 
pointer to the string comparison function: 
You also need to implement the following four string comparison functions:

 to sort the strings in lexicographically non-decreasing order.

 to sort the strings in lexicographically non-increasing order.

 to sort the strings in non-decreasing order of the number of distinct characters present in them. 
 If two strings have the same number of distinct characters present in them, then the lexicographically 
 smaller string should appear first.

 to sort the strings in non-decreasing order of their lengths. If two strings have the same length, 
 then the lexicographically smaller string should appear first.

Input Format

You just need to complete the function string\_sort and implement the four string comparison functions.

Constraints

 No. of Strings 
 Total Length of all the strings 
You have to write your own sorting function and you cannot use the inbuilt  function
The strings consists of lower-case English Alphabets only.
Output Format

The locked code-stub will check the logic of your code. The output consists of the strings sorted 
according to the four comparsion functions in the order mentioned in the problem statement.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    int i = 0;
    while(a[i] == b[i] || a == 0 || b == 0){
        i++;
    }
    return a[i] < b[i] ? 0 : 1;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    int i = 0;
    while(a[i] == b[i] || a == 0 || b == 0){
        i++;
    }
    return a[i] > b[i] ? 0 : 1;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int cnt_a = 0;
    int cnt_b = 0;
    int tmp = 0;
    for (int i = 0; i< strlen(a); i++){
        tmp = 1;
        for (int j = 0; j < i; j++){
            tmp = a[j] == a[i] ? 0 : tmp;
        } 
        cnt_a += tmp;
    }
    for (int i = 0; i< strlen(b); i++){
        tmp = 1;
        for (int j = 0; j < i; j++){
            tmp = b[j] == b[i] ? 0 : tmp;
        } 
        cnt_b += tmp;
    }
    if (cnt_a == cnt_b){
        return lexicographic_sort(a, b);
    }
    return cnt_a < cnt_b ? 0 : 1; 
}

int sort_by_length(const char* a, const char* b) {
    if (strlen(a) == strlen(b)){
        return lexicographic_sort(a, b);
    }
    return strlen(a) < strlen(b) ? 0 : 1;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int change = 1;
    char *tmp = NULL;
    while(change){
        change = 0;
        for(int i = 0; i < len-1; i++){
            if ((*cmp_func)(arr[i], arr[i+1])){
                change = 1;
                tmp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}
int main() 
{
    int n;
    /* custom input code
    
    scanf("%d", &n);
  
    char** arr;

	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
    */

    // default input:
    char *arr[] = {"wkue", "qoi", "sbv", "fekls"};
    n = 4;

    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}