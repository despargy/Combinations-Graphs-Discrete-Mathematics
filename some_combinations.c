/*
	A.M 8491 Despina Ekaterini Argiropoulos
	IDE DEV C++ 5.11
	References
	http://www.martinbroadhurst.com/permutations.html
	http://www.martinbroadhurst.com/k-permutations.html
	http://www.martinbroadhurst.com/combinations.html
	http://www.martinbroadhurst.com/multicombinations.html
	http://rosettacode.org/wiki/Permutations_with_repetitions#C 
*/
#define MAX 100 // n and k must be <MAX
#include <stdio.h>
static void swap( int *ar,  int first,  int second);
static void reverse( int *ar, int len);
int next_permutation( int *ar, int len);
int next_combination( int *ar, int n,  int k);
int next_k_permutation( int *ar, int,  int k);
int next_multicombination( int *ar, int n,  int k);
int combi_repeat(int *ar,int n,int k);
void message(int x);

int main()
{
int res,i,index,n,k,select,not_valid,ar[MAX]; 
do{
	for (i=0;i<MAX;i++) //array initialization 						 
				 ar[i]=i;				
	index=0;
	message(0); //screen messages
	do
		{
			printf("\t Please select number 0..5 from the menu \n");
			fflush(stdin);scanf("%d",&select);	
		} 	while (!(select>=0 && select<=5));
	switch(select)
	{
		case 1:			
			message(1);	//screen messages		
			do { scanf("%d",&n);not_valid=!(n>=2 && n<MAX-1); if (not_valid) printf("Not Valid number\n");
				} while (not_valid);			
			do {	
				res=next_permutation(ar, n);
				index=index+1;
				printf("%d. ",index);
				for (i=0;i<n;i++)
					printf("%d ",ar[i]+1);	
				printf("\n");
				} while (res);
			break;
		case 2:			
			message(2);		
			do { scanf("%d %d",&n,&k);not_valid=!(n>=2 && n<MAX-1 && k<=n); if (not_valid) printf("Not Valid numbers \n");
				} while (not_valid);	
			do {	
				index=index+1;
				printf("%d. ",index);	
				res= next_combination( ar, n,   k);
				for (i=0;i<k;i++)
					printf("%d ",ar[i]+1);	
				printf("\n");
				} while (res);
			break;
		case 3:	
			message(3);			
			do { scanf("%d %d",&n,&k);not_valid=!(n>=2 && n<MAX-1 && k<=n); if (not_valid) printf("Not Valid numbers \n");
				} while (not_valid);
			do {		
				res=next_k_permutation(ar,n,k);
				index=index+1;
				printf("%d. ",index);
				for (i=0;i<k;i++)			
					printf("%d ",ar[i]+1);
				printf("\n");
	 			} while (res);	
	 			break;
	 	case 4:
			message(4);			 
			do { scanf("%d %d",&n,&k);not_valid=!(n>=2 && n<MAX-1 && k<=n); if (not_valid) printf("Not Valid numbers \n");
				} while (not_valid);
			combi_repeat(ar,n,k);	
			break;	
		case 5:
			message(5);				
			do { scanf("%d %d",&n,&k);not_valid=!(n>=2 && n<MAX-1 && k>=2 && k<=MAX-1); if (not_valid) printf("Not Valid numbers \n");
				} while (not_valid);
			for (i=0;i<MAX;i++)		//array initialization 		 
					ar[i]=0;					
			do {				
				index=index+1;
				printf("%d. ",index);
				for (i=0;i<k;i++)			
					printf("%d ",ar[i]+1);
				printf("\n");
				res=next_multicombination( ar, n, k);
	 			} while (res);
				break;
	 	default:			
	 		break;
	}
	printf("press ENTER ");	fflush(stdin); getchar();printf("\n\n\n\n\n\n");
} while (!(select==0));

return 0;	
}
//
void message(int x)
{
	switch (x)
	{	
	case 0:
			printf("1.Simple Permutations\n");
			printf("2.Simple Combinations\n");
			printf("3.k-permutations of n\n");
			printf("4.k-permutations of n with repetitions \n");
			printf("5.Combinations of n elements in set of k with repetitions \n\n");
			printf("0.  End programm \n\n");	
			break;
	case 1:
			printf("* Permutations of n will be produced. *\n");	
			printf("***  n! ***\n");
			printf("Example: n=3 will produce: 6 simple permutations\n");
			printf("Give number n :\n");	
			break;
	case 2:
	 		printf("* Combinations of n elements in set of k will be produced. *\n");	
			printf("***  n!/((n-k)!k!) ***\n");	
			printf("Example: n=5 and k=3 will produce: 10 combinations of 3 elements\n");
			printf("Give number n  and number k :\n");	
			break;
	case 3:
			printf("* k-permutations of n will be produced. *\n");			
			printf("***  n!/(n-k)! = (n-k+1)...n ***\n");		
			printf("Example: n=5 and k=3 will produce: 60 3-permutations of 10 elements\n");
			printf("Give number n  and number k :\n");	
			break;	
	case 4:
			printf("* k-permutations of n with repetitions will be produced. *\n");			
			printf("***  n^k ***\n");		
			printf("Example: n=3 and k=2 will produce: 9 2-permutations of 3 elements with repetitions\n");
			printf("Give number n  and number k :\n");
			break;	
	case 5:
			printf("* Combinations of n elements in set of k with repetitions will be produced. *\n");			
			printf("***  (n+k-1 , k) = (n+k-1)!/(k!*(n-1)!) ***\n");		
			printf("Example: n=3 and k=5 will produce: 21 5-permutations of 3 elements with repetitions\n");
			printf("Give number n  and number k :\n");
			break;	
	}
	return;		
}
//
static void swap( int *ar,  int first,  int second)
{
    int temp = ar[first];
    ar[first] = ar[second];
    ar[second] = temp;
}
// 
static void reverse( int *ar, int len)
{
    int i, j; 
    for (i = 0, j = len - 1; i < j; i++, j--)        
		swap(ar, i, j);    
}
// 
int next_permutation( int *ar, int len)
{
     int i1, i2;
     int result = 0;
     
    /* Find the rightmost element that is the first in a pair in ascending order */
    for (i1 = len - 2, i2 = len - 1; ar[i2] <= ar[i1] && i1 != 0; i1--, i2--);
    if (ar[i2] <= ar[i1]) {
        /* If not found, array is highest permutation */
        reverse(ar, len);
    }
    else {
        /* Find the rightmost element to the right of i1 that is greater than ar[i1] */
        for (i2 = len - 1; i2 > i1 && ar[i2] <= ar[i1]; i2--);
        /* Swap it with the first one */
        swap(ar, i1, i2);
        /* Reverse the remainder */
        reverse(ar + i1 + 1, len - i1 - 1);
        result = 1;
    }
    return result;
}
//
int next_combination( int *ar, int n,  int k)
{
     int finished = 0;
     int changed = 0;
     int i;
 
    if (k > 0) {
        for (i = k - 1; !finished && !changed; i--) {
            if (ar[i] < (n - 1) - (k - 1) + i) {
                /* Increment this element */
                ar[i]++;
                if (i < k - 1) {
                    /* Turn the elements after it into a linear sequence */
                     int j;
                    for (j = i + 1; j < k; j++) {
                        ar[j] = ar[j - 1] + 1;
                    }
                }
                changed = 1;
            }
            finished = i == 0;
        }
        if (!changed) {
            /* Reset to first combination */
            for (i = 0; i < k; i++) {
                ar[i] = i;
            }
        }
    }
    return changed;
}
//
int next_k_permutation( int *ar, int n,  int k)
{
    int result = next_permutation(ar, k);
    if (result == 0) {
        result = next_combination(ar, n, k);
    }
    return result;
}
//
int next_multicombination( int *ar, int n,  int k)
{
    int changed = 0;
    int i;
 
    for (i = k - 1; i >= 0 && !changed; i--) {
        if (ar[i] < n - 1) {
            /* Increment this element */
            ar[i]++;
            if (i < k - 1) {
                /* Make the elements after it the same */
                int j;
                for (j = i + 1; j < k; j++) {
                    ar[j] = ar[j - 1];
                }
            }
            changed = 1;
        }
    }
    if (!changed) {
        /* Reset to first combination */
        for (i = 0; i < k; i++) {
            ar[i] = 0;
        }
    }
    return changed;
}
//    
int combi_repeat(int *ar,int n,int k)
{
	int temp2,temp,index=0;
	for( temp2 = 1 ; temp2 <= k; temp2++)
					ar[temp2]=1;		
			ar[k]=0;
			temp=k, temp2;
			while(1)
					{
						if(ar[temp]==n)
							{
								temp--;
								if(temp==0)
								return 0;
							}	
						else
							{
								ar[temp]++;
								while(temp<k)
								{
									temp++;
									ar[temp]=1;
								}
 								index=index+1;
								printf("%d. ",index);
								for( temp2 = 1 ; temp2 <= k; temp2++)											
										printf("%d ", ar[temp2]);									
								printf("\n");
							}
					}
}


