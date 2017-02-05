
const int T1 = 200;
const int Kp = 1;
int getNextPT1Value(const int x, const int tCycle, const int yPrev) {
	int X1, X2;
	int result;

	X1 = Kp * x * tCycle / T1;
	X2 = (yPrev - yPrev * tCycle / T1);

	result = X1 + X2;

	if (x >= yPrev && result >= x) {
		result = x;
	}

	return result;

}

int LPF_atom(const int input, const int N, const int y_prev) {
	int result;
	result = (((y_prev << N) - y_prev) + input) >> N;
	return result;
}

int LPF_1nd(const int input, const int N, const int y_prev) {
	return LPF_atom(input, N, y_prev);
}

int LPF_2nd(const int input, const int N, const int y_prev) {
	return LPF_atom(input, N, y_prev);
}