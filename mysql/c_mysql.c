#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mysql.h"
#include "errmsg.h"
#include "mysqld_error.h"

MYSQL conn;
MYSQL_RES *res_ptr;
MYSQL_ROW sqlrow;

void connection (const char* host,const char* user,const char* password,const char* database){

  mysql_init(&conn);

  if(mysql_real_connect(&conn,host,user,password,database,0,NULL,0)){
    printf("connection success!\n");
  }else{
    fprintf(stderr,"connection fail");
    if(mysql_error(&conn)){
      fprintf(stderr,"connection error %d:%s",mysql_errno(&conn),mysql_error(&conn));
    }
    exit(EXIT_FAILURE);
  }
  


}

void display_row(){

  unsigned int  field_count=mysql_field_count(&conn);
  int i=0;
  while(i<field_count){
    if(sqlrow[i]){
      printf("%s",sqlrow[i]);

    }else printf("NULL");
    i++; 
  }
  printf("\n");
}

void display_header(){
  MYSQL_FIELD *field_ptr;
  printf("column details:\n");
   while ((field_ptr = mysql_fetch_field(res_ptr)) != NULL) {
    printf("\t Name:%s\n",field_ptr->name);
    printf("\t Table:%s\n",field_ptr->table);
    printf("\t Type:");
    if(IS_NUM(field_ptr->type)){
      printf("Numeric  field\n");
    }else {
      switch(field_ptr->type){
      case FIELD_TYPE_VAR_STRING:
      printf("VARCHAR\n");
      break;
      case FIELD_TYPE_LONG:
      printf("LONG");
      break;
      default:
	
	printf("Type is %d,check in mysql_com.h\n",field_ptr->type);
      }

    }
    printf("\t Max width %ld\n",field_ptr->length);
    if(field_ptr->flags & AUTO_INCREMENT_FLAG){
      printf("\t AUTO increments\n");
    }
  }

}



int main(int argc,char *argv[]){
  connection("localhost","root","","aqjc");

  int res=mysql_query(&conn,"select * from sys_dept");
  if(res){
    fprintf(stderr,"select err:%s\n",mysql_error(&conn));
  }else{
       
    res_ptr=mysql_use_result(&conn);
    if(res_ptr){
      int first=1;
      while((sqlrow=mysql_fetch_row(res_ptr))){
	if(first){
	  display_header();
          first=0;  
	}
	display_row();

      }

      if(mysql_errno(&conn)){
        fprintf(stderr,"retrive error:%s\n",mysql_error(&conn));
      }
      mysql_free_result(res_ptr);

    }
  }

  mysql_close(&conn);
  exit(EXIT_SUCCESS);

}
