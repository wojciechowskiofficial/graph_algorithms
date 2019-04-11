class Graph {
	public:
		int v_nr, e_nr;
		bool am, im, el, il;
		std::string file_name_ass(std::string type, int v_nr, float saturation);
};

std::string Graph::file_name_ass(std::string type, int v_nr, float saturation) {
	if (type == "ug") {
		type = "UG_";
	}
	else if (type == "dag") {
		type = "DAG_";
	}
	std::string anwser = "";
	anwser += type;
	anwser += std::to_string(v_nr) + "_" + std::to_string((int)(round(saturation * 100))) + ".txt";
	return anwser;
}
