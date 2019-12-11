#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

/*

	Three vectors represent the turtle:

		heading: initialized to glm::vec3( 0, 1, 0)
		up:			 initialized to glm::vec3( 0, 0,-1)
		left:		 initialized to glm::vec3(-1, 0, 0)

	We maintian state variables for:

		pen up/pen down
		thickness of the line being drawn
		location of turtle (translated to keep up with state)
		orientation of turtle (heading, up, and left, but rotated to keep up with state)



	The recognized set of symbols:

		+: 			turn left by some amount, by rotating a negative amount about the up vector
		-: 			turn right by some amount, by rotating a positive amount about the up vector

		&:			pitch down, by rotating a positive amount about the left vector
		^:			pitch up, by rotating a negative amount about the left vector

		\:			roll left, by rotating a positive amount about the heading vector
		/:			roll right, by rotating a negative amount about the heading vector

		|:			turn around, by rotating 180 degrees about the up vector

		[:			push current position, heading, up, and left vectors, as well as any other state variables, onto the stack
		]:			pop state variables off of the stack

		T:			the line becomes thicker
		t:			the line becomes thinner

		F:			go forward, along heading


		think about:
			step length longer/shorter	-> this is stupid, just F->FF style rules
			pen up/pen down

*/







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
