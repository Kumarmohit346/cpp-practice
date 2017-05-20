#include<stdio.h>
#include<stdlib.h>

#define WORDSIZE 32
#define BITS_WS 5 //number of bits required to represent value of wordsize
#define MASK 0x1f //bit mask with all the bits in bits_ws set to 1

int initbv(int **bv, int val)
{
	*bv = calloc(val/WORDSIZE + 1,sizeof(int));
	return *bv != NULL;
}
void set(int bv[],int i)
{
	bv[i>>BITS_WS] |= (1<< (i & MASK));
}
int member(int bv[],int i)
{
	return bv[i>>BITS_WS] & (1 << (i & MASK));
}

int main()
{
	int*bv,i;
	int s1[] = {32,5,0};
	int s2[] = {32,4,5,0};

	initbv(&bv,32);

	for (i=0;s1[i];i++)
		set(bv,s1[i]);
	for (i=0;s2[i];i++)
		if (member(bv,s2[i]))
			printf("%d\n",s2[i]);
	free(bv);
        printf("%d\n",sizeof(2));
	return 0;
}
