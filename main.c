#include "HzDB.h"
#include <fcntl.h>
#include <stdarg.h>
#include <sys/uio.h>
#include <unisrd.h>


#define IDXLEN_SZ	4
#define SEP			":"
#define SPACE		" "
#define NEWLINE		"\n"

#define PTR_SZ	7
#define PTR_MAX	999999
#define NHASH_DEF 137
#define FREE_OFF 0
#define HASH_OFF PTR_SZ

typedef unsigned long DBHASH;
typedef unsigned long COUNT;

typedef struct DB
{
	int idxfd;
	int datfd;
	char *idxbuf;
	char *datbuf;
	char *name;
	off_t idxoff;
    size_t idxlen;
    off_t datoff;
    size_t datlen;

    off_t ptrval;
    off_t ptroff;
    off_t chainoff;
    off_t hashoff;

    DBHASH nhash;
    COUNT cnt_delok;
    COUNT cnt_delerr;
    COUNT cnt_fetchok;
    COUNT cnt_fetcherr;
    COUNT cnt_nextrec;
    COUNT cnt_stor1;
    COUNT cnt_stor2;
    COUNT cnt_stor3;
    COUNT cnt_stor4;
    COUNT cnt_storerr;
};

/*internal functions*/
static DB *_db_alloc(int);
static void _db_dodelete(DB *);
static int _db_find_and_lock(DB *,const char *, int);
static int _db_findfree(DB*, int, int);
static void _db_free(DB *);
static DBHASH _db_hash(DB *, const char*);
static char *_db_readdat(DB *);
static off_t	*_db_readidx(DB *);
static off_t *_db_readptr(DB *, off_t);
static void _db_writedat(DB *, const char *, off_t, int);
static void _db_writeidx(DB *, const char *, off_t, int, off_t);
static void _db_writeptr(DB *, off_t, off_t);

DBHANDLE
db_open(const char *pathname, int oflag, ...)/*什么时候改用指针什么时候不用？如何沿用另外一种更加直观的命名方法？*/
{
	DB  *db;
	int len, mode;
	size_t i;
	char  asciiptr[PTR_SZ + 1];
		  hash[(NHASH_DEF + 1) * PTR_SZ + 2];//偏移地址除了改变映射指向以外还有其他作用吗？

	struct stat statbuff;//结构为什么有时候有有时候没有？c中的关键字不熟悉导致了更多的问题

	len = strlen(pathname);
	if ((db = _db_alloc(len)) == NULL)//表达式等于null，什么意思？
	{
		err_dump("db_open: _db_alloc error for DB");
	}
}
