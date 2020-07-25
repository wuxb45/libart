#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <inttypes.h>
#include <string.h>
#include "art.h"

int main()
{
	art_tree t;
	int res = art_tree_init(&t);
	int len;
	char buf[10];
	FILE* f = fopen("words2.txt","r");
	uintptr_t line = 1;
	while(fgets(buf, sizeof buf, f)){
		//printf("value: %s",fgets(buf, sizeof buf, f));
		len = strlen(buf);
		buf[len-1] = '\0';
			
		art_insert(&t, (unsigned char*)buf, len, (void*)line);
		printf("line : %s\n",buf);
		line++;			
	}
	printf("tree size: %ld\n",t.size);
	art_callback cb;
	printf("\n\n");
	popular_iter(&t,cb,(void*)line);
	//res = art_tree_destroy(&t);
}
