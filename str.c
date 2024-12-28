#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>

//VALGRIND ALERT
char * process_str1( char * c){
	char * cs = strdup(c);
	char * word = strtok(cs," \t'");
	char * new_word = NULL;
	char * ans = calloc(1, sizeof(char) ) ;
	int slen = 0;
	//printf("\n d;fl;ldf;ldfl; \n %s \n dkjfsdfjksfjkdkjfd\n", cs ) ; 
	//word = strtok(cs," \t");
	if(word != NULL){
		new_word = strtok(NULL," \t");
	}	
	else{
		return NULL;
	}
	int i=0;
	do{
		//printf("\n!!!!!!! %d %s !!!!!!!\n",i, new_word) ; 
		++i;
		if(strcmp(word,new_word) != 0){
			int sslen = strlen(ans);
			slen += sslen;
			ans = (char*) realloc(ans,(slen+1)*sizeof(char));
			if(i > 1)
				strcat(ans," ");
			strcat(ans,new_word);
		}
		new_word = strtok(NULL," \t"); 
	} while(new_word != NULL);
	free(cs);
	return ans;
}


char * process_str2(char * s){
	if(!s) return NULL;
	int slen = strlen(s);
	if(!slen) return NULL;
	int new_slen = 0;
	char * cs = strdup(s);
	for(int i=0; i<slen; i++){
		if(cs[i] < 'A' || cs[i] > 'Z')
		{
			cs[new_slen] = s[i];
			++new_slen;
		}
	}
	cs[new_slen] = '\0';
	cs = (char*) realloc(cs,(new_slen+1) *sizeof(char) ) ;
	return cs;
}
int main(){
	char * c = readline("");
	char * s = process_str2(c);
	printf("\n'%s'\n'%s'\n",c,s);	
	return 0;
}
