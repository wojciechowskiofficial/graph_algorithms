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
		Topv * topv_list;
		void init_topv_list();
		~Topological();
		int * sorted, sorted_p;
};

void Topological::init_topv_list() {
	sorted = new int [this->v_nr];
	sorted_p = this->v_nr - 1;
	this->topv_list = new Topv [this->v_nr];
	for (int i = 0; i < this->v_nr; i++) {
		this->topv_list[i].value = i;
	}
}

Topological::~Topological() {
	if (this->topv_list != NULL) {
		delete [] this->topv_list;
		this->topv_list = NULL;
	}
	if (this->sorted != NULL) {
		delete [] this->sorted;
		sorted = NULL;
	}
}

