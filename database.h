#ifndef database_h
#define database_h

int checkForDatabaseConnectionAndCreateTable();
static int callback(void *NotUsed, int argc, char **argv, char **azColName);
int insertIntoDatabase(char *name,char *number);
int deleteEntryByName(char *name);
int deleteEntryByNumber(char *name);
int displayList();

#endif 