#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct _Node
{

    int data;
    struct _Node *next; //구조체 자기자신을 가르킴
} Node, *Pnode;
//name convention을 맞춰주면 좋습니다.
//보통 struct는 대문자, 변수들은 소문자, 함수도 소문자로 합니다.
//꼭 이 convention을 맞출 필요는 없지만 본인만의 naming convention을 지키면 좋습니다.
typedef struct _Stack
{
    Pnode peak;
    int size;

} Stack, *Pstack;

//name convention을 맞춰주면 좋습니다.
//보통 struct는 대문자, 변수들은 소문자, 함수도 소문자로 합니다.
//꼭 이 convention을 맞출 필요는 없지만 본인만의 naming convention을 지키면 좋습니다.
Pstack createStack()
{
    return (Pstack)calloc(1, sizeof(Stack));
    //안에 원소들이 전부 0이면 calloc을 호출하는 편이 좋습니다.
    //OS가 메모리블록을 전부 0으로 초기화할 수 있어서 malloc호출 후 0으로 대입하는 것보다
    //빠르거나 동일한 속도(0으로 초기화된 메모리가 없는 경우)가 나옵니다.
}
void push(Pstack stack, int newInt)
{
    Pnode newNode = (Pnode)malloc(sizeof(Node)); //C언어에서는 형변환 명시 안해주셔도 됩니다.
    newNode->data = newInt;
    newNode->next = stack->peak;
    stack->peak = newNode;
    stack->size++;
    //이렇게 쓴다면 케이스를 나누지 않고 구현 가능합니다.
}

int pop(Pstack stack)
{
    if (stack->size == 0)
        return -1;
    int data;
    Pnode tempNode;
    data = stack->peak->data;
    tempNode = stack->peak;
    stack->peak = stack->peak->next;
    stack->size--;
    free(tempNode); //free 안해주시면 메모리 누수가 발생합니다.
    return data;
}
int empty(Pstack stack)
{
    return stack->size == 0 ? 1 : 0;
}
int top(Pstack stack)
{
    return stack->size == 0 ? -1 : stack->peak->data;
}
int size(Pstack stack)
{
    return stack->size;
}
int main()
{
    int T;
    int input;
    char str[20];
    Pstack Stack = createStack();
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {

        scanf("%s", str);
        if (!strcmp(str, "push"))
        {
            scanf("%d", &input);
            push(Stack, input);
        }
        else if (!strcmp(str, "pop"))
        {
            printf("%d\n", pop(Stack));
        }
        else if (!strcmp(str, "size"))
        {
            printf("%d\n", size(Stack));
        }
        else if (!strcmp(str, "empty"))
        {
            printf("%d\n", empty(Stack));
        }
        else if (!strcmp(str, "top"))
        {
            printf("%d\n", top(Stack));
        }
    }
    return 0;
}