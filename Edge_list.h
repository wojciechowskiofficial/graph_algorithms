class Edge_list: public Graph {
	public:
		Edge_list();
		~Edge_list();
		std::vector<Edge> graph;
		void read_from_file(std::string file_name);
		void display();
		bool is_edge(int a, int b);
};

Edge_list::Edge_list() {
	this->am = false;
	this->im = false;
	this->el = true;
	this->il = false;
}

Edge_list::~Edge_list() {
	std::vector<Edge>().swap(this->graph);
}

void Edge_list::read_from_file(std::string file_name) {
	std::fstream in;
	in.open(file_name, std::ios::in);
	in >> this->v_nr;
	in >> this->e_nr;
	char checkpoint;
	in >> checkpoint;
	if (checkpoint != '@') {
		std::cerr << "ivalid file format" << std::endl;
	}
	int tmp;
	for (int i = 0; i < this->v_nr; i++) {
		for (int j = 0; j < this->v_nr; j++) {
			in >> tmp;
			if (tmp == 1) {
				this->graph.push_back(Edge());
				this->graph.at(this->graph.size() - 1).a = i;
				this->graph.at(this->graph.size() - 1).b = j;
			}
		}
	}
	in.close();
}

void Edge_list::display() {
	for (int i = 0; i < this->graph.size(); i++) {
		this->graph.at(i).display();
		std::cout << std::endl;
	}
}

bool Edge_list::is_edge(int a, int b) {
	for (int i = 0; i < this->graph.size(); i++) {
		if (this->graph.at(i).a == a && this->graph.at(i).b == b) {
			return true;
		}
	}
	return false;
}
