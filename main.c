#include <stdio.h>
#include <stdlib.h>



const int N = 6;

int getNextPT1Value(const int x, const int tCycle, const int yPrev);
int LPF_atom(const int input, const int N, const int y_prev);
int LPF_1nd(const int input, const int N, const int y_prev);
int LPF_2nd(const int input, const int N, const int y_prev);

int task_count = 0;


int input = 1000;
int pt1_input = 0;
int LPF_1nd_Value = 0;
int LPF_2nd_Value = 0;

int main() {
	while (1) {
		if ((task_count % 10) == 0) {
			///input = rand() % 3000;
			pt1_input = getNextPT1Value(input, 10, pt1_input);
		}
		LPF_1nd_Value = LPF_1nd(pt1_input, N, LPF_1nd_Value);
		LPF_2nd_Value = LPF_2nd(LPF_1nd_Value, N, LPF_2nd_Value);
		printf("%d\t%d\t%d\t%d\n", input, pt1_input, LPF_1nd_Value, LPF_2nd_Value);
		task_count = (task_count + 1);
		if (task_count == 1000) return 0;
	}
	return 0;
}