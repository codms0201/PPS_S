/*
다장조는 c d e f g a b C, 총 8개 음으로 이루어져있다. 이 문제에서 8개 음은 다음과 같이 숫자로 바꾸어 표현한다. c는 1로, d는 2로, ..., C를 8로 바꾼다.

1부터 8까지 차례대로 연주한다면 ascending, 8부터 1까지 차례대로 연주한다면 descending, 둘 다 아니라면 mixed 이다.

연주한 순서가 주어졌을 때, 이것이 ascending인지, descending인지, 아니면 mixed인지 판별하는 프로그램을 작성하시오.
*/

#include <stdio.h>
int main(){
    int n[8]={0};
    int result = 0;

    for(int i=0; i<8; i++){
        scanf("%d", &n[i]);
    }

    if(n[0] == 1){
        for(int i=1; i<8; i++){
            if(n[i] == i+1) result = 1;
            else {
                result = 0;
                break;
            }
            
        }
    }

    if(n[0] == 8){
        for(int i=1; i<8; i++){
            if(n[i] == 8-i) result = 2;
            else{
                result = 0;
                break;
            }
        }
    }

    if(result == 1) printf("ascending");
    else if(result == 2) printf("descending");
    else printf("mixed");

    return 0;
}