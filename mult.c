# include <stdio.h>
# include <stdlib.h>

int helper(int min, int max, int *ans) {
    if(ans[min] != -1)
        return ans[min];
    else if (min == 0)
        ans[min] = 0;
    else if (min == 1)
        ans[min] = max;

    if (ans[min] != -1)
        return ans[min];

    int even = 0;
    if (min % 2 == 0)
        even = 1;

    if (even) {
        ans[min] =  helper(min >> 1, max, ans) << 1;
    }
    else
        ans[min] = (helper(min >> 1, max, ans) << 1) + max;

    return ans[min];
}

int mult(int a, int b) {
    int sign = 1;
    int min = (a <= b) ? a : b;
    int max;

    if (a < 0) {
        sign = -sign;
        a = -a;
    }
    if (b < 0) {
        sign = - sign;
        b = -b;
    }

    min = (a <= b) ? a : b;
    if (min == a)
        max = b;
    else
        max = a;

    int *ans = calloc(min + 1, sizeof(int));
    for(int i=0; i <= min; i++)
        ans[i] = -1;

    if (sign == -1) {
        int out = -helper(min, max, ans);
        free(ans);
        return out;
    }
    else {
        int out;
        out = helper(min, max, ans);
        free(ans);
        return out;
    }
}