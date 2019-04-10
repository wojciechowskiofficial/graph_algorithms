class Generator {
	public:
		Generator(int v_nr, float saturation);
		~Generator();
		int v_nr, e_nr;
		float saturation;
		int ** graph;
		bool ug, dag;
		void write_to_file();
};

Generator::Generator(int v_nr, float saturation) {
	this->v_nr = v_nr;
	this->e_nr = (int) (round(saturation * (v_nr * (v_nr - 1) / 2)));
	this->saturation = saturation;
	this->graph = new int * [this->v_nr];
	for (int i = 0; i < v_nr; i++) {
		this->graph[i] = new int [this->v_nr];
		for (int j = 0; j < v_nr; j++) {
			this->graph[i][j] = 0;
		}
	}
	this->ug = false;
	this->dag = false;
}

Generator::~Generator() {
	for (int i = 0; i < this->v_nr; i++) {
		delete [] this->graph[i];
		this->graph[i] = NULL;
	}
	delete [] this->graph;
	this->graph = NULL;
}

void Generator::write_to_file() {
	std::fstream out;
	std::string file_name;
	if (this->ug) {
		file_name = "UG_" + std::to_string(this->v_nr) + "_" + std::to_string(this->saturation) + ".txt";
	}
	else if (this->dag) {
		file_name = "DAG_" + std::to_string(this->v_nr) + "_" + std::to_string(this->saturation) + ".txt";
	}
	out.open(file_name, std::ios::out);
	out << this->v_nr << std::endl;
	out << this->e_nr << std::endl;
	out << "@" << std::endl;
	for (int i = 0; i < this->v_nr; i++) {
		for (int j = 0; j < this->v_nr; j++) {
			out << this->graph[i][j] << " ";
		}
		out << std::endl;
	}
	out.close();
}
