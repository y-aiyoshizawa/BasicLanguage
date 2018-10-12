#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// --------------------------
// hash 探索 キー/int
// [チェイン法 chaining]
// --------------------------

#define    HASHSIZE    101

struct nlist {
    int   key;
    char  value[21];
    struct nlist *next;
} *hashtable[HASHSIZE];

struct nlist *AllocNlist(int key, char *value, struct nlist *nl)
{
    struct nlist *t;

    t = (struct nlist *)malloc(sizeof(struct nlist));
    t->key = key;
    strcpy(t->value, value);
    t->next = nl;

    return t;
}

void FreeNlist(struct nlist *p)
{
    if (p != NULL)
        free(p);
}

void TermHashTable()
{
    int i;
    struct nlist *t, *n;

    for (i = 0; i < HASHSIZE; ++i) {
        for (t = hashtable[i]; t != NULL; t = n) {
            n = t->next;
            FreeNlist(t);
        }
    }
}

void PrintHashTable()
{
    int i;
    struct nlist *t;

    for (i = 0; i < HASHSIZE; ++i) {
        if (hashtable[i] == NULL) continue;
        t = hashtable[i];
        printf("hash[%3d]  key = %4d, value = %s\n",i, t->key, t->value);
        for (t = t->next; t != NULL; t = t->next) {
            printf("           key = %4d, value = %s\n", t->key, t->value);
        }
    }
}

unsigned hash(int key)
{
    return key % HASHSIZE;
}


char* search(int key)
{
    unsigned h = hash(key);
    struct nlist *t;

    for (t= hashtable[h]; t != NULL; t = t->next) {
        if(t->key == key) {
            return t->value;
        }
    }

    return NULL;
}

void insert(int key, char* value)
{
    unsigned h = hash(key);

    if (search(key) == NULL) {
        hashtable[h] = AllocNlist(key, value, hashtable[h]);
    }
}

void delete(int key)
{
    unsigned h = hash(key);
    struct nlist *t;

    for (t= hashtable[h]; t != NULL; t = t->next) {
        if(t->key == key) {
            return t->value;
        }
    }

    return NULL;
}

void InitHashTable()
{
    int   i;
    int   key;
    char *value;
    char  buff[100];
    FILE *fp;

    for (i = 0; i < HASHSIZE; ++i) {
        hashtable[i] = NULL;
    }

    fp = fopen("hash_int.dat","r");

    for(;;) {
        if (fgets(buff, sizeof(buff), fp) == NULL) break;
        if(buff[0] == 'E' || buff[0] == 'e') break;
        if(buff[0] == '#') continue;
        buff[strlen(buff)-1] = '\0';

        key = atoi(&buff[0]);
        for (value = &buff[1]; *value != ','; ++value)
            ;
        ++value;
        insert(key, value);
    }

    fclose(fp);
}

int main()
{
    int   key;
    char *value;
    char  buff[100];

    InitHashTable();

    for (;;) {
        printf("> ");
        fgets(buff, sizeof(buff), stdin);
        buff[strlen(buff)-1] = '\0';
        if (buff[0] == 'E' || buff[0] == 'e') break;

        switch(buff[0]) {
        case '?':
            printf("-- Hash/int chaining --\n");
            printf ("I key, valuse → insert(key, value)\n");
            printf ("S key → search(key)\n");
            printf ("D key → delete(key)\n");
            printf ("E → End、* → PrintHashTable\n\n");
            break;
        case '*':
            PrintHashTable();
            break;
        case 'I':
        case 'i':
            key = atoi(&buff[1]);
            for (value = &buff[2]; *value != ','; ++value)
                ;
            ++value;
            insert(key, value);
            break;
        case 'D':
        case 'd':
            key = atoi(&buff[1]);
            delete(key);
            break;
        case 'S':
        case 's':
            key = atoi(&buff[1]);
            value = search(key);
            if (value != NULL) {
                printf("search : key = %d value = %s\n", key, value);
            } else {
                printf("search Error : key = %d\n", key);
            }
            break;
        }
    }

    TermHashTable();

    return 0;
}

