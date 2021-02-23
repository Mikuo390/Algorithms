#define _CRT_SECURE_NO_WARNINGS

#define MAXLEN 255

typedef struct {
	//255+1 -> 0-255
	char ch[MAXLEN + 1];//存储串的一维数组
	int length;//串的当前长度
}SString;//S顺序+String字符串

//int Index_BF(SString S, SString T) {
//	int i = 1, j = 1;
//	while (i <= S.length && j <= T.length) {
//		if (S.ch[i] == T.ch[j]){
//			i++;
//			j++;//主串和子串一次匹配下一个字符
//		}
//		else {
//			i = i + j - 2;
//			j = 1;//主串，子串指针回溯重新开始下一次匹配
//		}
//		if (j >= T.length)
//			return i - T.length;//返回匹配的第一个字符的下标
//		else
//			return 0;//模式匹配不成功
//	}
//}

int Index_BF(SString S, SString T,int pos) {
	int i = pos, j = 1;
	while (i <= S.length && j <= T.length) {
		if (S.ch[i] == T.ch[j]){
			i++;
			j++;//主串和子串一次匹配下一个字符
		}
		else {
			i = i + j - 2;
			j = 1;//主串，子串指针回溯重新开始下一次匹配
		}
		if (j >= T.length)
			return i - T.length;//返回匹配的第一个字符的下标
		else
			return 0;//模式匹配不成功
	}
}
