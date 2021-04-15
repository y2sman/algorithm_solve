# 나는야 포켓몬 마스터 이다솜

- 랭크 : 실버 4
- [나는야 포켓몬 마스터 이다솜](https://www.acmicpc.net/problem/1620)
- 자료 구조
- 문자열
- 해시를 사용한 집합과 맵

# 풀이

"solved.ac"의 클래스3 돌파용 문제.

어떻게 풀지 고민을 해봤는데... 이진탐색을 이용해도 좋을 것 같았다. 이름과 번호를 pair로 묶고... 메모리 제한도 넉넉해보이니, (사실 시간제한도 넉넉해 보였다. 나중에 보니까 아니긴 했다.) 괜찮은 선택 같다.

번호를 알려주고 이름을 물어보는건 그냥 vector에서 바로 조회하면 빠르기 때문에 번호가 나왔을때용 데이터셋 하나, 이름이 나왔을때용 데이터셋 하나를 나눴다.

이번에는 C++ STL의 [isdigit](https://www.cplusplus.com/reference/cctype/isdigit/?kw=isdigit)과 [compare](https://www.cplusplus.com/reference/string/string/compare/)를 애용했다.

[isdigit](https://www.cplusplus.com/reference/cctype/isdigit/?kw=isdigit)은 입력이 문자와 숫자로 들어오는 두가지 경우가 있으니까, 그걸 검사하기 위해 사용했다. (string을 사용해서 그렇다.)


|value|relation between compared string and comparing string|
|:---:|:---:|
|0|They compare equal|
|<0|Either the value of the first character that does not match is lower in the compared string, or all compared characters match but the compared string is shorter.|
|>0|Either the value of the first character that does not match is greater in the compared string, or all compared characters match but the compared string is longer.|

[compare](https://www.cplusplus.com/reference/string/string/compare/)에 대한 내용은 cplusplus.com 의 정보를 일부 발췌했다. 내가 이 STL에 기대한건, 문자열 비교를 해주는 것이었다. 단순히 영어만 읽어봤을때는 첫글자 비교하고 길이 비교해서 반환해주는가 싶어서 확인해봤는데 그런건 아니었다.

문자열 비교해서 양수, 음수를 반환해주는 것을 이용해서 이진탐색 코드으로 작성했다. 음... 일부러 처음쓰는 STL도 막 써가면서 짜느라 좀 더 오래 걸린 것 같다.

언젠가 익숙해지겠지~

<br><br>
PS. vector에서 pair를 쓰고있을때 second 기준으로 정렬하는 방법
```cpp
bool sortbysec(const pair<int, string> &a, const pair<int, string> &b)
{
  return (a.second < b.second);
}
```
이걸 sort 할때 넣어주면 된다. 이게 pair<int, int>의 비교가 아니라도, 대소비교로 하면 잘 된다. vector에 pair를 넣어 쓰는 경우가 많은데, 앞으로 잘 애용해야겠다.
