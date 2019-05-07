class Topv
{
	public:
		int predecesor, finished, value;
		char state;
		Topv();
};

Topv::Topv() {
	this->predecesor = -1;
	this->finished = -1;
	this->state = 'u';
}

class Topological: public Adjecency_matrix
{
	public:
		Topv ** graphv;
		void init_graphv();
		~Topological();
		int * sorted, sorted_p;
};

void Topological::init_graphv() {
	sorted = new int [this->v_nr];
	sorted_p = this->v_nr - 1;
	this->graphv = new Topv * [this->v_nr];
	for (int i = 0; i < this->v_nr; i++) {
		this->graphv[i] = new Topv [this->v_nr];
	}
	for (int i = 0; i < this->v_nr; i++) {
		for (int j = 0; j < this->v_nr; j++) {
			this->graphv[i][j].value = this->graph[i][j];
		}
	}
}

Topological::~Topological() {
	if (this->graphv != NULL) {
		for (int i = 0; i < this->v_nr; i++) {
			delete [] this->graphv[i];
			this->graphv[i] = NULL;
		}
		delete [] this->graphv;
		this->graphv = NULL;
	}
	if (this->sorted != NULL) {
		delete [] this->sorted;
		sorted = NULL;
	}
}

