# 리모컨

- 랭크 : 골드 5
- [리모컨](https://www.acmicpc.net/problem/1107)
- 브루트포스 알고리즘

# 풀이

고장난 리모컨을 바탕으로 버튼을 몇번 눌러야 원하는 채널에 도달할 수 있는지에 대한 문제였다. 나 같은 경우에는 DP로 생각했었다. 버튼을 모두 누를 수 있는 수인 1332를 가정해보면, "DP[1332]=DP[1331]+1" 와 같이 계산해서 1331을 누르면 4번이고, 이전 번호까지 도달해서 +1하면 5번 누르는거니까 비교해서 하려고 했다.

이 방법의 문제는 뒤에서 눌러서 접근하는 방법도 있다.

```cpp
500000
8
0 2 3 4 6 7 8 9
```
문제에서 주어진 예제중 하나인데, 이 채널을 누르려면 두가지 방법이 있다. 511111번을 누른 다음에 채널을 내려오는 방법과, 155555에서 부터 올라가는 방법이다. 당연히 511111번에서 내려오는 방법이 빠르지만, 앞서 이야기한 방법으로는 이 부분을 해결할 수 없다.

그래서 새로운 방법을 생각했다. 일단, 1000000번까지 생존해있는 버튼으로 누를 수 있다면 몇번 눌러야하는지를 저장한 배열을 하나 만든다. 그리고 못누르는 채널이면 -1을 넣어두었다. 이를 바탕으로 원하는 채널 X에서 위와 아래로 가장 가까운 누를 수 있는 채널을 찾아서 거리를 계산해서 풀었다.

늘 이런 문제는 범위가 헷갈린다. 이것도 새로운 마음으로 다시 코딩해서 풀었다. 아무튼 끝!