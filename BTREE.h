#ifndef _BTREE_H_
#define _BTREE_H_

#define	m 1024
struct BTREE_NODE;
typedef struct BTREE_NODE	*PTR_BTREE_NODE;
struct BTREE_NODE
{
	 int	amountOfKey;
	 PTR_BTREE_NODE		parent;
	 PTR_BTREE_NODE		*ptr;
	 KeyType	*key;

};

struct BTREE
{
	BTREE_NODE 	*root
};


#endif