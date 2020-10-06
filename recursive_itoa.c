#include <stdio.h>

void reverse(char s[], int n)
{

	static int i = 0;
	int j = n - (i + 1);
	int temp;
	if (i < j)
	{

		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
		reverse(s, n);
	}
}
void recursive_itoa(char s[], int n)
{
	static int i = 0;
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n != 0)
	{
		s[i] = (n % 10) + '0';
		i++;
		n = n / 10;
		recursive_itoa(s, n);
	}
	else
	{
		s[i] = '\0';
		reverse(s, i);
	}
}
int main()
{
	char s[10] = {'\0'};
	int n = 0;
	printf("Enter the number\n");
	scanf("%d", &n);
	recursive_itoa(s, n);
	for (int i = 0; s[i] != '\0'; i++)
	{
		printf("%d ", s[i]);
	}
	return 0;
}