#include <stdio.h>
#include "sqlite3.h"

#include "database.h"

int checkForDatabaseConnectionAndCreateTable()
{
	sqlite3 *db;
	int result;
	char *errorMessage;

   result = sqlite3_open("phone.db", &db);

   if( result ) 
   {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return 0;
   } 
   else 
   {
		fprintf(stderr, "Opened database successfully\n");
   
    	char *sql = "CREATE TABLE IF NOT EXISTS COMPANY("  \
      "NUMBER TEXT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL);";
		
		result = sqlite3_exec(db, sql, callback, 0, &errorMessage);
	   
	   if( result != SQLITE_OK )
	   {
		  fprintf(stderr, "SQL error: %s\n", errorMessage);
		  sqlite3_free(errorMessage);
		  return 0;
	   } 
	   else 
	   {
		  fprintf(stdout, "Table created successfully\n");
	   }
	   sqlite3_close(db);
	   return 1;
   }
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