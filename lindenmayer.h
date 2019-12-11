#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;





class lindenmayer
{
public:

	lindenmayer();

	void compute_generation();

	vector<char> current_data;

};


lindenmayer::lindenmayer()
{
	current_data.clear();

	current_data.push_back('a');

	cout << "a ";

}


void lindenmayer::compute_generation()
{
	vector<char> next_data;
	next_data.clear();

	for(char c : current_data)
	{
		switch(c)
		{
			case 'a':
				next_data.push_back('a');
				next_data.push_back('b');
				break;

			case 'b':
				next_data.push_back('b');
				next_data.push_back('a');
				break;


			default:
				break;
		}
	}

	current_data.clear();

	for(char c : next_data)
	{
		current_data.push_back(c);
		cout << c << " ";
	}

}
