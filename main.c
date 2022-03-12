#include <stdio.h>
#include<stdlib.h>
#include "lib.h"
#include<string.h>

int main (void)
{

   DoubleList list = new_double_list();
   list=addDouble(3.25,list);
   list=addDouble(1.023,list);
   list=addDouble(403.025,list);
   list=addDouble(1.0230001,list);
    list=sortDoubleList(list);
   printDoubleList(list);




   free(list);
    // StringList list = new_string_list();
    // list = addString("ismail",list);
    // list = addString("bouaddi",list);
    // list = addString("ototage",list);
    // list = addStringFront("Koora",list);

    // printf("la taille de la liste est %d \n",sizeStringList(list));
    // printStringList(list);
    // printf("l'index du koora is %d\n",getStringIndex(list,"Koora"));
    // printf("l'index du ismail is %d\n",getStringIndex(list,"ismail"));
    // printf("l'index du bouaddi is %d\n",getStringIndex(list,"bouaddi"));
    // printf("l'index du ototage is %d\n",getStringIndex(list,"ototage"));

    // printf("la chaine dans l'index 0 est %s \n",getStringAtIndex(list,0));
    // printf("la chaine dans l'index 1 est %s \n",getStringAtIndex(list,1));
    // printf("la chaine dans l'index 2 est %s \n",getStringAtIndex(list,2));
    // printf("la chaine dans l'index 3 est %s \n",getStringAtIndex(list,3));
    // printf("la chaine dans l'index 29 est %s \n",getStringAtIndex(list,29));
    //list=popStringFront(list);
    //printStringList(list);
    //list=clearStringList(list);
    //printStringList(list);
    // IntList list = new_int_list();
    // list =addInt(21,list);
    // list =addInt(21,list);
    // list = addIntFront(1245,list);
    // list = addIntFront(0,list);
    // list = addIntFront(-3,list);
    // list =addInt(600,list);
    
    // printIntList(list);  // [-3,0,1245,21,21,600]

    // list=sortIntList(list);

    // printf("La liste apres le trie \n");
    // printIntList(list);
    
    // printf("index of -3 is %d\n",getIntIndex(list,-3));          // 0
    // printf("index of 0 is %d\n",getIntIndex(list,0));           // 1 
    // printf("index of 1245 is %d\n",getIntIndex(list,1245));     // 2   
    // printf("index of 21 is %d\n",getIntIndex(list,21));        // 3
    // printf("index of 21 is %d\n",getIntIndex(list,21));        // 3
    // printf("index of 600 is %d\n",getIntIndex(list,600));       // 5
    // printf("index of 2145 is %d\n",getIntIndex(list,2145));       // -1

    // printf("the size of the list is %d \n",sizeIntList(list));



    // printf("the integer at index 0 is %d\n",getIntAtIndex(list,0));
    // printf("the integer at index 1 is %d\n",getIntAtIndex(list,1));
    // printf("the integer at index 2 is %d\n",getIntAtIndex(list,2));
    // printf("the integer at index 3 is %d\n",getIntAtIndex(list,3));
    // printf("the integer at index 4 is %d\n",getIntAtIndex(list,4));
    // printf("the integer at index 5 is %d\n",getIntAtIndex(list,5));

    

    //free(list);
}