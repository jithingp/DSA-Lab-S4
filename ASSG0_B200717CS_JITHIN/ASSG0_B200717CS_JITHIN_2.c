#include <stdio.h>
#include <stdlib.h>
struct s
{
    int head;
    int tail;
    int *e;
};
int isfull(struct s *a, int n)
{
    if (a->tail == n - 1)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
void enqueue(struct s *a, int n, int k)
{
    int b = isfull(a, n);
    if (b == 1)
    {
        printf("%d\n", 1);
    }
    else
    {
        a->tail++;
        a->e[a->tail] = k;

        if (a->head == -1)
        {
            a->head = 0;
        }
    }
}
int isempty(struct s *a)
{
    if (a->head == -1 || a->head > a->tail)
    {
        return 1;
    }
    return -1;
}
void dequeue(struct s *a, int n)
{
    if (isempty(a) == 1)
    {
        printf("%d\n", 1);
    }
    else
    {
        printf("%d\n", a->e[a->head]);
        a->head++;
    }
}
int main()
{
    struct s *q = NULL;
    q = (struct s *)malloc(sizeof(struct s));
    int n, k, b;
    scanf("%d", &n);
    q->head = -1;
    q->tail = -1;
    q->e = (int *)malloc(n * sizeof(int));
    char ch;
    do
    {
        scanf("%c", &ch);
        switch (ch)
        {
        case 'i':
            scanf("%d", &k);
            enqueue(q, n, k);
            break;
        case 'd':
            dequeue(q, n);
            break;
        case 'e':
            b = isempty(q);
            printf("%d\n", b);
            break;
        case 'f':
            b = isfull(q, n);
            printf("%d\n", b);
            break;
        }
    } while (ch != 't');

    return 0;
}