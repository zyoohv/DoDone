#include <stdio.h>

int states = -1, cnt = 0, tot = 0;
char buf[135][235];

void judg(char *str){
	if(str[0] == 'W' && str[1] == 'E' && str[2] == 'K') states = 0;
	if(str[0] == 'M' && str[1] == 'o' && str[2] == 'n') states = 1;
	if(str[0] == 'T' && str[1] == 'u' && str[2] == 'e') states = 2;
	if(str[0] == 'W' && str[1] == 'e' && str[2] == 'd') states = 3;
	if(str[0] == 'T' && str[1] == 'h' && str[2] == 'u') states = 4;
	if(str[0] == 'F' && str[1] == 'r' && str[2] == 'i') states = 5;
	if(str[0] == 'S' && str[1] == 'a' && str[2] == 't') states = 6;
	if(str[0] == 'S' && str[1] == 'u' && str[2] == 'n') states = 7;
}


int main(int argc, char *argv[]){
	FILE *fr, *fw;
	fr = freopen(argv[1], "r", stdin);
	while(gets(buf[cnt])) cnt++;
	fclose(fr);

	//for(int i=0;i<cnt;i++) printf("%s\n", buf[i]);

	int today;
	if(argv[3][0] == 'M' && argv[3][1] == 'o' && argv[3][2] == 'n') today = 1;
	if(argv[3][0] == 'T' && argv[3][1] == 'u' && argv[3][2] == 'e') today = 2;
	if(argv[3][0] == 'W' && argv[3][1] == 'e' && argv[3][2] == 'd') today = 3;
	if(argv[3][0] == 'T' && argv[3][1] == 'h' && argv[3][2] == 'u') today = 4;
	if(argv[3][0] == 'F' && argv[3][1] == 'r' && argv[3][2] == 'i') today = 5;
	if(argv[3][0] == 'S' && argv[3][1] == 'a' && argv[3][2] == 't') today = 6;
	if(argv[3][0] == 'S' && argv[3][1] == 'u' && argv[3][2] == 'n') today = 7;


	fw = freopen(argv[2], "w", stdout);

	for(int i=0;i<cnt;i++){
		judg(buf[i]);
		if(buf[i][0] < '0' || buf[i][0] > '9') continue;
		if(states == 0 || states == today){
			tot++;
			printf("%s\n", buf[i]);
		}
	}

	fclose(fw);

	int tmp;

	fr = freopen(argv[4], "r", stdin);
	fw = freopen(argv[4], "w", stdout);
	scanf("%d", &tmp);
	printf("%d", tmp + tot);
	fclose(fr);
	fclose(fw);

	fr = freopen(argv[5], "r", stdin);
	fw = freopen(argv[5], "w", stdout);
	scanf("%d", &tmp);
	printf("%d", tmp + tot);
	fclose(fr);
	fclose(fw);

	fr = freopen(argv[6], "r", stdin);
	fw = freopen(argv[6], "w", stdout);
	scanf("%d", &tmp);
	printf("%d", tmp + tot);
	fclose(fr);
	fclose(fw);

	return 0;
}
