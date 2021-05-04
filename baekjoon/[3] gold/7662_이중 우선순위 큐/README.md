# 이중 우선순위 큐

- 랭크 : 골드 5
- [이중 우선순위 큐](https://www.acmicpc.net/problem/7662)
- 자료 구조
- 우선순위 큐
- 트리를 사용한 집합과 맵

# 풀이

처음 들었던 생각은, STL 중의 "priority_queue"를 이용하는 것이다. priority_queue가 최대값이 가장 위로 올라오게 정렬이 되어서 저장이 되지만, 최소값이 올라오도록 만들 수도 있기 때문이다. 이러한 방식을 사용하면, 최대값을 가진 queue와 최소값을 가진 queue를 만들 수 있다. 근데 문제는... 비어있는 경우를 어떻게 구할지가 모르겠어서 이 풀이법은 넘겼다.

그래서 해결한 방법은 SET이다. 일단 SET STL을 한번도 써본적은 없다. 하지만 주변에서 알고리즘 이야기를 들으면서 정렬 되는 STL로 알고는 있었다. (주된 이유는 삭제가 된다는 점) 그래서 찾아봤더니...

```
<set>
Set header
Header that defines the set and multiset container classes:

Classes
set
Set (class template )
multiset
Multiple-key set (class template )

Functions
begin
Iterator to beginning (function template )
end
Iterator to end (function template )
```
[C++ 레퍼런스 사이트](http://www.cplusplus.com/reference/set/)에서 SET을 둘러보니... "multiset"이 나왔다. 무려...! 이 문제에서 필요한 조건(중복 입력이 들어올 수 있음)을 만족한다!

나머지는 매우 쉬웠다. 새로운 STL을 이용해서 구현만 하면... 끝!