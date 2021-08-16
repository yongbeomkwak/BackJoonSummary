#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;++i)
int main()
{
    // ios_base ::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

/*
    헤더파일 : <stdio.h>, <cstdio>
함수원형 : char* gets(char* str);
표준 입력(stdin)으로 들어온 문자열을 C언어 스타일 문자열인 char*, char[] 타입으로 저장해 주는 함수 입니다.
gets 함수가 "문자열"이라고 감지하는 기준은 개행(\n)입니다.
gets 함수는 들어온 문자열ㅇ에 대해 '\0'울 붙여줍니다.
정리하면, 표준입력으로 들어온 문자열을 개행한 부분 앞까지 짤라서 char* 타입의 문자열로 저장해주고, 자동으로 문자열 맨 끝에 '\0'을 넣어서 문자열을 완성해 줍니다.
즉 길이=L , L-1개 까지 입력 가능
*/

// char str[10];
//     for (int i = 0; i < 1; ++i)
//     {
//         gets(str);
//         printf("str : %s\n", str);
//         int j = 0;
//         while (true)
//         {
//             if (str[j] == '\0')
//                 break;
//             printf("[%c]", str[j]);
//             ++j;
//         }
//         printf("\n\n");
//     }
//     return 0;
/*
헤더파일 : <stdio.h>, <cstdio>

함수원형 : int puts(const char* str)



C언어 스타일의 문자열인 char*, char[] 타입을 표준 출력(stdout)으로 보내는 함수입니다.

puts 함수가 문자열을 출력을 끝까지 하고나면 개행(\n)도 보내기 때문에 자동적으로 줄이 바뀌게 됩니다.

puts 함수의 매개변수로 들어온 문자열 처음부터 문자열의 끝 '\0' 까지의 문자열을 출력합니다.

정리하면, 매개변수로 들어온 char* 타입의 문자열의 주소값으로 가서 문자열의 끝 '\0'이 나올때까지의 문자들을 표준출력(output)에 쭉 출력해주다가 다 출력한 후에는 친절하게 개행('\0') 까지 넣어주는 함수 입니다.

*/
 
 char str2[10];
    for (int i = 0; i < 1; ++i)
    {
        printf("input : ");
        gets(str2);
 
        printf("output : ");
        puts(str2);
    }


}
