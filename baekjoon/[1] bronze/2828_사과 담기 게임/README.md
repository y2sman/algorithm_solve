# 사과 담기 게임

- 랭크 : 브론즈 1
- [사과 담기 게임](https://www.acmicpc.net/problem/2828)
- 그리디 알고리즘

# 풀이

사과를 담는 문제이다.

N칸의 넓이의 스크린, M칸의 넓이를 가진 바구니 그리고 사과가 떨어질 위치가 주어진다.

이런 문제를 보면 항상 그런 생각이 든다. 문제 조건은 문제 설명에 적어야지... 왜 입력 조건에도 적는지... 한글을 잘 못해서 그런지 이렇게 적어둔 글을 보면 늘 잘 모르겠다.

아무튼 문제는 간단하다.

그리디 알고리즘 설명을 보면 문제를 해결하는 과정에서 순간마다 최적의 결정을 하는 방식으로 진행하여 최종 해답에 도달하는 알고리즘이라는데, 결국 조건을 잘 짜면 되는 문제라고 생각한다.

||||||
|:---:|:---:|:---:|:---:|:---:|
|||O|||
|||||O|
|O|||||
|스|-|크|-|린|
|바|구|니|||

```
5 3
3
1
5
3
```
를 입력했다면 위와 같은 형태로 된다는 것이다. 

풀이는 바구니의 크기에 맞추어 좌/우로 움직이는 경우를 계산해서 사과를 받는 조건문을 작성해서 반복문을 돌리면 쉽게 해결된다. 시간도 1초를 주고, 바구니 크기와 스크린 크기도 작아서 이래도 충분히 해결 가능하다.