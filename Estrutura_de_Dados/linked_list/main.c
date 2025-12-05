
#include <stdio.h>

#include "forward_list.h"

int main()
{
    int n, val;

    ForwardList *l = forward_list_construct();

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        forward_list_push_front(l, val);
    }

    ForwardList *m = forward_list_clone(l);
    n = forward_list_size(m);

    for (int i = 0; i < n; i++)
        printf("%d\n", forward_list_pop_front(m));

    forward_list_destroy(l);
    forward_list_destroy(m);

    return 0;
}