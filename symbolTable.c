#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.h"

/******************************************************************
 * This function uses the string argument to check if an identifier is 
 * already in the symbol table. If it is not in the symbol table, it
 * places it in the symbol table. Either way, it returns the address of
 * the associated node to the calling function.
 ******************************************************************/
struct symTabNode *lookup(char *givenLexeme) {
    unsigned int hash = RSHash(givenLexeme, (unsigned int) strlen(givenLexeme));
    int key = hash % SIZE;

    struct symTabNode *current = &symbolTable[key];
    int result = strcmp(current->lexeme, givenLexeme);
    if (result != 0) {
        while (current->next != 0) {
            current = current->next;
            result = strcmp(current->lexeme, givenLexeme);
            if (result == 0)
                break;
        }
    }


    if (result == 0);


    else if (strcmp(current->lexeme, "default") == 0) {
        current->lexeme = givenLexeme;
    }
    else {
        current->next = malloc(sizeof (struct symTabNode));
        current = current->next;
        current->lexeme = givenLexeme;
        current->next = 0;
    }


    return &*current;
}

/**********************************************************
 * algorithm from www.partow.net, based on algorithm 
 * by Robert Sedgewicks. A fairly generic hash function.
 **********************************************************/
unsigned int RSHash(char* str, unsigned int len) {
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;
    unsigned int i = 0;

    for (i = 0; i < len; str++, i++) {
        hash = hash * a + (*str);
        a = a * b;
    }

    return hash;
}

void symbolTableInitialization() {
    struct symTabNode * address;
    address = lookup("auto");
    address->kind = 1;

    address = lookup("break");
    address->kind = 2;

    address = lookup("case");
    address->kind = 3;

    address = lookup("char");
    address->kind = 4;

    address = lookup("const");
    address->kind = 5;

    address = lookup("continue");
    address->kind = 6;

    address = lookup("default");
    address->kind = 7;

    address = lookup("do");
    address->kind = 8;

    address = lookup("double");
    address->kind = 9;

    address = lookup("else");
    address->kind = 10;

    address = lookup("enum");
    address->kind = 11;

    address = lookup("extern");
    address->kind = 12;

    address = lookup("float");
    address->kind = 13;

    address = lookup("for");
    address->kind = 14;

    address = lookup("goto");
    address->kind = 15;

    address = lookup("if");
    address->kind = 16;

    address = lookup("int");
    address->kind = 17;

    address = lookup("long");
    address->kind = 18;

    address = lookup("register");
    address->kind = 19;

    address = lookup("return");
    address->kind = 20;

    address = lookup("short");
    address->kind = 21;

    address = lookup("signed");
    address->kind = 22;

    address = lookup("sizeof");
    address->kind = 23;

    address = lookup("static");
    address->kind = 24;

    address = lookup("struct");
    address->kind = 25;

    address = lookup("switch");
    address->kind = 26;

    address = lookup("typedef");
    address->kind = 27;

    address = lookup("union");
    address->kind = 28;

    address = lookup("unsigned");
    address->kind = 29;

    address = lookup("void");
    address->kind = 30;

    address = lookup("volatile");
    address->kind = 31;

    address = lookup("while");
    address->kind = 32;

}