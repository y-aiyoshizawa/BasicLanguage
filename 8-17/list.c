#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _cell {
    char key[100];       //本来ならば動的に領域確認すべき
    int  value;
    struct _cell *next;
};

static struct _cell *top;

void InitList()
{

    top = NULL;
}

void TermList()
{
    struct _cell *cell;
    struct _cell *next;

    for (cell = top; cell != NULL; cell = next) {
        next = cell->next;
        free(cell);
    }

    top = NULL;
}

void addList(char *key, int value)
{
    struct _cell *cell;

    cell = (struct _cell *)malloc(sizeof(struct _cell));

	strcpy(cell->key, key);
    cell->value = value;
    cell->next  = top;

    top = cell;
}

int getList(char *key, int *value)
{
    struct _cell *cell;

    for (cell = top; cell != NULL; cell = cell->next) {
        if(strcmp(cell->key, key) == 0) {
            *value = cell->value;
            return 1;
        }
    }

    return 0;
}

void delList(char *key)      // 演習問題
{
    struct _cell *cell;
    struct _cell *before_cell;

    for (cell = top; cell != NULL; cell = cell->next) {
        if(strcmp(cell->key, key) == 0) {
            if(top == before_cell){
                top = cell->next;
            }else{
                before_cell->next = cell->next;
            }
            free(cell);
            return;
        }
        before_cell = cell;
    }

    return;
}

void PrintAllList()          // 演習問題
{
    struct _cell *cell;

    printf("---List Start---");
    for (cell = top; cell != NULL; cell = cell->next) {
        printf("key=%s,value=%d",cell->key,cell->value);
    }
    printf("---List End---");
}

void main()
{
    char *key;
    int   value;
    char  buff[100];

    InitList();

    for(;;) {
    	printf("> ");
        fgets(buff, sizeof(buff),stdin);
        buff[strlen(buff)-1] = '\0';
        if (buff[0] == 'E' || buff[0] == 'e')
            break;

        switch(buff[0]) {
        case '?' :
            printf ("-- List/Command list --\n");
            printf ("A key, valuse → AddList(key, value)\n");
            printf ("G key → getList(key)\n");
            printf ("D key → delList(key)\n");
            printf ("E → End、* → PrintAllStack、T → Test\n\n");
            break;
        case '*' :
            PrintAllList();
            break;
        case 'T' :
        case 't' :
            addList("a11", 11); printf("addList/a11, 11\n");
            addList("b12", 12); printf("addList/b12, 12\n");
            addList("c13", 13); printf("addList/c13, 13\n");
            PrintAllList();
            getList("a11", &value); printf("getList(a11)/%d\n",value);
            getList("b12", &value); printf("getList(b12)/%d\n",value);
            delList("b12"); printf("delList(b12)\n");
            PrintAllList();
            break;
        case 'A' :
        case 'a' :
            key   = strtok(&buff[1], ",");
            value = atoi(strtok(NULL,","));
            addList(key, value);
            printf("addList : %s, %d\n", key, value);
            break;
        case 'G' :
        case 'g' :
            if( getList(&buff[1], &value) ) {
                printf("getList : %s, %d\n", &buff[1], value);
            } else {
                printf("getList : %s -> not found\n", &buff[1]);
            }
            break;
        case 'D' :
        case 'd' :
            delList(&buff[1]);
            printf("delList : %s\n", &buff[1]);
            break;
        }
    }

    TermList();
}

