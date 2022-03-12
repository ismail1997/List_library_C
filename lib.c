#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include"lib.h"

IntList new_int_list(void)
{
    return NULL;
}
/*---------------------------------------------------*/
Bool isEmptyIntList(IntList list)
{
    if(list==NULL)
        return true;
    return false;    
}
/*---------------------------------------------------*/
int sizeIntList(IntList list)
{
    int size = 0;
    if(isEmptyIntList(list))
        return size;
    while(list != NULL)
    {
        ++size;
        list = list->next;
    }
    return size;
}
/*---------------------------------------------------*/
void printIntList(IntList list)
{
    if(isEmptyIntList(list))
    {
        printf("The list is empty, there is nothing to show :(\n");
        return;
    }
    printf("[");
    while(list != NULL)
    {
        printf("%d,",list->value);
        list=list->next;
    }
    printf("]\n");
}
/*---------------------------------------------------*/
IntList addInt(int value,IntList list)
{
    IntegerList * element = new_int_list();
    element=malloc(sizeof(* element));

    if(element ==NULL )
    {
        fprintf(stderr,"Error : Alocation of memory has failed :(\n");
        exit(1);
    }

    element->value=value;
    element->next=NULL;

    if(isEmptyIntList(list))
        return element;
    
    IntegerList * temp ;
    temp=list;
    
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=element;

    return list;
}
/*---------------------------------------------------*/
IntList addIntFront(int value , IntList list)
{
    IntegerList * element = new_int_list();
    element=malloc(sizeof(* element));

    if(element ==NULL )
    {
        fprintf(stderr,"Error : Alocation of memory has failed :(\n");
        exit(1);
    }

    element->value=value;

    if(isEmptyIntList(list))
    {
        element->next=NULL;
    }else
    {
        element->next=list;
    }
    
    return element;
    
}
/*---------------------------------------------------*/
IntList popInt(IntList list)
{
    if(isEmptyIntList(list))
        return new_int_list();

    if(list->next==NULL)
    {
        free(list);
        list=NULL;
        return new_int_list();
    }  

    IntegerList * temp = list;
    IntegerList * before = list;

    while(temp->next != NULL )
    {
        before = temp;
        temp = temp->next;
    }

    before ->next = NULL ;
    free(temp);
    temp=NULL;
    return list;
}
/*---------------------------------------------------*/
IntList popIntFront(IntList list)
{
    if(isEmptyIntList(list))
        return new_int_list();
    if(list->next ==NULL)
    {
        free(list);
        list =NULL;
        return new_int_list();
    }

    IntegerList * element;
    element = malloc(sizeof(*element));

    if(element ==NULL )
    {
        fprintf(stderr,"Error : Alocation of memory has failed :(\n");
        exit(1);
    }

    element=list->next;
    free(list);
    list=NULL;
    return element;
}
/*---------------------------------------------------*/
IntList clearIntList(IntList list)
{
    if(isEmptyIntList(list))
    {
        return new_int_list();
    }
    while(list != NULL)
    {
        list=popIntFront(list);
    }
}
/*---------------------------------------------------*/
int getIntIndex(IntList list, int value)
{
    int sizeOfList = sizeIntList(list);
    int index = -1;
    if(isEmptyIntList(list))
    {
        return index;
    }
    index = 0 ;
    while(list != NULL && list->value !=value)
    {   
        ++index;
        list=list->next;
        
    }
    if(index >= sizeOfList) index=-1;
    return index;
}
/*---------------------------------------------------*/
int getIntAtIndex(IntList list ,int index)
{
    if(isEmptyIntList(list)){
        fprintf(stderr,"The list is empty :(\n");
        exit(1);
    }

    int sizeOfList = sizeIntList(list);
    if(index >= sizeOfList || index <0) 
    {
        fprintf(stderr,"!!Index out of bounds\n");
        exit(1);
    }
    int count = -1;
    while(list != NULL)
    {
        ++count;
        if(count == index)
        {
            return list->value;
        }
        list = list->next;
    }
    if(count>=sizeOfList)
    {
        fprintf(stderr," Index out of bounds\n");
        exit(1);
    }
    
}
/*---------------------------------------------------*/
IntList sortIntList(IntList list)
{
    if(isEmptyIntList(list))
        return new_int_list();
    if(list->next==NULL)
        return list;
    
    IntegerList * temp , *pointer;
    int valuePermuted = 0;

    for(temp = list ; temp->next !=NULL ; temp=temp->next)
    {
        for(pointer = temp->next ; pointer != NULL ; pointer = pointer->next)
        {
            if((pointer->value)<(temp->value))
            {
                valuePermuted = pointer->value;
                pointer->value = temp->value;
                temp->value = valuePermuted;
            }
        }    
    }
    return list;
}

/*####################################################################*/

StringList new_string_list(void)
{
    return NULL;
}
/*---------------------------------------------------*/
Bool isEmptyStringList(StringList list)
{
    if(list ==NULL )
        return true ;
    return false ;
}
/*---------------------------------------------------*/
int sizeStringList(StringList list)
{
    int size = 0;
    if(isEmptyStringList(list)) return size;
    while(list !=NULL)
    {
        ++size;
        list = list->next;
    }
    return size;
}
/*---------------------------------------------------*/
void printStringList(StringList list)
{
    if(isEmptyStringList(list))
    {
        printf("The list is empty, there is nothing to show :(\n");
        return;
    }
    printf("[");
    while(list != NULL)
    {
        printf("%s,",list->str);
        list=list->next;
    }
    printf("]\n");
}
/*---------------------------------------------------*/
StringList addString(string value ,StringList list)
{

    CharList * element = new_string_list() ;
    element = malloc(sizeof(* element));

    if(element ==NULL )
    {
        fprintf(stderr,"Error : Alocation of memory has failed :(\n");
        exit(1);
    }

    element->str= malloc(strlen(value)+1); //alocate memory to hold the string value 
    strcpy(element->str,value);
    element->next=NULL;

    if(isEmptyStringList(list))
    {
        return element;
    }
    CharList * temp;
    temp = list;

    while(temp->next != NULL )
    {
        temp=temp->next;
    }
    temp->next=element;

    return list;
}
/*---------------------------------------------------*/
StringList addStringFront(string value , StringList list)
{
    CharList * element = new_string_list() ;
    element = malloc(sizeof(* element));

    if(element ==NULL )
    {
        fprintf(stderr,"Error : Alocation of memory has failed :(\n");
        exit(1);
    }

    element->str= malloc(strlen(value)+1); //alocate memory to hold the string value 
    strcpy(element->str,value);
    if(isEmptyStringList(list))
        element->next=NULL;
    else 
        element->next=list;
    
    return element;
}
/*---------------------------------------------------*/
StringList popString(StringList list)
{
    if(isEmptyStringList(list))
        return new_string_list();
    if(list->next==NULL)
    {
        free(list);
        list=NULL;
        return new_string_list();
    }
    CharList * temp = list;
    CharList * before = list;
    while(temp->next != NULL)
    {
        before=temp;
        temp=temp->next;
    }
    before->next=NULL;
    free(temp);
    temp =NULL;
    return list;
}
/*---------------------------------------------------*/
StringList popStringFront(StringList list)
{
    if(isEmptyStringList(list))
        return new_string_list();
    
    if(list->next==NULL)
    {
        free(list);
        list=NULL;
        return new_string_list();
    }
    CharList * element ;
    element = malloc(sizeof(* element));

    if(element==NULL )
    {
        fprintf(stderr,"Error : failed allocation of memory :(\n");
        exit(1);
    }
    element = list->next;
    free(list);
    return element;
}
/*---------------------------------------------------*/
StringList clearStringList(StringList list)
{
     if(isEmptyStringList(list))
    {
        return new_string_list();
    }
    while(list != NULL)
    {
        list=popStringFront(list);
    }
}
/*---------------------------------------------------*/
int getStringIndex(StringList list, string value)
{
    int sizeOfList = sizeStringList(list);
    int index = -1;
    if(isEmptyStringList(list))
    {
        return index;
    }
    index = 0 ;
    while(list != NULL && strcmp(list->str,value) != 0)
    {   
        ++index;
        list=list->next;
        
    }
    if(index >= sizeOfList) index=-1;
    return index;
}
/*---------------------------------------------------*/
string getStringAtIndex(StringList list ,int index)
{
     if(isEmptyStringList(list)){
        fprintf(stderr,"The list is empty :(\n");
        exit(1);
    }

    int sizeOfList = sizeStringList(list);
    if(index >= sizeOfList || index <0) 
    {
        fprintf(stderr,"!!Index out of bounds\n");
        exit(1);
    }
    int count = -1;
    while(list != NULL)
    {
        ++count;
        if(count == index)
        {
            return list->str;
        }
        list = list->next;
    }
    if(count>=sizeOfList)
    {
        fprintf(stderr," Index out of bounds\n");
        exit(1);
    }
}
/*---------------------------------------------------*/
StringList sortStringList(StringList list)
{
   if(isEmptyStringList(list))
        return new_string_list();
    if(list->next==NULL)
        return list;
    
    CharList * temp , *pointer;
    char valuePermuted [100];

    for(temp = list ; temp->next !=NULL ; temp=temp->next)
    {
        for(pointer = temp->next ; pointer != NULL ; pointer = pointer->next)
        {
            if(strcmp((pointer->str),(temp->str))<0)
            {
                strcpy(valuePermuted , pointer->str);
                strcpy(pointer->str , temp->str);
                strcpy(temp->str ,valuePermuted);
            }
        }    
    }
    return list;
}


/*####################################################################*/

DoubleList new_double_list(void)
{
    return NULL;
}
/*---------------------------------------------------*/
Bool isEmptyDoubleList(DoubleList  list)
{
    if(list==NULL)
        return true;
    return false;    
}
/*---------------------------------------------------*/
int sizeDoubleList(DoubleList list)
{
    int size = 0;
    if(isEmptyDoubleList(list))
        return size;
    while(list != NULL)
    {
        ++size;
        list = list->next;
    }
    return size;
}
/*---------------------------------------------------*/
void printDoubleList(DoubleList list)
{
    if(isEmptyDoubleList(list))
    {
        printf("The list is empty, there is nothing to show :(\n");
        return;
    }
    printf("[");
    while(list != NULL)
    {
        printf("%lf,",list->value);
        list=list->next;
    }
    printf("]\n");
}
/*---------------------------------------------------*/
DoubleList addDouble(double value,DoubleList list)
{
    doubleList * element = new_double_list();
    element=malloc(sizeof(* element));

    if(element ==NULL )
    {
        fprintf(stderr,"Error : Alocation of memory has failed :(\n");
        exit(1);
    }

    element->value=value;
    element->next=NULL;

    if(isEmptyDoubleList(list))
        return element;
    
    doubleList * temp ;
    temp=list;
    
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=element;

    return list;
}
/*---------------------------------------------------*/
DoubleList addDoubleFront(double value , DoubleList list)
{
    doubleList * element = new_double_list();
    element=malloc(sizeof(* element));

    if(element ==NULL )
    {
        fprintf(stderr,"Error : Alocation of memory has failed :(\n");
        exit(1);
    }

    element->value=value;

    if(isEmptyDoubleList(list))
    {
        element->next=NULL;
    }else
    {
        element->next=list;
    }
    
    return element;
    
}
/*---------------------------------------------------*/
DoubleList popDouble(DoubleList list)
{
    if(isEmptyDoubleList(list))
        return new_double_list();

    if(list->next==NULL)
    {
        free(list);
        list=NULL;
        return new_double_list();
    }  

    doubleList * temp = list;
    doubleList * before = list;

    while(temp->next != NULL )
    {
        before = temp;
        temp = temp->next;
    }

    before ->next = NULL ;
    free(temp);
    temp=NULL;
    return list;
}
/*---------------------------------------------------*/
DoubleList popDoubleFront(DoubleList list)
{
    if(isEmptyDoubleList(list))
        return new_double_list();
    if(list->next ==NULL)
    {
        free(list);
        list =NULL;
        return new_double_list();
    }

    doubleList * element;
    element = malloc(sizeof(*element));

    if(element ==NULL )
    {
        fprintf(stderr,"Error : Alocation of memory has failed :(\n");
        exit(1);
    }

    element=list->next;
    free(list);
    list=NULL;
    return element;
}
/*---------------------------------------------------*/
DoubleList clearDoubleList(DoubleList list)
{
    if(isEmptyDoubleList(list))
    {
        return new_double_list();
    }
    while(list != NULL)
    {
        list=popDoubleFront(list);
    }
}
/*---------------------------------------------------*/
int getDoubleIndex(DoubleList list, double value)
{
    int sizeOfList = sizeDoubleList(list);
    int index = -1;
    if(isEmptyDoubleList(list))
    {
        return index;
    }
    index = 0 ;
    while(list != NULL && list->value !=value)
    {   
        ++index;
        list=list->next;
        
    }
    if(index >= sizeOfList) index=-1;
    return index;
}
/*---------------------------------------------------*/
double getDoubleAtIndex(DoubleList list ,int index)
{
    if(isEmptyDoubleList(list)){
        fprintf(stderr,"The list is empty :(\n");
        exit(1);
    }

    int sizeOfList = sizeDoubleList(list);
    if(index >= sizeOfList || index <0) 
    {
        fprintf(stderr,"!!Index out of bounds\n");
        exit(1);
    }
    int count = -1;
    while(list != NULL)
    {
        ++count;
        if(count == index)
        {
            return list->value;
        }
        list = list->next;
    }
    if(count>=sizeOfList)
    {
        fprintf(stderr," Index out of bounds\n");
        exit(1);
    }
    
}
/*---------------------------------------------------*/
DoubleList sortDoubleList(DoubleList list)
{
    if(isEmptyDoubleList(list))
        return new_double_list();
    if(list->next==NULL)
        return list;
    
    doubleList * temp , *pointer;
    double valuePermuted = 0.0;

    for(temp = list ; temp->next !=NULL ; temp=temp->next)
    {
        for(pointer = temp->next ; pointer != NULL ; pointer = pointer->next)
        {
            if((pointer->value)<(temp->value))
            {
                valuePermuted = pointer->value;
                pointer->value = temp->value;
                temp->value = valuePermuted;
            }
        }    
    }
    return list;
}
