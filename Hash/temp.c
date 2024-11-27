#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*键值对 */
typedef struct Pair
{
    int key;        //键
    char *value;    //值
}Pair;

/*链表节点 */
typedef struct Node
{
    Pair  *pair;         //键值对指针
    struct Node* next;  //链表节点指针
}Node;

/*链式地址哈希表*/
typedef struct 
{
    int size;           //键值对数量
    int capacity;       //哈希表容量
    double loadThres;   //触发扩容的负载因子阈值
    int extendRatio;    //扩容倍数
    Node **buckets;     //桶数组
    
}LinkHashMap;

LinkHashMap* newHashMapLink();
void deleteLinkHashMap(LinkHashMap* hashMap);
int hashFuc(LinkHashMap* hashMap, int key);
double loadFactor(LinkHashMap* hashMap);
char* getValue(LinkHashMap* hashMap, int key);
void put(LinkHashMap* hashMap, int key, const char* value);
void removeItem(LinkHashMap* hashMap);
void extend(LinkHashMap* hashMap);
Pair* pairSet(LinkHashMap* hashMap);
int* keySet(LinkHashMap* hashMap);
char** valueSet(LinkHashMap *hashMap);
void printHash(LinkHashMap* hasMap);

int main()
{
    LinkHashMap* hashMap = newHashMapLink();
    put(hashMap, 2, "hello");
    put(hashMap, 4, "world");
    put(hashMap, 8, "mortality");
    put(hashMap, 12, "rob");
    printHash(hashMap);
    printf("4 ->value: %s\n", getValue(hashMap, 4));
    printf("capatity: %d\n ",hashMap->capacity);
    printf("size: %d\n ",hashMap->capacity);
    printf("ratio: %.3f\n ",hashMap->loadThres); 
    
    printf("Pair------------------\n");
    Pair* pair = pairSet(hashMap); 
   
    for (int i = 0; i < hashMap->size; i++)
    {
        printf("%d -> %s\n",pair[i].key, pair[i].value);
    }
   
    printf("\nkeySet------------------\n");
    int* key = keySet(hashMap);
    for (int i = 0; i < hashMap->size; i++)
    {
        printf("%d\n",pair[i].key);
    }
    printf("\nValueSet----------------\n\n");
    char** str = valueSet(hashMap);
    for (int i = 0; i < hashMap->size; i++)
    {
        printf("%s\n",pair[i].value);
    }
    deleteLinkHashMap(hashMap);
    
    system("pause");
    return 0;
}
/*构造函数*/
LinkHashMap* newHashMapLink()
{
    LinkHashMap* hashMap = (LinkHashMap*)malloc(sizeof(LinkHashMap));
 
    hashMap->size = 0;                      //键值对数量
    hashMap->capacity = 4;                  //哈希表容量
    hashMap->loadThres = 3.0 / 4.0;         //触发扩容的负载因子阈值3/4                             
    hashMap->extendRatio = 2;               //扩容倍数
    hashMap->buckets = (Node**)malloc(hashMap->capacity * sizeof(Node *));
    /*初始化所有桶 */
    for (int i = 0; i < hashMap->capacity; i++)
    {
        hashMap->buckets[i] = NULL;
    }
    return hashMap;
}
/*析构函数 */
void deleteLinkHashMap(LinkHashMap* hashMap)
{
    /*遍历所有桶 */
    for (int i = 0; i < hashMap->capacity; i++)
    {
        Node* cur = hashMap->buckets[i];
        /*遍历所有同一索引的键值对，并释放内存*/
        while (cur)
        {
            Node* temp = cur;
            cur = cur ->next;
            free(temp);             
        }
    }
    free(hashMap->buckets);
    free(hashMap);
}

/*哈希函数 */
int hashFuc(LinkHashMap* hashMap, int key)
{
    return key % hashMap->capacity;
}

/*负载因子 */
double loadFactor(LinkHashMap* hashMap)
{
    return (double)hashMap->size / (double)hashMap->capacity;
}

/*查询操作 ,根据键，返回值*/
char* getValue(LinkHashMap* hashMap, int key)
{
    int index = hashFuc(hashMap,key);
    Node* node = hashMap->buckets[index];
    while(node)
    {
        // 遍历桶，若找到 key ，则返回对应 value
        if(node->pair->key == key)
        {
            return node->pair->value;
        }
        node = node->next;
    }
    //没有找到key,返回空字符串
    return (char*)"";   
}

/* 扩容哈希表 */
void extend(LinkHashMap *hashMap)
{
    /*暂存原哈希表*/
    Node **oldBuckts = hashMap->buckets;
    int oldCapacity = hashMap->capacity;
    /*初始化扩容后的新哈希表*/
    hashMap->capacity *= hashMap->extendRatio;
    hashMap->buckets = (Node**)malloc(sizeof(Node*)*hashMap->capacity);
    for (int i = 0; i < hashMap->capacity; i++)
    {
        hashMap->buckets[i] = NULL;
    }
    hashMap->size = 0;
    // 将键值对从原哈希表搬运至新哈希表
    for (int i = 0; i < oldCapacity; i++)
    {
        Node* cur = hashMap->buckets[i];
        while (cur)
        {
            put(hashMap,cur->pair->key, cur->pair->value);
            cur = cur->next;
        }
    }
    free(oldBuckts);
}
/*添加操作 */
void put(LinkHashMap* hashMap, int key, const char* value)
{
    int index = hashFuc(hashMap, key);
    Node* cur = hashMap->buckets[index];
    Node* pre = NULL;
    /*当负载因子超过阈值时，执行扩容*/
    if (loadFactor(hashMap) > hashMap->loadThres)
    {
        extend(hashMap); 
    }
    /*遍历桶，若遇到指定 key ，则更新对应 value 并返回*/
    while (cur)
    {
        if(cur->pair->key == key)
        {
            cur->pair->value = (char *)malloc(strlen(value) + 1);
            strcpy(cur->pair->value,value);
            return;
        }
        pre = cur;
        cur = cur->next;
    }

    /*没有找到key，将键值对添加到链表头部*/
    Pair *newPair = (Pair *)malloc(sizeof(Pair));
    newPair->value = (char *)malloc(strlen(value) + 1);
    newPair->key = key;
    strcpy(newPair->value, value);
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->pair = newPair;
    newNode->next = hashMap->buckets[index];
    hashMap->buckets[index] = newNode;
    hashMap->size++;
}

/*获取所有键值对 */
Pair* pairSet(LinkHashMap* hashMap)
{
    Pair* result =(Pair*)malloc(sizeof(Pair) * hashMap->size);
    int index = 0;
    /*遍历所有桶 */
    for (int i = 0; i < hashMap->capacity; i++)
    {
        Node* cur = hashMap->buckets[i];
        /*遍历当前索引的链表*/
        while (cur)
        {
            result[index].key = cur->pair->key;
            result[index].value = (char*)malloc(sizeof(strlen(cur->pair->value)+1));
            strcpy(result[index].value, cur->pair->value);
            index++;
            cur = cur->next;
        }
    }
    return result;
}
/*打印哈希表 */
void printHash(LinkHashMap* hasMap)
{
    /*遍历桶数组，打印所有键值对 */
    for (int i = 0; i < hasMap->capacity; i++)
    {
        Node* cur = hasMap->buckets[i];
        if(!cur) continue;
        /*打印索引相同的所有键值对 */
        printf("[\n");
        while (cur)
        {
            printf("  %d -> %s\n",cur->pair->key,cur->pair->value);
            cur = cur->next;
        }
        printf("]\n");
    }
    
}
/*返回所有键 */
int* keySet(LinkHashMap* hashMap)
{
    int* result = (int*)malloc(sizeof(int) * hashMap->size);
    int index = 0;
    for (int i = 0; i < hashMap->capacity; i++)
    {
        Node* cur = hashMap->buckets[i];
        if(!cur) continue;
        while (cur)
        {
            result[index] = cur->pair->key;
            index++;
            cur = cur->next;
        }
    }
    return result;
}
/*返回所有值*/
char** valueSet(LinkHashMap *hashMap)
{
    char** result = (char**)malloc(sizeof(char*) * hashMap->size);
    int index = 0;
    for (int i = 0; i < hashMap->capacity; i++)
    {
        Node* cur = hashMap->buckets[i];
        if(!cur) continue;
        while (cur)
        {
            result[index] = cur->pair->value;
            index++;
            cur = cur->next;
        }
    }
    return result;
}
