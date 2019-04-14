class Incidence_matrix: public Graph {
	public:
		Incidence_matrix();
		~Incidence_matrix();
		int ** graph;
		Edge ** e_vec;
		int find_edge(int a, int b);
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
	if (this->e_vec != NULL) {
		for (int i = 0; i < this->e_nr; i++) {
			delete this->e_vec[i];
			this->e_vec[i] = NULL;
		}
		delete [] this->e_vec;
		this->e_vec = NULL;
	}
	if (this->graph != NULL) {
		for (int i = 0; i < this->v_nr; i++) {
			delete [] this->graph[i];
			this->graph[i] = NULL;
		}
		delete [] this->graph;
		this->graph = NULL;
	}
}

int Incidence_matrix::find_edge(int a, int b) {
	for (int i = 0; i < this->e_nr; i++) {
		if (this->e_vec[i]->a == a && this->e_vec[i]->b == b) {
			return i;
		}
	}
	return -1;
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
	this->e_vec = new Edge * [this->e_nr];
	for (int i = 0; i < this->e_nr; i++) {
		this->e_vec[i] = new Edge();
		e_vec[i]->a = -1;
		e_vec[i]->b = -1;
	}
	int tmp, counter = 0;
	for (int i = 0; i < this->v_nr; i++) {
		for (int j = 0; j < this->v_nr; j++) {
			in >> tmp;
			if (tmp == 1) {
				if (this->find_edge(i, j) == -1 && this->find_edge(j, i) == -1) {
					this->e_vec[counter]->a = i;
					this->e_vec[counter]->b = j;
					this->graph[i][this->find_edge(i, j)] = 1;
					if (file_name[0] == 'U') {
						this->graph[j][this->find_edge(i, j)] = 1;
					}
					else if (file_name[0] == 'D') {
						this->graph[j][this->find_edge(i, j)] = -1;
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
	for (int i = 0; i < this->e_nr; i++) {
		this->e_vec[i]->display();
		std::cout << " ";
	}
	std::cout << std::endl;
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
	int anwser;
	anwser = this->find_edge(a, b);
	if (anwser == -1) {
		return false;
	}
	else {
		return true;
	}
}
