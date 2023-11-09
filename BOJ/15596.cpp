#include <iostream>
#include <vector>

long long sum(std::vector<int> &a) {
	long long ans = 0;
    std::vector<int>::iterator iter;
    for (iter = a.begin(); iter != a.end(); iter++)
    {
        ans += static_cast<long long>(*iter);
    }
	return ans;
}
