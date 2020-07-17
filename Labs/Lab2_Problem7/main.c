#include <stdio.h>
#include <stdlib.h>
//7. a. Read sequences of positive integer numbers (reading of each sequence ends by 0, reading of
//all the sequences ends by -1) and determine the maximum element of each sequence and the
//maxim element of the global sequence.
//b. Given a vector of numbers, find the longest contiguous subsequence such that all elements are
//in a given interval.
void citire()
{
    int c = 0, maxx_seq = -1, maxx_global = -1, a[100], i = 0;
    scanf("%d", &c);
    while(c != -1)
    {
        maxx_seq = -1;
        while(c != 0 && c != -1)
        {
            if(c > maxx_seq)
                maxx_seq = c;
            scanf("%d", &c);
        }
        if(maxx_seq > maxx_global)
            maxx_global = maxx_seq;

        i++;
        a[i] = maxx_seq;
        if(c == -1)
            break;
        scanf("%d", &c);
    }
    printf("The maximums are: ");
    for(int j = 1; j <= i; j++)
        printf("%d ", a[j]);
    printf("\n");
    printf("The maximum of the sequences is: %d", maxx_global);
}

void sequence()
{
    int n = 0, i = 0, a[100], c = 0, b = 0, len = 0, end_pos = 0, max_len = 0, aux = 0;

    printf("Lungimea sirului: ");
    scanf("%d", &n);
    //printf("\n");
    //printf("Elementele: ");
    for(i = 1; i <= n; i++)
    {
        printf("Elementul curent ");
        scanf("%d", &a[i]);
    }
    printf("Lower Bound: ");
    scanf("%d", &c);
    printf("Upper Bound: ");
    scanf("%d", &b);

    if(b < c)
    {
        aux = c;
        c = b;
        b = aux;
    }
    for(i = 1; i <= n; i++)
    {
        if(a[i] >= c && a[i] <= b)
            len++;
        else
            len = 0;
        if(len > max_len)
        {
            max_len = len;
            end_pos = i;
        }
    }

    for(i = end_pos - max_len + 1; i <= end_pos; i++)
        printf("%d ", a[i]);

}

int main()
{
    sequence();
    //citire();
    return 0;
}
