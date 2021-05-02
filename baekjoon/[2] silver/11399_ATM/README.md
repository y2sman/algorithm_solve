# ATM

- 랭크 : 실버 3
- [ATM](https://www.acmicpc.net/problem/11399)
- 그리디 알고리즘
- 정렬

# 풀이

vector와 pair를 이용한 정렬만으로 간단히 해결되는 문제.

문제에서 순서대로 출력을 하는데, 뽑는 금액만큼 오래걸리는 형태라 제일 적은 돈을 뽑는 사람부터 뽑아야한다. vector와 pair를 이용해서 하긴 했는데, 곰곰히 생각해보니 N번째 사람이 뭘 하는 지는 중요하지 않으므로 꼭 pair를 쓸 필요는 없는 것 같다.

STL을 이용하면 쉽게 풀리는 문제!