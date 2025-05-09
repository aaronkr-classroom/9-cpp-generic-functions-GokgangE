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

// ����� find
template<class In, class X>
In find2(In begin, In end, const X &x) {
	if (begin == end || *begin == x)
		return begin;
	begin++;
	return find2(begin, end, x); // ����� �κ�
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
			swap(*begin++, *end); // swap�Լ��� �ٸ� ���̺귯�� �ʿ�
	}
}

template<class Ran, class X>
bool bineary_search(Ran begin, Ran end, const X& x) {
	while (begin < end) {
		// �߾Ӱ� ã��
		Ran mid = begin + (end - begin) / 2;

		// x�� ����ִ� �κп����� ��� ã��
		if (x < *mid)
			end = mid;
		else if (x > *mid)
			begin = mid + 1;
		// ������
		else return true;
	}
	return false;
}

#endif // ! GUARD_std_lib_funs_h
