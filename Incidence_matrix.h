class Incidence_matrix: public Graph {
	public:
		Incidence_matrix();
		~Incidence_matrix();
		int ** graph;
		void display();
		void read_from_file(std::string file_name);
		bool is_edge(int a, int b);
};

Incidence_matrix::Incidence_matrix() {
	this->am = false;
	this->im = true;
	this->el = false;
	this->il = false;
	this->graph = NULL;
}

Incidence_matrix::~Incidence_matrix() {
	if (this->graph != NULL) {
		for (int i = 0; i < this->v_nr; i++) {
			delete [] this->graph[i];
			this->graph[i] = NULL;
		}
		delete [] this->graph;
		this->graph = NULL;
	}
}

void Incidence_matrix::read_from_file(std::string file_name) {
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
		this->graph[i] = new int [this->e_nr];
		for (int j = 0; j < this->e_nr; j++) {
			this->graph[i][j] = 0;
		}
	}

	int tmp, counter = 0;
	for (int i = 0; i < this->v_nr; i++) {
		for (int j = 0; j < this->v_nr; j++) {
			in >> tmp;
			if (tmp == 1) {
				if (this->is_edge(i, j) == false && this->is_edge(j, i) == false) {
					this->graph[i][counter] = 1;
					if (file_name[0] == 'U') {
						this->graph[j][counter] = 1;
					}
					else if (file_name[0] == 'D') {
						this->graph[j][counter] = -1;
					}
					counter++;
				}
			}
		}
	}
	in >> checkpoint;
	if (checkpoint != '$') {
		std::cerr << "invalid file format" << std::endl;
	}
	in.close();
}

void Incidence_matrix::display() {
	for (int i = 0; i < this->v_nr; i++) {
		for (int j = 0; j < this->e_nr; j++) {
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

bool Incidence_matrix::is_edge(int a, int b) {
	if (a == b) {
		return false;
	}
	for (int i = 0; i < this->e_nr; i++) {
		if (this->graph[a][i] != 0 && this->graph[b][i] != 0) {
			return true;
		}
	}
	return false;
}
