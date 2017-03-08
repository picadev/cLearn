/*************************************************************************
  > File Name: ../source/List.c
  > Author: dpica
  > Mail: dpicadev@163.com
  > Created Time: Tue 28 Feb 2017 04:19:32 AM PST
 ************************************************************************/

#include <stdio.h>
#include "../include/List.h"
#include <stdlib.h>
#include  <string.h>
int init_list(SqList * L)
{ 
    L->elem = (char *) malloc (LIST_LIMIT_SIZE*sizeof(char));
    if(!L->elem)
    {
	exit(-1);
    }
    L->length=0;
    L->listsize=LIST_LIMIT_SIZE;

    printf("%s"," SqList  init success  \n");
    return 0;
}
int  destory_list(SqList *L)
{
     free(L);
};
int  ClearList(SqList *L)
{

};
int  ListEmpty(SqList *L)
{

};
int  ListLength(SqList *L)
{   
    return  L->length;
};
int  GetElem(SqList L,int i,char *e)
{    int j=0;

      for(;j<L.length;j++)
      {    
           if(j==i)
	   {
	   //printf("%c\n",L.elem[i]);
	    *e=L.elem[i];
	    // strcpy(&e,hell
	    // .elem[i]);
	     break;
	   }
      }
      return 0;
};
int  PriorElem(SqList L,char cur_e,char *pri_e)
{   int i=1;
    for(i=1;i<=L.length;i++)
    {
      if(L.elem[i-1]==cur_e){
         char *e=&L.elem[i-1];
	* pri_e=e[i-2];
	 break;
      
      }
    
    }
     return 0;
         
};
int  NextElem(SqList L,char cur_e,char *nex_e)
{    
     int i=0;
    for(i=0;i<L.length;i++)
    {
      if(L.elem[i]==cur_e){
         char *e=&L.elem[i];
	* nex_e=e[i+1];
	 break;
      
      }
    
    }
     return 0;
       
};
int  ListInsert(SqList * L,int i,char e)
{   
    char * q;
    char * p;
    char  *newbase;
    if(i<1||i>L->length+1)
    {
	return -1;
    }
    if(L->length>L->listsize)
    { 
	newbase=(char *) realloc(L->elem,(L->listsize+LIST_INCREMENT)*sizeof(char ));
	if(!newbase)
	{
	    exit(-1);
	}
	L->elem = newbase;
	L->listsize+=LIST_INCREMENT;

    }
    q = &(L->elem[i+1]);
    for(p=&(L->elem[L->length-1]); p>=q;p--)
	*(p+1) = * q;                      /* main */
     *q = e;
    ++L->length;
   //printf("insert char type data success \n");
    return 0;


};
int  ListDelete(SqList *L,int i,char e)
{

};
//int  ListTraverse(*L,visit())
//{
//};
visit()
{

    printf("%s"," my is test function ,named visit()");

};

