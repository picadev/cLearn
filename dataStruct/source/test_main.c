/*************************************************************************
	> File Name: ../source/test_main.c
	> Author: dpica
	> Mail: dpicadev@163.com
	> Created Time: Tue 28 Feb 2017 04:27:43 AM PST
 ************************************************************************/

#include<stdio.h>
#include "../include/List.h"

int  main()
{
   printf("%s"," good , start learn c struct \n");
   SqList sqlist;
   init_list(&sqlist);
   char a='k';
   ListInsert(&sqlist,1,a);
    return 0;
}
