/*
Task found at:
https://www.hackerrank.com/challenges/printing-tokens-/problem?isFullScreen=true

Given a sentence, , print each word of the sentence in a new line.
Input Format
The first and only line contains a sentence, .
Constraints


Output Format
Print each word of the sentence in a new line.


Author of solution: Mikolaj Markiel

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.
    for (int i = 0; i < strlen(s); i++){
        s[i] = s[i] == ' ' ? '\n' : s[i];
    }
    printf("%s", s);
    return 0;
}