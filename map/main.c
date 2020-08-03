#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
typedef struct pair
{
        void *key; // maps to a value
        void *value;
        struct pair *next;
} Pair;

typedef struct map
{
        int size;
        Pair **list; // points to  array pair<key,value>
} Map;

Pair pair(char *key, int value)
{
        Pair p;
        p.key = (char *)key; // memory leaks
        p.value = &value;
        return p;
}

// returns the index of where the pair  is to be stored
int hashCode(Map *m, const char *key)
{
        int idx = atoi(key);
        if (idx < 0)
        {
                return -(idx); // turn it to positive
        }
        return atoi(key) % m->size;
}

// createMap return the address to a map
Map *createMap(int sz)
{
        Map *m = (Map *)malloc(sizeof(Map));
        m->size = sz;
        m->list = (Pair **)malloc(sz * sizeof(Map));
        // initialize every element to null
        int i;
        for (i = 0; i < sz; i++)
        {
                m->list[i] = NULL;
        }
        return m;
}

// search function

Pair search(Map *m, Pair *value)
{
        int idx = hashCode(m, value->key);
        Pair ret; // return  value ? Risky
        Pair *list = m->list[idx];
        Pair *temp = list; // make a copy for lookup
        while (temp)
        {
                if (temp->key == value->key)
                {
                        ret = *temp; // copy of the pair
                        break;
                }
                temp = temp->next; // else move forward
        }
        return ret;
}
// insert function
void insert(Map *m, Pair item)
{
        int position = hashCode(m, item.key);
        // create a bucket
        Pair *list = m->list[position];
        Pair *node = (Pair *)malloc(sizeof(Pair));
        Pair *temp = list;
        while (temp)
        {
                if (temp->key == item.key)
                {
                        temp->value = item.value;
                        return;
                }
                temp = temp->next;
        }
        node->key = item.key;
        node->value = item.value;
        node->next = list;
        m->list[position] = node;
}

// map clean up
void destroyMap(Map *m)
{
        free(m);
}
// print function

int main(int argc, char const *argv[])
{
        Map* mp = createMap(5);
        insert(mp,pair("g",56));
        insert(mp,pair("a",6));
        insert(mp,pair("b",26));
        Pair l = pair("b",26);
        printf("%d",(int)search(mp,&l).value);
        return 0;
}
