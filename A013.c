/*
빈 정수 nums 배열을 감안할 때, 모든 요소는 하나를 제외하고 두 번 나타난다. 그 하나를 찾아봐.

선형 런타임 복잡성을 가진 솔루션을 구현하고 일정한 추가 공간만 사용해야 합니다.

 

예시 1:

입력: 숫자 = [2,2,1]출력: 1

예시 2:

입력: 숫자 = [4,1,2,1,2]출력: 4

예시 3:

입력: 숫자 = [1]출력: 1
 

제약 조건:

1 <= nums.length <= 3 * 10^4
-3 * 104 <= nums[i] <= 3 * 10^4
배열의 각 요소는 한 번만 나타나는 하나의 요소를 제외하고 두 번 나타납니다.
*/

#include <stdio.h>
int main(){
    int nums[3*10^4];
    int count=0;
    for(int i=0; ; i++){
        scanf("%d", &nums[i]);
        if(nums[i] == -1) break;
        count++;
    }
    int num = nums[0];
    for(int i=0; i<count; i++){
        for(int j=0; j<count; j++){
            if(i != j){
                if(nums[i] == nums[j]) num = nums[i+1];
                break;
            }
        }
    }
    printf("%d", num);
    return 0;
}