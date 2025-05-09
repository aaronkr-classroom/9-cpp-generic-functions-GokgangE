#pragma once
// std_lib_funs.h
#ifndef GUARD_std_lib_funs_h
#define GUARD_std_lib_funs_h

template<class In, class X>
In find(In begin, In end, const X &x) {
	while (begin != end && *begin != x)
		++begin;	
	return begin;
}

// 재귀적 find
template<class In, class X>
In find2(In begin, In end, const X &x) {
	if (begin == end || *begin == x)
		return begin;
	begin++;
	return find2(begin, end, x); // 재귀적 부분
}

template<class In, class Out>
Out copy(In begin, In end, Out dest) {
	while (begin != end)
		*dest++ = *begin++;
	return dest;
}

template<class For, class X>
void replace(For beg, For end, const X& x, const X& y) {
	while (beg != end) {
		if (*beg == x)
			*beg = y;
		++beg;
	}
}

template<class Bi>
void reverse(Bi begin, Bi end) {
	while (begin != end) {
		--end;
		if (begin != end)
			swap(*begin++, *end); // swap함수는 다른 라이브러리 필요
	}
}

template<class Ran, class X>
bool bineary_search(Ran begin, Ran end, const X& x) {
	while (begin < end) {
		// 중앙값 찾기
		Ran mid = begin + (end - begin) / 2;

		// x가 들어있는 부분에서만 계속 찾기
		if (x < *mid)
			end = mid;
		else if (x > *mid)
			begin = mid + 1;
		// 마지막
		else return true;
	}
	return false;
}

#endif // ! GUARD_std_lib_funs_h
