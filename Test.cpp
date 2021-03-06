// Взвешенный орграф, заданный списком смежности, найти максимальный путь между двумя вершинами.

#include "stdafx.h"
#include <conio.h>
#include "Graph.h"

using namespace std;



int main(void)
{
	graph graph_1, graph_2, graph_3, graph_4, graph_5;
	vector<int> longestPath;

	cout << "Graph 1:" << endl << endl;

	graph_1.add_edge(1, 2, 1);
	graph_1.add_edge(2, 3, 1);
	graph_1.add_edge(3, 7, 1);
	graph_1.add_edge(1, 4, 1);
	graph_1.add_edge(4, 5, 2);
	graph_1.add_edge(5, 6, 3);
	graph_1.add_edge(6, 7, 4);
	graph_1.add_edge(1, 7, 15);

	graph_1.print_list();

	graph_1.longest_path(1, 7);
	cout << endl << "The longest path from 1 to 7 is: ";
	graph_1.print_path();
	cout << "\nThe longest path length: " << graph_1.get_longest_path_length() << endl << endl;



	cout << "Graph 2:" << endl << endl;

	graph_2.add_edge(1, 2, 1);
	graph_2.add_edge(2, 3, 3);
	graph_2.add_edge(3, 4, 3);
	graph_2.add_edge(4, 5, 3);
	graph_2.add_edge(5, 2, 3);
	graph_2.add_edge(2, 6, 1);

	graph_2.print_list();

	graph_2.longest_path(1, 6);
	cout << endl << "The longest path from 1 to 6 is: ";
	graph_2.print_path();
	cout << "\nThe longest path length: " << graph_2.get_longest_path_length() << endl << endl;



	cout << "Graph 3:" << endl << endl;

	graph_3.add_edge(1, 1, 5);

	graph_3.print_list();

	graph_3.longest_path(1, 1);
	cout << endl << "The longest path from 1 to 1 is: ";
	graph_3.print_path();
	cout << "\nThe longest path length: " << graph_3.get_longest_path_length() << endl << endl;



	cout << "Graph 4:" << endl << endl;

	graph_4.add_edge(1, 2, 1);
	graph_4.add_edge(1, 3, 1);
	graph_4.add_edge(4, 2, 1);
	graph_4.add_edge(4, 3, 1);
	graph_4.add_edge(4, 1, 1);

	graph_4.print_list();

	graph_4.longest_path(1, 4);
	cout << endl << "The longest path from 1 to 4 is: ";
	graph_4.print_path();
	cout << "\nThe longest path length: " << graph_4.get_longest_path_length() << endl << endl;



	cout << "Graph 5:" << endl << endl;

	graph_5.add_edge(1, 2, 10);
	graph_5.add_edge(2, 3, 10);
	graph_5.add_edge(3, 4, 1);
	graph_5.add_edge(4, 5, 1);
	graph_5.add_edge(1, 6, 1);
	graph_5.add_edge(3, 9, 10);
	graph_5.add_edge(4, 9, 1);
	graph_5.add_edge(5, 10, 1);
	graph_5.add_edge(6, 7, 1);
	graph_5.add_edge(7, 8, 1);
	graph_5.add_edge(8, 9, 1);
	graph_5.add_edge(10, 9, 1);
	graph_5.add_edge(6, 11, 1);
	graph_5.add_edge(12, 6, 1);
	graph_5.add_edge(7, 13, 1);
	graph_5.add_edge(9, 13, 10);
	graph_5.add_edge(9, 14, 1);
	graph_5.add_edge(9, 15, 1);
	graph_5.add_edge(10, 15, 1);
	graph_5.add_edge(11, 12, 1);
	graph_5.add_edge(13, 12, 10);
	graph_5.add_edge(12, 16, 1);
	graph_5.add_edge(12, 18, 10);
	graph_5.add_edge(14, 20, 1);
	graph_5.add_edge(15, 20, 1);
	graph_5.add_edge(16, 17, 1);
	graph_5.add_edge(17, 18, 1);
	graph_5.add_edge(18, 19, 10);
	graph_5.add_edge(19, 20, 10);

	graph_5.print_list();

	graph_5.longest_path(1, 20);
	cout << endl << "The longest path from 1 to 20 is: ";
	graph_5.print_path();
	cout << "\nThe longest path length: " << graph_5.get_longest_path_length() << endl << endl;



	cout << "Press any key...";
	_getch();
	return 0;
}
