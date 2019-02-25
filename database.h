#ifndef database_h
#define database_h

int checkForDatabaseConnectionAndCreateTable();
static int callback(void *NotUsed, int argc, char **argv, char **azColName);

#endif 