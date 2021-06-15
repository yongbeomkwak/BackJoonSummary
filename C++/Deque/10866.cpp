#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct _Node
{

    int data;
    struct _Node *next; //구조체 자기자신을 가르킴
    struct _Node *prev; //구조체 자기자신을 가르킴

} Node, *Pnode;
//name convention을 맞춰주면 좋습니다.
//보통 struct는 대문자, 변수들은 소문자, 함수도 소문자로 합니다.
//꼭 이 convention을 맞출 필요는 없지만 본인만의 naming convention을 지키면 좋습니다.
typedef struct _Deque
{
    Pnode front;
    Pnode back;
    int size;

} Deque, *Pdeque;

//name convention을 맞춰주면 좋습니다.
//보통 struct는 대문자, 변수들은 소문자, 함수도 소문자로 합니다.
//꼭 이 convention을 맞출 필요는 없지만 본인만의 naming convention을 지키면 좋습니다.
Pdeque createDeque()
{
    return (Pdeque)calloc(1, sizeof(Deque));
    //안에 원소들이 전부 0이면 calloc을 호출하는 편이 좋습니다.
    //OS가 메모리블록을 전부 0으로 초기화할 수 있어서 malloc호출 후 0으로 대입하는 것보다
    //빠르거나 동일한 속도(0으로 초기화된 메모리가 없는 경우)가 나옵니다.
}
void push_front(Pdeque deque, int newInt)
{
    Pnode newNode = (Pnode)malloc(sizeof(Node)); //C언어에서는 형변환 명시 안해주셔도 됩니다.
    newNode->data = newInt;
    if (deque->size == 0) // Stack부분에서 여기가 많이 바뀜
    {
        newNode->next = newNode; // 자신의 다음 자기 자신
        newNode->prev = newNode; // 자신의 이전 자기 자신
        deque->front = newNode;  // 덱의 가장 앞 자기 자신
        deque->back = newNode;   // 덱의 가장 뒤 자기 자신
    }
    else
    {
        newNode->prev = deque->front;
        deque->front->next = newNode;
        deque->front = newNode;
    }
    deque->size++;
    //이렇게 쓴다면 케이스를 나누지 않고 구현 가능합니다.
}

void push_back(Pdeque deque, int newInt)
{
    Pnode newNode = (Pnode)malloc(sizeof(Node)); //C언어에서는 형변환 명시 안해주셔도 됩니다.
    newNode->data = newInt;
    if (deque->size == 0) // Stack부분에서 여기가 많이 바뀜
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        deque->front = newNode;
        deque->back = newNode;
    }
    else
    {
        newNode->next = deque->back;
        deque->back->prev = newNode;
        deque->back = newNode;
    }
    deque->size++;
    //이렇게 쓴다면 케이스를 나누지 않고 구현 가능합니다.
}

int pop_front(Pdeque deque)
{
    if (deque->size == 0)
        return -1;
    int data;
    Pnode tempNode;
    data = deque->front->data;
    tempNode = deque->front;
    deque->front = deque->front->prev;
    deque->size--;
    free(tempNode); //free 안해주시면 메모리 누수가 발생합니다.
    return data;
}
int pop_back(Pdeque deque)
{
    if (deque->size == 0)
        return -1;
    int data;
    Pnode tempNode;
    data = deque->back->data;
    tempNode = deque->back;
    deque->back = deque->back->next;
    deque->size--;
    free(tempNode); //free 안해주시면 메모리 누수가 발생합니다.
    return data;
}
int empty(Pdeque deque)
{
    return deque->size == 0 ? 1 : 0;
}
int front(Pdeque deque)
{
    return deque->size == 0 ? -1 : deque->front->data;
}
int back(Pdeque deque)
{
    return deque->size == 0 ? -1 : deque->back->data;
}
int size(Pdeque deque)
{
    return deque->size;
}
int main()
{
    int T;
    int input;
    char str[20];
    Pdeque dq = createDeque();
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {

        scanf("%s", str);
        if (!strcmp(str, "push_back"))
        {
            scanf("%d", &input);
            push_back(dq, input);
        }
        else if (!strcmp(str, "push_front"))
        {
            scanf("%d", &input);
            push_front(dq, input);
        }
        else if (!strcmp(str, "pop_back"))
        {
            printf("%d\n", pop_back(dq));
        }
        else if (!strcmp(str, "pop_front"))
        {
            printf("%d\n", pop_front(dq));
        }
        else if (!strcmp(str, "size"))
        {
            printf("%d\n", size(dq));
        }
        else if (!strcmp(str, "empty"))
        {
            printf("%d\n", empty(dq));
        }
        else if (!strcmp(str, "front"))
        {
            printf("%d\n", front(dq));
        }
        else if (!strcmp(str, "back"))
        {
            printf("%d\n", back(dq));
        }
    }
}