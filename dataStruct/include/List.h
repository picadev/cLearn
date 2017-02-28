/*************************************************************************
	> File Name: List.h
	> Author: dpica
	> Mail: dpicadev@163.com
	> Created Time: Tue 28 Feb 2017 04:09:32 AM PST
 ************************************************************************/

#ifndef _LIST_H
#define _LIST_H
#define  LIST_LIMIT_SIZE 100  
#define  LIST_INCREMENT  10  
typedef  struct{
  char  * elem;
  int length;
  int listsize;
 
}SqList;
int  init_list(SqList *L);
int  destory_list(SqList *L);
int  ClearList(SqList *L);
int  ListEmpty(SqList *L);
int  ListLength(SqList *L);
int  GetElem(SqList L,int i,char *e);
int  PriorElem(SqList L,char cur_e,char *pri_e);
int  NextElem(SqList L,char cur_e,char *nex_e);
int  ListInsert(SqList *L,int i, char * e);
int  ListDelete(SqList *L,int i,char e);
//int  ListTraverse(SqList *L,visit());
visit();
#endif
