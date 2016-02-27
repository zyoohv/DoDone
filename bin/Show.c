#include <stdio.h>
#include <string.h>

#define buflen 150

char files[35][115];
int all[35],finish[35];
char buf[155];

int main(int argc,char *argv[]){

	freopen(argv[1],"r",stdin);
	int cnt = 0;
	while(scanf("%s",files[cnt]) != EOF) cnt++;

	int len,slen,tot;
	for(int i=0;i<cnt;i++){
		len = strlen(argv[2]);
		for(int j=0;j<len;j++) buf[j] = argv[2][j];

		slen = strlen(files[i]);
		tot = len;
		for(int j=0;j<slen;j++) buf[tot++] = files[i][j];
		buf[tot] = '\0';

		freopen(buf,"r",stdin);
		scanf("%d",&all[i]);

		//----------------------------

		len = strlen(argv[3]);
		for(int j=0;j<len;j++) buf[j] = argv[3][j];
		
		slen = strlen(files[i]);
		tot = len;
		for(int j=0;j<slen;j++) buf[tot++] = files[i][j];
		buf[tot] = '\0';

		freopen(buf,"r",stdin);
		scanf("%d",&finish[i]);
	}
	//printf("---test\n");
	//for(int i=0;i<cnt;i++) printf("all : %d finish : %d\n",all[i],finish[i]);

	freopen(argv[4],"w",stdout);
	for(int i=0;i<cnt;i++){
		printf("%s:[",files[i]);
		if(all[i] == 0){
			for(int j=0;j<buflen;j++) printf("#");
			printf("]100%\n");
			continue;
		}
		int num = buflen * finish[i] / all[i];
		for(int j=0;j<num;j++) printf("#");
		for(int j=0;j<buflen-num;j++) printf(".");
		printf("]%d%\n",100 * finish[i] / all[i]);
	}
	return 0;
}

