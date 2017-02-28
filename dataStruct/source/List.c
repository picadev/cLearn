/*************************************************************************
  > File Name: ../source/List.c
  > Author: dpica
  > Mail: dpicadev@163.com
  > Created Time: Tue 28 Feb 2017 04:19:32 AM PST
 ************************************************************************/

#include<stdio.h>
#include "../include/List.h"
#include <stdlib.h>
int init_list(SqList * L)
{ 
    L->elem = (SqList *) malloc (LIST_LIMIT_SIZE*sizeof(char));
    if(!L->elem)
    {
	exit(-1);
    }
    L->length=0;
    L->listsize=LIST_LIMIT_SIZE;

    printf("%s"," SqList  init success \n");
    return 0;
}
int  destory_list(SqList *L)
{

};
int  ClearList(SqList *L)
{

};
int  ListEmpty(SqList *L)
{

};
int  ListLength(SqList *L)
{

};
int  GetElem(SqList L,int i,char *e)
{

};
int  PriorElem(SqList L,char cur_e,char *pri_e)
{

};
int  NextElem(SqList L,char cur_e,char *nex_e)
{

};
int  ListInsert(SqList * L,int i,char *e)
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
	newbase=(char *) realloc(L->elem,(L->listsize+LIST_INCREMENT)*sizeof(char));
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
    * q = e;
    ++L->length;
    printf("insert char type data success  e \n");
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

