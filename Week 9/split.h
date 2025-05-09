#pragma once
// spliht.h
#ifndef GUARD_split_h
#define GUARD_split_h

#include <algorithm> // find_if()
#include <cctype> // isspace()
#include <string>

using namespace std;

// �μ��� ������ ���� true, �� �ܿ��� false
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
		// ���� i��ġ���� ù ��° ���� �ƴ� ���� ã��
		i = find_if(i, s.end(), not_space);

		// ������ ���� �ܾ��� ���� ó��
		// ���� ���� ã��
		iter j = find_if(i, s.end(), space);

		// ������ �ƴ� ���ڵ��� ã���� ��
		if (i != s.end()) {
			*os++ = string(i, j);
		}

		// i �ݺ��� ��ġ�� j �ݺ����� ��ġ�� �����ϱ�
		i = j;
	}
}

#endif // !GUARD_split_h
