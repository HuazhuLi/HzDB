#ifndef _HZ_DB_H
#define _HZ_DB_H 

typedef struct 
{
	char	NAME_OF_DB[32]
	char	
	BTREE	*btree
	TABLE	*table
}DB;

typedef int STATUS;

DB 		*openDB(const char *);
STATUS	closeDB(DB 	*db)
STATUS  getDB
STATUS	storeDB
STATUS	deleteDB
	
#endif