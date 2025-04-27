#include<stdio.h>
#include<math.h>

void main(void)
{
	int a;
	int b;
	int c;

	if (scanf("%d %d %d", &a, &b, &c))
	{
		float constant = -((float)b) / (2 * a);
		int root = (int)pow(b, 2) - (4 * a * c);
		if (constant == -0)
		{
			constant = 0;
		}
		if (root > 0)
		{
			printf("%.2f\n", constant + (sqrt(root) / (2 * a)));
			printf("%.2f", constant - (sqrt(root) / (2 * a)));
		}
		else if (root < 0)
		{
			printf("%.2f+%.2fi\n", constant, sqrt(abs(root)) / abs((2 * a)));
			printf("%.2f-%.2fi", constant, sqrt(abs(root)) / abs((2 * a)));
		}
		else
		{
			printf("%.2f", constant);
		}

	}
}