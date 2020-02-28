/*************************************************************************
	> File Name: LeetCode202.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月28日 星期五 16时33分45秒
 ************************************************************************/

int get_len(int n) {
    int sum = 0;
    while (n) {
        sum += pow(n % 10, 2);
        n /= 10;
    }
    return sum;
}



bool isHappy(int n) {
    int p = n, q = n;
    do {
        p = get_len(p);
        q = get_len(get_len(q));
        if (p == q) break;
    } while (p != q);
    return p == 1;
}
