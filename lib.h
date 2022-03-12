#ifndef __LIB__H__
#define __LIB__H__



/*
 Define the types that will be used in this library
*/
typedef enum {
    false,
    true ,
}Bool;
typedef char * string ;

/*---------------------------FIRST FOR INTEGERS-------------------------------------------*/
/*Define the integer linked list */
typedef struct IntegerList
{
    int value ;
    struct IntegerList * next ;
}IntegerList , *IntList;

/*Prototypes*/ 
IntList new_int_list(void);
Bool isEmptyIntList(IntList list);
int sizeIntList(IntList list);
void printIntList(IntList list);
IntList addInt(int value ,IntList list);
IntList addIntFront(int value , IntList list);
IntList popInt(IntList list);
IntList popIntFront(IntList list);
IntList clearIntList(IntList list);
int getIntIndex(IntList list, int value);
int getIntAtIndex(IntList list ,int index);
IntList sortIntList(IntList list);

/*---------------------------END FOR INTEGERS-------------------------------------------*/

/*---------------------------SECOND FOR STRINGS-------------------------------------------*/
/*define the string list structure*/
typedef struct CharList{
    string str;
    struct CharList * next;
}CharList , *StringList;
/*prototypes*/
StringList new_string_list(void);
Bool isEmptyStringList(StringList list);
int sizeStringList(StringList list);
void printStringList(StringList list);
StringList addString(string value ,StringList list);
StringList addStringFront(string value , StringList list);
StringList popString(StringList list);
StringList popStringFront(StringList list);
StringList clearStringList(StringList list);
int getStringIndex(StringList list, string value);
string getStringAtIndex(StringList list ,int index);
StringList sortStringList(StringList list);
/*---------------------------END FOR STRINGS-------------------------------------------*/

/*---------------------------FIRST FOR INTEGERS-------------------------------------------*/
/*Define the integer linked list */
typedef struct doubleList
{
    double value ;
    struct doubleList * next ;
}doubleList , *DoubleList;

/*Prototypes*/ 
DoubleList new_double_list(void);
Bool isEmptyDoubleList(DoubleList list);
int sizeDoubleList(DoubleList list);
void printDoubleList(DoubleList list);
DoubleList addDouble(double value ,DoubleList list);
DoubleList addDoubleFront(double value , DoubleList list);
DoubleList popDouble(DoubleList list);
DoubleList popDoubleFront(DoubleList list);
DoubleList clearDoubleList(DoubleList list);
int getDoubleIndex(DoubleList list, double value);
double getDoubleAtIndex(DoubleList list ,int index);
DoubleList sortDoubleList(DoubleList list);




#endif