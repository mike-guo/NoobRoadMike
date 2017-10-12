#include <iostream>

int x[1024] = { 0 };	// x[]���ڴ洢��
int total = 0;			// total���ڼ�����ֵķ�����

void splitN(int n, int m) {		//n����Ҫ��ֵ�����m�ǲ�ֵĽ���
	int rest, i, j;
	for (i = 1; i <= n; i++) {	//��1��ʼ���Բ��
		if (i >= x[m - 1]) {		//��ֵ������ڻ����ǰһ���Ӷ���֤���ظ�
			x[m] = i;			// ���������������
			rest = n - i;		// ʣ�µ�����n-i������Ѿ�û��ʣ�µ��ˣ����ҽ���(�ܵĲ�ָ���)����1��˵���Ѿ��õ�һ�������
			if (rest == 0 && m > 1) {
				total++;
				printf("%d\t", total);
				for(j = 1; j < m; j++) {
					printf("%d+", x[j]);
				}
				printf("%d ", x[m]);
				printf("\n");
			} else {
				splitN(rest, m + 1);  // ����ʣ�µ������н���Ϊm+1���
			}
			x[m] = 0;			// ȡ�����ν����������һ�β�֡������ָ���������
		}
	}
}

void SplitLittleInt_test() {
	int n ;
	printf("Please input the natural number n:");
	scanf("%d", &n);
	total = 0;
	memset(x, 0, 1024);
	splitN(n, 1);
	printf("There are %d ways to split natural number %d. \n", total, n);
}