#include <iostream>
#include <vector>
#include <stack>
#include <random>
#include <iomanip>
#include <fstream>
#include <algorithm>


#define GLM_FORCE_SWIZZLE
#define GLM_SWIZZLE_XYZW
#include "glm/glm.hpp" //general vector types
#include "glm/gtc/matrix_transform.hpp" // for glm::ortho
#include "glm/gtc/type_ptr.hpp" //to send matricies gpu-side
#include "glm/gtx/transform.hpp"


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



		the increment in now specified as 30 degrees

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

		T:			the line becomes thicker	//maybe not this
		t:			the line becomes thinner


		f:			go forward, along heading
		F:			go forward, along heading (thicker)
		1:			go forward, along heading (thicker)
		2:			go forward, along heading (thicker)
		3:			go forward, along heading (thicker)
		4:			go forward, along heading (thicker)
		5:			go forward, along heading (thicker)
		6:			go forward, along heading (thicker)
		7:			go forward, along heading (thicker)
		8:			go forward, along heading (thicker)


		think about:
			step length longer/shorter	-> this is stupid, just F->FF style rules
			pen up/pen down

*/







class lindenmayer
{
public:

	lindenmayer();

	void compute_generation();
	void list_out();

	void interpret();

	vector<char> current_data;

};


lindenmayer::lindenmayer()
{
	current_data.clear();

	current_data.push_back('f');

}


void lindenmayer::list_out()
{
	for(char c : current_data)
	{
		cout << c << " ";
	}
}


void lindenmayer::interpret()
{

	typedef struct state_t
	{
		glm::vec3 location;
		glm::vec3 heading;
		glm::vec3 left;
		glm::vec3 up;
	} state;

	state current_state;

	std::ofstream file;
	file.open (std::string("V.txt").c_str());

	std::stack<state> statestack;

	for(char c : current_data)
	{
		switch(c)
		{
			case '[':
				statestack.push(current_state);
				cout << c << " ";
				break;

			case ']':
				current_state = statestack.top();
				statestack.pop();
				cout << c << " ";
				break;

			default:
				break;
		}
	}





}

void lindenmayer::compute_generation()
{
	vector<char> next_data;
	next_data.clear();

	for(char c : current_data)
	{
		switch(c)
		{
			case 'f':
				next_data.push_back('F');

				next_data.push_back('[');
				next_data.push_back('[');
				next_data.push_back('[');

				next_data.push_back(']');

				next_data.push_back('/');
				next_data.push_back('/');
				next_data.push_back('/');
				next_data.push_back('/');

				next_data.push_back('&');
				next_data.push_back('f');


				next_data.push_back(']');

				next_data.push_back('/');
				next_data.push_back('/');
				next_data.push_back('/');
				next_data.push_back('/');

				next_data.push_back('/');
				next_data.push_back('/');
				next_data.push_back('/');
				next_data.push_back('/');

				next_data.push_back('&');
				next_data.push_back('f');


				next_data.push_back(']');

				next_data.push_back('/');
				next_data.push_back('/');
				next_data.push_back('/');
				next_data.push_back('/');

				next_data.push_back('/');
				next_data.push_back('/');
				next_data.push_back('/');
				next_data.push_back('/');

				next_data.push_back('/');
				next_data.push_back('/');
				next_data.push_back('/');
				next_data.push_back('/');

				next_data.push_back('&');
				next_data.push_back('f');
				break;

			case 'F':
				next_data.push_back('1');
				next_data.push_back('1');
				break;

			case '1':
				next_data.push_back('2');
				next_data.push_back('2');
				break;

			case '2':
				next_data.push_back('3');
				next_data.push_back('3');
				break;

			case '3':
				next_data.push_back('4');
				next_data.push_back('4');
				break;

			case '4':
				next_data.push_back('5');
				next_data.push_back('5');
				break;

			case '5':
				next_data.push_back('6');
				next_data.push_back('6');
				break;

			case '6':
				next_data.push_back('7');
				break;

			case '7':
				next_data.push_back('8');
				break;

			case '8':
				next_data.push_back('8');
				break;

			default:
				break;
		}
	}

	current_data.clear();

	for(char c : next_data)
	{
		current_data.push_back(c);
	}

}
