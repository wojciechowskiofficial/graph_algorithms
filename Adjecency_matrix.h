class Adjecency_matrix: public Graph {
	public:
		Adjecency_matrix();
		~Adjecency_matrix();
		void read_from_file(std::string file_name);
		bool is_edge(int a, int b);
		void display();
		int ** graph;
};

Adjecency_matrix::Adjecency_matrix() {
	this->am = 1;
	this->im = 0;
	this->el = 0;
	this->il = 0;
	this->graph = NULL;
}

Adjecency_matrix::~Adjecency_matrix() {
	if (this->graph != NULL) {
		for (int i = 0; i < this->v_nr; i++) {
			if (this->graph[i] != NULL) {
				delete [] this->graph[i];
				this->graph[i] = NULL;
			}
		}
		delete [] this->graph;
		this->graph = NULL;
	}
}

void Adjecency_matrix::read_from_file(std::string file_name) {
	std::fstream in;
	in.open(file_name, std::ios::in);
	in >> this->v_nr;
	in >> this->e_nr;
	char checkpoint;
	in >> checkpoint;
	if (checkpoint != '@') {
		std::cerr << "invalid file format" << std::endl;
	}
	this->graph = new int * [this->v_nr];
	for (int i = 0; i < this->v_nr; i++) {
		this->graph[i] = new int [this->v_nr];
		for (int j = 0; j < this->v_nr; j++) {
			this->graph[i][j] = 0;
		}
	}

	int tmp;
	for (int i = 0; i < this->v_nr; i++) {
		for (int j = 0; j < this->v_nr; j++) {
			in >> tmp;
			this->graph[i][j] = tmp;
		}
	}
	in >> checkpoint;
	if (checkpoint != '$') {
		std::cerr << "invalid file format" << std::endl;
	}
	in.close();

}

void Adjecency_matrix::display() {
	for (int i = 0; i < this->v_nr; i++) {
		for (int j = 0; j < this->v_nr; j++) {
			if (this->graph[i][j] == -1) {
				std::cout << this->graph[i][j] << " ";
			}
			else {
				std::cout << " " << this->graph[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
}

bool Adjecency_matrix::is_edge(int a, int b) {
	if (this->graph[a][b] == 1 || this->graph[a][b] == -1) return true;
	else return false;
}
