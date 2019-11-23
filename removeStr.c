#include <stdio.h>
#include <string.h>

char *removeStr(char *ptr, const char *p);

int main(void)
{
	char s1[] = "bugun pazartesi gunu";
	char s2[] = "ali 2345metin 2345";

	puts(removeStr(s1, "tesi")); // bugun pazar gunu
	puts(removeStr(s2, "2345")); //ali metin 2345

	return 0;
}

char *removeStr(char *ptr, const char *p)
{
	char *pch;
	unsigned int len = strlen(p);
	pch = strstr(ptr, p);
	if(pch)
	{
		strcpy(pch, pch + len);
	}
	return ptr;
}