#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
void process_arr1(int ** arr , int * n){
	int first = **arr;
	int new_n = 0;
	for(int i=1; i<*n; i++){
		int x = *(*arr + i);
		if ( x != first )
		{

			*(*arr + new_n) = x;
			++new_n;
		}
	}
	*arr = (int*) realloc(*arr,sizeof(int) * new_n ) ; 
	*n = new_n;

}
int main(){
	int * arr = (int*) malloc(4*sizeof(int)) ;
	arr[0] = 1;
	arr[2] = 4;
	arr[1] = 1;
	arr[3] = 8;
	int n = 4;
	process_arr1(&arr,&n);
	printf("%d %d %d" , arr[0], arr[1], n ) ;
	
	return 0;
}
