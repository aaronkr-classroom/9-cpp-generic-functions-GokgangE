#pragma once
// spliht.h
#ifndef GUARD_split_h
#define GUARD_split_h

#include <algorithm> // find_if()
#include <cctype> // isspace()
#include <string>

using namespace std;

// 인수가 공백일 때는 true, 그 외에는 false
inline bool space(char c) {
	return isspace(c);
}
inline bool not_space(char c) {
	return !isspace(c);
}


template<class Out>
void split(const string& s, Out os) {
	typedef string::const_iterator iter;

	iter i = s.begin();

	while (i != s.end()) {
		// 지금 i위치부터 첫 번째 띄어쓰기 아닌 문자 찾기
		i = find_if(i, s.end(), not_space);

		// 순서상 다음 단어의 끝을 처음
		// 띄어쓰기 문자 찾기
		iter j = find_if(i, s.end(), space);

		// 공백이 아닌 문자들을 찾았을 때
		if (i != s.end()) {
			*os++ = string(i, j);
		}

		// i 반복자 위치가 j 반복자의 위치를 저장하기
		i = j;
	}
}

#endif // !GUARD_split_h
