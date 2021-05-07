# 토마토

- 랭크 : 실버 1
- [토마토](https://www.acmicpc.net/problem/7569)
- 그래프 이론
- 그래프 탐색
- 너비 우선 탐색

# 풀이

[토마토](https://www.acmicpc.net/problem/7576)의 문제와는 같은 이름이지만, 다층 토마토 문제로 살짝 다른 점이 있는 문제였다.

사실 이 문제를 꽤 오래 해결을 못했다. 반례 10종을 가지고 테스트 해도 왜 틀리는지 이해할 수 없었지만... 누군가가 해결책을 알려줘서 해결한 문제이다.

```cpp
priority_queue<pair<int, tuple<int, int, int> >, vector<pair<int, tuple<int, int, int> >>, greater<> > q;
```

```cpp
queue<pair<int, tuple<int, int, int> > > q;
```

해답은 위에 숨어있다. 나는 queue를 사용해서 탐색을 시도하는데, 다른 문제와는 다르게 이 문제에서는 priority_queue를 사용해야했다.

뭔가... 마음으로는 이해가 가는데 머리로는 이해가 잘 가지 않는 갑갑한 느낌...? 사실 [상범빌딩](https://www.acmicpc.net/problem/6593)도 풀어서 쉽게 생각하고 접근한 문제였는데 오랫동안 붙잡고 있어서 마음이 불편했다.

해결책을 알려주신 분의 추가 조언도 있었는데, 나처럼 횟수를 queue에 녹이지 않는 것이 좋다고 했다.

```cpp
queue<int> que;
que.push(1);

while(!que.empty()){
  queue<int> que2;
  
  while(!que.empty()){
    조건 검사

    que2.push(2)
  }
  
  que = que2;
}
```
와 같은 구조라면 조금 더 명확하게 짤 수 있다는 조언을 받고, 나중에 이렇게도 구현해봐야 겠다고 생각했다.

아무튼... 끝! 머리가 복잡하다~!
