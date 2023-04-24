/*
Task found at:
https://www.hackerrank.com/challenges/querying-the-document/problem?isFullScreen=true

A document is represented as a collection paragraphs,
a paragraph is represented as a collection of sentences,
a sentence is represented as a collection of words and
a word is represented as a collection of lower-case ([a-z]) and upper-case ([A-Z]) English characters.

You will convert a raw text document into its component paragraphs, sentences and words. 
To test your results, queries will ask you to return a specific paragraph, sentence or word as described below.

Alicia is studying the C programming language at the University of Dunkirk 
and she represents the words, sentences, paragraphs, and documents using pointers:

A word is described by char*.
A sentence is described by char**. The words in the sentence are separated by one space (" "). 
The last word does not end with a space(" ").
A paragraph is described by char***. The sentences in the paragraph are separated by one period (".").
A document is described by char****. The paragraphs in the document are separated by one newline("\n"). 
The last paragraph does not end with a newline.

The text which is passed to the get_document() has words separated by a space (" "), 
sentences separated by a period (".") and paragraphs separated by a newline("\n").
The last word in a sentence does not end with a space.
The last paragraph does not end with a newline.
The words contain only upper-case and lower-case English letters.
 1 <= number of characters in the entire document <= 1000
 1 <= number of paragraphs in the entire document <= 5


Author of solution: Mikolaj Markiel

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

char**** get_document(char* text) {

    char **** doc;
    char ***tmp_d[MAX_PARAGRAPHS]; 
    char **tmp_p[MAX_CHARACTERS]; 
    char *tmp_s[MAX_CHARACTERS];  
    char *tmp_w = NULL;   

    int len_w = 0;
    int len_s = 0;
    int len_p = 0;
    int len_d = 0;

    for (int i = 0; i <= strlen(text); i++){
        if (text[i] == '\n' || text[i] == '.' || text[i] == ' '){
            if(tmp_w != NULL){
                tmp_s[len_s] = (char*)malloc(len_w * sizeof(char));
                memset(tmp_s[len_s], 0, len_w * sizeof(char));
                memcpy(tmp_s[len_s], tmp_w, len_w * sizeof(char));
                len_s++;
            }
            tmp_w = NULL;
            len_w = 0;
        } else if (text[i] != 0){
            tmp_w = tmp_w == NULL ? &text[i] : tmp_w;
            len_w++;
        } 

        if (text[i] == '.'){
            tmp_p[len_p] = (char**)malloc((len_s) * sizeof(char*));
            memcpy(tmp_p[len_p], tmp_s, (len_s) * sizeof(char*));
            len_s = 0;
            len_p++;
        }

        if (text[i] == '\n' || text[i] == 0){
            tmp_d[len_d] = (char***)malloc((len_p) * sizeof(char**));
            memcpy(tmp_d[len_d], tmp_p, (len_p) * sizeof(char**));
            len_p = 0;
            len_d++;
        }
    }
 
    doc = (char****)malloc(len_d * sizeof(char***));
    memcpy(doc, tmp_d, len_d * sizeof(char***));
    return doc;
}


char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}