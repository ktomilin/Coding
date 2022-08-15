// ReverseInt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Solution {
public:
	int reverse(int x) {
		int rev = 0;
		while (x != 0) {
			int pop = x % 10;
			x /= 10;
			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
			if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
			rev = rev * 10 + pop;
		}
		return rev;
	}
};


int main()
{
	Solution solution;
	int res = solution.reverse(-234);

	int big_int = INT_MAX;
	big_int += 1;
	
}

