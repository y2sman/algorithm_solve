# 잃어버린 괄호

- 랭크 : 실버 2
- [잃어버린 괄호](https://www.acmicpc.net/problem/1541)
- 수학
- 문자열
- 그리디 알고리즘
- 파싱

# 풀이

문제를 곰곰히 생각해보면... 괄호를 만들어서 덧셈을 무조건 먼저 수행하면 된다. 그러면 어떤 경우에든 빼는 연산만 남아 가장 작은 숫자를 얻을 수 있다. 문제는 구현인데... regex의 split 사용하는게 쉬울 것 같아 [c++ 레퍼런스 사이트](https://www.cplusplus.com/reference/regex/)를 방문했다.

```cpp
Functions:
regex_match
Match sequence (function template )
regex_search
Search sequence (function template )
regex_replace
Replace matched sequence (function template )
```
근데 없다. 파이썬이랑은 다르구나... 싶어서 그냥 파이썬으로 풀었다. 알고리즘은 cpp로 풀자고 다짐했지만, 오늘도 세상 앞에 타협했다.

구현은 엄청 간단하게 했다. 연산자(+,-)를 기준으로 나누고, 연산자 위치를 다시 계산해서 하나의 분리된 리스트 형태로 만들어주고... +먼저 계산하고, -계산했다. 쉽게 쉽게 하는게 최고다!