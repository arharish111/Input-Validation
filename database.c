#include <stdio.h>
#include "sqlite3.h"

#include "database.h"

int checkForDatabaseConnectionAndCreateTable()
{
	sqlite3 *db;
	int result;
	char *errorMessage;

   result = sqlite3_open("phone.db", &db);

   if(result) 
   {
		fprintf(stderr,"Can't open database: %s\n", sqlite3_errmsg(db));
		return 0;
   } 
   else 
   {
		//printf("Opened database successfully\n");

		char *sql = "CREATE TABLE IF NOT EXISTS COMPANY(NUMBER TEXT PRIMARY KEY,NAME TEXT NOT NULL)";
	  //"NUMBER TEXT PRIMARY KEY     NOT NULL," \"NAME           TEXT    NOT NULL
		
	  result = sqlite3_exec(db, sql, callback, 0, &errorMessage);
	   
	   if(result!=SQLITE_OK)
	   {
		  fprintf(stderr,"SQL error: %s\n", errorMessage);
		  sqlite3_free(errorMessage);
		  sqlite3_close(db);
		  return 0;
	   } 
	   else 
	   {
		  //printf("Table created successfully\n");
	   }
   }
   sqlite3_close(db);
   return 1;
}

int insertIntoDatabase(char *name,char *number)
{
	//printf("%s,%s\n",name,number);
	sqlite3 *db;
	int result;
	sqlite3_stmt *preparedStatement;

   result = sqlite3_open("phone.db", &db);

   if(result != SQLITE_OK) 
   {
		fprintf(stderr,"Can't open database: %s\n", sqlite3_errmsg(db));
		return 0;
   } 
   else 
   {
	  //printf("Opened database successfully\n");

	  char *sql = "INSERT INTO COMPANY VALUES(?,?)";
		
	  result = sqlite3_prepare_v2(db,sql,-1,&preparedStatement,0);
	   
	   if(result != SQLITE_OK)
	   {
		  fprintf(stderr,"SQL error: %s\n", sqlite3_errmsg(db));
		  sqlite3_close(db);
		  return 0;
	   } 
	   else 
	   {
		  //printf("size1:%d\n",sizeof(number));
		  result = sqlite3_bind_text(preparedStatement,1,number,-1,NULL);
		  if(result != SQLITE_OK)
		  {
			fprintf(stderr,"SQL error: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);
			return 0;
		  }
		  //printf("size2:%d\n",sizeof(name));
		  result = sqlite3_bind_text(preparedStatement,2,name,-1,NULL);
		  if(result != SQLITE_OK)
		  {
			fprintf(stderr,"SQL error: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);
			return 0;
		  }
		  else
		  {
			result = sqlite3_step(preparedStatement);
			if(result == SQLITE_ERROR)
			{
				fprintf(stderr,"SQL error: %s\n", sqlite3_errmsg(db));
				sqlite3_close(db);
				return 0;
			}
		  }
	   }
   }
   sqlite3_close(db);
   sqlite3_finalize(preparedStatement);
   return 1;
}

int deleteEntryByName(char *name)
{
	sqlite3 *db;
	int result;
	sqlite3_stmt *preparedStatement;

   result = sqlite3_open("phone.db", &db);

   if(result != SQLITE_OK) 
   {
		fprintf(stderr,"SQL error: %s\n", sqlite3_errmsg(db));
		return 0;
   } 
   else 
   {
	  //printf("Opened database successfully\n");

	  char *sql = "DELETE FROM COMPANY WHERE NAME =?";
		
	  result = sqlite3_prepare_v2(db,sql,-1,&preparedStatement,0);
	   
	   if(result != SQLITE_OK)
	   {
		  fprintf(stderr,"SQL error: %s\n", sqlite3_errmsg(db));
		  sqlite3_close(db);
		  return 0;
	   } 
	   else 
	   {
		  result = sqlite3_bind_text(preparedStatement,1,name,-1,NULL);
		  if(result!=SQLITE_OK)
		  {
			fprintf(stderr,"SQL error: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);
			return 0;
		  }
		  else
		  {
			result = sqlite3_step(preparedStatement);
			//printf("%d-%d-%d-%d-%d-%d",result,SQLITE_ERROR,SQLITE_OK,SQLITE_DONE,SQLITE_ROW,sqlite3_changes(db));
			if(sqlite3_changes(db)==0)
			{
				fprintf(stderr,"%s\n","Data does not exist to delete");
				sqlite3_close(db);
				return 0;
			}
			if(result==SQLITE_ERROR)
			{
				fprintf(stderr,"SQL error: %s\n", sqlite3_errmsg(db));
				sqlite3_close(db);
				return 0;
			}
		  }
	   }
   }
   sqlite3_close(db);
   sqlite3_finalize(preparedStatement);
   return 1;
	
}

int deleteEntryByNumber(char *number)
{
	sqlite3 *db;
	int result;
	sqlite3_stmt *preparedStatement;

   result = sqlite3_open("phone.db", &db);

   if(result != SQLITE_OK) 
   {
		fprintf(stderr,"SQL error: %s\n", sqlite3_errmsg(db));
		return 0;
   } 
   else 
   {
	  //printf("Opened database successfully\n");

	  char *sql = "DELETE FROM COMPANY WHERE NUMBER =?";
		
	  result = sqlite3_prepare_v2(db,sql,-1,&preparedStatement,0);
	   
	   if(result != SQLITE_OK)
	   {
		  printf("SQL error: %s\n", sqlite3_errmsg(db));
		  sqlite3_close(db);
		  return 0;
	   } 
	   else 
	   {
		  result = sqlite3_bind_text(preparedStatement,1,number,-1,NULL);
		  if(result!=SQLITE_OK)
		  {
			fprintf(stderr,"SQL error: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);
			return 0;
		  }
		  else
		  {
			result = sqlite3_step(preparedStatement);
			if(sqlite3_changes(db)==0)
			{
				fprintf(stderr,"%s\n","Data does not exist to delete");
				sqlite3_close(db);
				return 0;
			}
			if(result==SQLITE_ERROR)
			{
				fprintf(stderr,"SQL error: %s\n", sqlite3_errmsg(db));
				sqlite3_close(db);
				return 0;
			}
		  }
	   }
   }
   sqlite3_close(db);
   sqlite3_finalize(preparedStatement);
   return 1;
}
int displayList()
{
	sqlite3 *db;
	int result;
	char *errorMessage;

   result = sqlite3_open("phone.db", &db);

   if(result != SQLITE_OK) 
   {
		fprintf(stderr,"SQL error: %s\n", sqlite3_errmsg(db));
		return 0;
   } 
   else 
   {
	  //printf("Opened database successfully\n");

	  char *sql = "SELECT * FROM COMPANY";
		
	  result = sqlite3_exec(db, sql, callback, 0, &errorMessage);
	   
	   if(result!=SQLITE_OK)
	   {
		  fprintf(stderr,"SQL error: %s\n", errorMessage);
		  sqlite3_free(errorMessage);
		  sqlite3_close(db);
		  return 0;
	   } 
   }
   sqlite3_close(db);
   return 1;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName) 
{
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}