class Topv
{
	public:
		int predecesor, f, d, value;
		char state;
		Topv();
};

Topv::Topv() {
	this->predecesor = -1;
	this->f = -1;
	this->d = -1;
	this->state = 'u';
}

class Topological: public Adjecency_matrix
{
	public:
		Topv * topv_list;
		void init_topv_list();
		~Topological();
		int * sorted, sorted_p, time;
		void dfs();
		void dfs_visit(int to_visit);
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


void Topological::dfs() {
	time = 0;
	for (int i = 0; i < this->v_nr; i++) {
		if (this->topv_list[i].state == 'u') {
			this->dfs_visit(i);
		}
	}
}

void Topological::dfs_visit(int to_visit) {
	this->time++;
	this->topv_list[to_visit].d = time;
	this->topv_list[to_visit].state = 'v';
	for (int i = 0; i < this->v_nr; i++) {
		if (this->graph[to_visit][i] == 1) {
			if (this->topv_list[i].state == 'u') {
				this->topv_list[i].predecesor = to_visit;
				this->dfs_visit(i);
			}
		}
	}
	this->time++;
	this->topv_list[to_visit].f = time;
	this->sorted[this->sorted_p--] = to_visit;
}
