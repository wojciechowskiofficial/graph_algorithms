void perform() {
	std::fstream out;
	out.open("output.txt", std::ios::out);
	Utility * utility = new Utility();
	int * a, * b, * c;
	clock_t begin, end;
	double elapsed = 0.0;

	//Adjecency matrix
	std::cout << "am" << std::endl;
	Adjecency_matrix * am;
	int count = 100;
	out << "Adjecency_matrix" << std::endl;
	for (int i = 0; i < 9; i++) {
		am = new Adjecency_matrix();
		a = new int [count * count];
		b = new int [count * count];
		c = new int [count * count];
		utility->fill(a, count, 1);
		utility->fill(b, count, 0);
		for (int j = 0; j < count * count; j++) {
			c[j] = j;
		}
		utility->shuffle(c, count * count);
		am->read_from_file(am->file_name_ass("ug", count, 0.6));

		for (int j = 0; j < count * count; j++) {
			begin = clock();
			am->is_edge(a[c[j]], b[c[j]]);
			end = clock();
			elapsed += double (end - begin) / CLOCKS_PER_SEC;
		}
		elapsed /= count;
		printf("%f\n", elapsed);
		out << elapsed << std::endl;


		delete am;
		am = NULL;
		delete [] a;
		a = NULL;
		delete [] b;
		b = NULL;
		delete [] c;
		c = NULL;
		elapsed = 0.0;
		count += 100;
	}

	/*
	//Edge_list
	std::cout << "el" << std::endl;
	Edge_list * el;
	count = 100;
	out << "Edge_list" << std::endl;
	for (int i = 0; i < 9; i++) {
		el = new Edge_list();
		a = new int [count * count];
		b = new int [count * count];
		c = new int [count * count];
		utility->fill(a, count, 1);
		utility->fill(b, count, 0);
		for (int j = 0; j < count * count; j++) {
			c[j] = j;
		}
		utility->shuffle(c, count * count);
		el->read_from_file(el->file_name_ass("ug", count, 0.6));

		std::cout << i << std::endl;
		for (int j = 0; j < count * count; j++) {
			//std::cout << "j: " << j << " count * count: " << count * count << std::endl;
			begin = clock();
			el->is_edge(a[c[j]], b[c[j]]);
			end = clock();
			elapsed += double (end - begin) / CLOCKS_PER_SEC;
		}
		elapsed /= count;
		printf("%f\n", elapsed);
		out << elapsed << std::endl;


		delete el;
		el = NULL;
		delete [] a;
		a = NULL;
		delete [] b;
		b = NULL;
		delete [] c;
		c = NULL;
		elapsed = 0.0;
		count += 100;
	}
	*/

	//Incidence_list
	std::cout << "il" << std::endl;
	Incidence_list * il;
	count = 100;
	out << "Incidence_list" << std::endl;
	for (int i = 0; i < 9; i++) {
		il = new Incidence_list();
		a = new int [count * count];
		b = new int [count * count];
		c = new int [count * count];
		utility->fill(a, count, 1);
		utility->fill(b, count, 0);
		for (int j = 0; j < count * count; j++) {
			c[j] = j;
		}
		utility->shuffle(c, count * count);
		il->read_from_file(il->file_name_ass("ug", count, 0.6));

		std::cout << i << std::endl;
		for (int j = 0; j < count * count; j++) {
			begin = clock();
			il->is_edge(a[c[j]], b[c[j]]);
			end = clock();
			elapsed += double (end - begin) / CLOCKS_PER_SEC;
		}
		elapsed /= count;
		printf("%f\n", elapsed);
		out << elapsed << std::endl;

		delete il;
		il = NULL;
		delete [] a;
		a = NULL;
		delete [] b;
		b = NULL;
		delete [] c;
		c = NULL;
		elapsed = 0.0;
		count += 100;
	}

	//Incidence_matrix
	std::cout << "im" << std::endl;
	Incidence_matrix * im;
	count = 100;
	out << "Incidence_matrix" << std::endl;
	for (int i = 0; i < 9; i++) {
		im = new Incidence_matrix();
		a = new int [count * count];
		b = new int [count * count];
		c = new int [count * count];
		utility->fill(a, count, 1);
		utility->fill(b, count, 0);
		for (int j = 0; j < count * count; j++) {
			c[j] = j;
		}
		utility->shuffle(c, count * count);
		begin = clock();
		im->read_from_file(im->file_name_ass("ug", count, 0.6));
		end = clock();
		printf("czytanie: %f\n", double (end - begin) / CLOCKS_PER_SEC);

		std::cout << i << std::endl;
		for (int j = 0; j < count * count; j++) {
			begin = clock();
			im->is_edge(a[c[j]], b[c[j]]);
			end = clock();
			elapsed += double (end - begin) / CLOCKS_PER_SEC;
		}
		elapsed /= count;
		printf("%f\n", elapsed);
		out << elapsed << std::endl;

		delete im;
		im = NULL;
		delete [] a;
		a = NULL;
		delete [] b;
		b = NULL;
		delete [] c;
		c = NULL;
		elapsed = 0.0;
		count += 100;
	}

	out.close();
	delete utility;
	utility = NULL;
}
