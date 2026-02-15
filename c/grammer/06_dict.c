/*
- 제목: 문법 예제 06_dict
- 개념: 코딩 테스트에서 자주 쓰는 C 문법/표현을 짧은 실행 예제로 확인합니다.
- 시간복잡도(필요한 경우): 해당 없음 (문법 데모 중심)
- 주요 변수 의미: 파일 내부 변수 선언 라인과 printf 출력을 함께 읽으면 타입/역할을 빠르게 파악할 수 있습니다.
- 실행 흐름 요약:
  1) 예제에서 사용할 변수/자료를 선언하고 초기화합니다.
  2) 해당 파일의 문법 포인트(연산, 자료형, 라이브러리 함수)를 실제 코드로 실행합니다.
  3) 중간 상태 또는 결과를 printf로 출력해 동작을 눈으로 검증합니다.
  4) 필요하면 반복/조건문으로 다양한 입력 상황을 짧게 시연합니다.
  5) 출력 결과를 통해 문법의 사용 맥락과 주의점을 함께 확인합니다.
- 오픈 카톡방 : https://open.kakao.com/o/gX0WnTCf
- 책 구매 : https://store.kyobobook.co.kr/person/detail/1112299903
- 결과값 설명: 출력 결과를 통해 해당 문법이 어떤 형태로 사용되는지 학습할 수 있습니다.
*/

#include <stdio.h>
#include <string.h>
typedef struct{const char*key; int value;} KV;
int main(void){
    KV map[]={{"apple",3},{"banana",5}};
    for(int i=0;i<2;i++) if(strcmp(map[i].key,"banana")==0) printf("%d\n",map[i].value);
    return 0;
}
