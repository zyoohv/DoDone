#include <stdio.h>
#include <string.h>

#define delnum 38

char tmp[20][101];


int main(int argc, char *argv[]){
	freopen(argv[1],"r",stdin);
	int cnt = 0;
	while(gets(tmp[cnt])) cnt++;

	if(argc == 3){
		int len = strlen(argv[2]);
		int del = 0;
		int flag = 0;
		for(int i=0;i<len;i++){
			if(argv[2][i] < '0' || argv[2][i] > '9'){
				flag = 1;
				break;
			}
			del *= 10;
			del += argv[2][i] - '0';
			if(del > cnt){
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			printf("error");
			return 0;
		}
		tmp[del-1][0] = delnum;
	}
	for(int i=0;i<cnt;i++)if(tmp[i][0] == delnum){
		int nex = i + 1;
		for(;nex < cnt;nex++)if(tmp[nex][0] != delnum) break;
		if(nex >= cnt) break;
		for(int j=0;j<101;j++){
			char sw = tmp[i][j];
			tmp[i][j] = tmp[nex][j];
			tmp[nex][j] = sw;
		}
	}
	for(int i=0;i<cnt;i++){
		if(tmp[i][0] != delnum) tmp[i][0] = '1' + i;
		else break;	
	}
	freopen(argv[1],"w",stdout);
	for(int i=0;i<cnt;i++) printf("%s\n",tmp[i]);
	return 0;
}
