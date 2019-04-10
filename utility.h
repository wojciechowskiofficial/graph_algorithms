void shuffle(int * a, int s) {
	srand(time(NULL));
	for (int i = s - 1; i > 0; i--) {
		std::swap(a[i], a[rand() % (i + 1)]);
	}
}
