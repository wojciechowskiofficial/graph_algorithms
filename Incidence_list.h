class Incidence_list: public Graph {
	public:
		Incidence_list();
		~Incidence_list();
		std::vector<int> * graph;
		void read_from_file(std::string file_name);
		void display();
		bool is_edge(int a, int b);
};

Incidence_list::Incidence_list() {
	this->am = false;
	this->im = false;
	this->el = false;
	this->il = true;
	this->graph = NULL;
}

Incidence_list::~Incidence_list() {
	if (this->graph != NULL) {
		for (int i = 0; i < this->v_nr; i++) {
			std::vector<int>().swap(this->graph[i]);
		}
		delete [] this->graph;
		this->graph = NULL;
	}
}

void Incidence_list::read_from_file(std::string file_name) {
	std::fstream in;
	in.open(file_name, std::ios::in);
	in >> this->v_nr;
	in >> this->e_nr;
	char checkpoint;
	in >> checkpoint;
	if (checkpoint != '@') {
		std::cerr << "invalid file format" << std::endl;
	}
	this->graph = new std::vector<int> [this->v_nr];
	int tmp;
	for (int i = 0; i < this->v_nr; i++) {
		for (int j = 0; j < this->v_nr; j++) {
			in >> tmp;
			if (tmp == 1) {
				this->graph[i].push_back(j);
			}
		}
	}
	in >> checkpoint;
	if (checkpoint != '$') {
		std::cerr << "invalid file format" << std::endl;
	}
	in.close();
}

void Incidence_list::display() {
	for (int i = 0; i < this->v_nr; i++) {
		std::cout << i << ": ";
		for (int j = 0; j < this->graph[i].size(); j++) {
			std::cout << this->graph[i].at(j) << " ";
		}
		std::cout << std::endl;
	}
}

bool Incidence_list::is_edge(int a, int b) {
	return std::find(this->graph[a].begin(), this->graph[a].end(), b) != this->graph[a].end();
}
