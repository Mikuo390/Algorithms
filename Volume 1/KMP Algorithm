#define _CRT_SECURE_NO_WARNINGS

#define MAXLEN 255

typedef struct {
	//255+1 -> 0-255
	char ch[MAXLEN + 1];//存储串的一维数组
	int length;//串的当前长度
}SString;//S顺序+String字符串

int Index_KMP(SString S, SString T, int pos) {

	int i = pos, j = 1;
	while (i < S.length && j < T.length) {

		if (S.ch[i] == T.ch[j]) {
			i++;
			j++;//主串和子串一次匹配下一个字符
		}
		else
			j = next[j];//i不变，j后退

		if (j > T.length)
			return i - T.length;//返回匹配的第一个字符的下标
		else
			return 0;//模式匹配不成功

	}
}

void get_next(SString T, int& next[]) {

	int i = 1, j = 0;
	next[1] = 0;

	while (i < T.length) {
		if (j == 0 || T.ch[i] == T.ch[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

void get_next(SString T, int& nextval[]) {

	int i = 1, j = 0;
	nextval[1] = 0;

	while (i < T.length) {
		if (j == 0 || T.ch[i] == T.ch[j]) {
			i++;
			j++;
			if (T.ch[i] != T.ch[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
}
