class Utility {
	public:
		void shuffle(int * a, int s);
		void fill(int * a, int s, bool flag);
};

void Utility::shuffle(int * a, int s) {
	srand(time(NULL));
	for (int i = s - 1; i > 0; i--) {
		std::swap(a[i], a[rand() % (i + 1)]);
	}
}

void Utility::fill(int * a, int squared, bool flag) {
	int counter = 0;
	if (flag) {
		for (int i = 0; i < squared; i++) {
			for (int j = 0; j < squared; j++) {
				a[counter++] = j;
			}
		}
	}
	else {
		for (int i = 0; i < squared; i++) {
			for (int j = 0; j < squared; j++) {
				a[counter++] = i;
			}
		}
	}
}
