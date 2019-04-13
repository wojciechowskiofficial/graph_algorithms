class Edge {
	public:
		int a, b;
		void display();
};

void Edge::display() {
	std::cout << "(" << this->a << "-" << this->b << ")";
}
