/*************************************************************************
	> File Name: ../source/test_main.c
	> Author: dpica
	> Mail: dpicadev@163.com
	> Created Time: Tue 28 Feb 2017 04:27:43 AM PST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include "../include/List.h"

int  main()
{
   printf("%s"," good , start learn c struct \n");
   SqList sqlist;
   init_list(&sqlist);
   char a[]="abcdef";
   int i=0;
   //insert  data  to sqlist'elem
   for(;i<strlen(a);i++)
   {   

   ListInsert(&sqlist,i,a[i]);
   }
   int len= ListLength(&sqlist);
   printf("sqlist length is = %d\n",len);
   char temp;
   GetElem(sqlist,5,&temp);
   printf("our data from  sqlist ,i value =%c\n",temp);
   char temp1;
   PriorElem(sqlist,'b',&temp1);
   printf("prior elem =%c\n",temp1);
   NextElem(sqlist,'b',&temp1);
   printf("next  elem=%c\n",temp1);
   int  empty=ListEmpty(&sqlist);
   printf("empty is  0, %d\n",empty);
   destory_list(&sqlist);

    return 0;
}
