# push_swap
[subject](https://github.com/tozggg/push_swap/blob/master/subject.pdf)  
임의의 수가 담긴 스택을 명령어를 사용해서 가장 효율적으로 정렬하는 프로그램 만들기
<br>
<br>
## Details
### 과제정리

- 2개의 스택 ( a 와 b )
    - a스택에는 중복되지않는 난수(음,양의정수)가 들어간다 (프로그램 실행시 argv인자로)
    - b스택은 비어있음
- 명령어

```c
//swap (top과 top-1 교환)
sa / sb / ss

//push (a에 b의 top을, b에 a의 top을)(비어있으면 안함)
pa / pb

//rotate (한칸씩 땡기고 top이 bottom으로)
ra / rb / rr

//rotate반대 (한칸씩 밀고 bottom이 top으로)
rra / rrb / rrr
```

- 결론은 프로그램 실행시 임의의 난수들을 주고,
    
    가장 효율적인(시간복잡도) 명령어집합으로 정렬하는 방법 찾기

### 주의사항

- push_swap 실행파일 만들기
- Makefile
- 전역변수 사용금지
- 누수x  /  에러처리
- Norm
- write read malloc free exit 함수 사용가능 

### checklist

- 메모리 누수가 나지는 않는가?
- 에러처리
    - 정수가 아닌 인자
    - 중복인자
    - int의 범위초과
    - 인자가 없을때
- identity test
    - 인자가 한개이거나 이미 정렬이 되어있을때 아무것도 표시x
- simple version
    - 인자가 3개
    - 인자가 5개
        
        일때 check_OS에 대해 OK가 뜨고 명령어의 개수확인
        
- middle version
    - 랜덤 인자 100개
- advanced version
    - 랜덤인자 500개

---

### tip

- 정렬방법?
    - pivot을 활용한 quicksort ... 조금더 이해필요
    - pivot을 2개로 잡는 방법..?
- 스택구현?
    - double LinkedList로 구현하기
    - size가 있는 stack을 감싸는 구조체도..?
- 예외처리시 주의사항
    - 표준에러로 출력하기
    - 파싱시 "1 3 5" 가 인자로 들어왔을때도 생각하기
- 최적화
    - 범위가 2나 3일때 따로처리
    - ra와 rra 횟수 줄이는법 생각
    - 이미 정렬되어있다면 건너뛰는 알고리즘

### 알고리즘

- 기본알고리즘
    
    pivot을 잡아서 큰것들은 a남겨두기→작은것은 b로넘기기
    
    반복후 b에 넘긴것에 대해 올라가면서 pivot을잡아서 a에 넘기거나 남겨두기
    
    (a에 넘겼다면 그것부터 처리해야겠죠)
    
    = 재귀적으로
    
    atob와 btoa는 범위가1일시 리턴됨 ( btoa는 pa하면서 return )
    
- 기본스택a가 정렬되있는지 확인
- 개수에따라 다른 solve 0 / 2 / 3 / 5 / 그이상
- pivot 2개 사용이유
    - rra와 rrb 를 rrr로 합치는 느낌 ( 합칠수 있을만큼의 조건주기 )
- ra와 rra action시 전체스택의 크기보고 빠른거 선택하기?
- ? rr은 사용불가 → a와 b에서의 행동이 구분적으로 이루어지기 때문
- ? s관련도 사용불가 → 모르니까!!
- ?? pivot을 어떤것으로 잡아야 가장 효율이 좋을까
    
    ⇒ 배열에 저장해서 quicksort로 정렬한후 중앙, 3분의1, 3분의2 지점을 잡음
    

### 추가 최적화

- b의 그룹이 DESC 정렬되어있다면 그만큼 pa하고 끝
- a의 그룹이 ASC 정렬되어있다면 return; ( 상위함수로 )
- 그룹의 범위가 2~3일때 처리하는 로직
- rra로 되돌아올때 ra가 더빠른지 확인후 그렇다면 반대로(ra)
    - ! ra는 rra로 바꿀수없음 → 솎아내는거기 때문
- ? a에서 넘어갈 마지막원소시
    - ra → pb → rra 를 sa → pb로 바꾸기..?

### 예외처리종합

- 실행파일(main)에 인자로 들어온게
    - 정수가 아닐때
    - 정수의 범위를 넘었을때
    - 중복될때 (스택에 이미 있는 수)
- 스택
    - 2  /  5
- 파트
    - 잘 정렬되어 있을때
    - 2  /  3
