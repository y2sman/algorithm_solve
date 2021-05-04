# 좌표 압축

- 랭크 : 실버 2
- [좌표 압축](https://www.acmicpc.net/problem/18870)
- 정렬
- 값 / 좌표 압축

# 풀이

좌표값을 입력받는데, 가장 작은 값을 기준으로 0부터 시작해서 수치를 다시 맞추는 문제이다.

```cpp
vector<int> map;
vector<pair<int, int> > coord;
```
처음에는 위와 같은 구조를 이용하려 했다. coord에서 pair는 실제 값과 축소된 좌표 값을 쌍으로 만들고, vector find를 이용해서 map과 대조하려 했다.

하지만, vector에 pair를 쓴 경우에는 find를 사용할 수 없었다. (sort는 되는데 이건 왜 안되게 구현을...???) 고민을 조금 하다보니 어차피 find를 사용했어도 find가 O(n)이므로 시간초과가 났을 것 같았다.

그래서 이진탐색을 구현하고, 이진탐색에서 return value를 축소된 좌표값을 반환하는 것으로 해결했다.