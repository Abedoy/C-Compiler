/* 
 * File:   symbolTable.h
 * Author: Michael Hill
 *
 * Created on October 19, 2015, 11:51 AM
 */

#ifndef SYMBOLTABLE_H
#define	SYMBOLTABLE_H
#define SIZE 997

struct paramList
{
    // should be either an int or a float
    char *type;
    int intValue;
    float floatValue;
    struct paramList* next;
};


struct symTabNode
{
    char *lexeme;
    int value;
    int kind;
    struct symTabNode *next;
    struct paramList *param;
};

// global variable so that lookup only need be given a string
struct symTabNode symbolTable[SIZE];

unsigned int RSHash(char* str, unsigned int len);
struct symTabNode *lookup(char *givenLexeme);
void symbolTableInitialization();


#endif	/* SYMBOLTABLE_H */


