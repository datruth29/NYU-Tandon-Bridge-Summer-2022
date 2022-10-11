#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <assert.h>

using namespace std;

class Organism;
class WorldState;

enum class OrgTypes
{
	TypeAnt,
	TypeDoodleBug
};
enum class Moves
{
	Up,
	Down,
	Left,
	Right
};
Moves get_random_move();
static vector<Moves> movements = { Moves::Up, Moves::Down, Moves::Left, Moves::Right };

struct CellInfo
{
	int x;
	int y;
	Organism* org;

	CellInfo(int x_pos, int y_pos)
		:x(x_pos), y(y_pos), org(nullptr)
	{

	}
	CellInfo(int x_pos, int y_pos, Organism* org)
		:x(x_pos), y(y_pos), org(org)
	{

	}
};

class Organism
{
public:
	int x_pos;
	int y_pos;
	int breed_timer;
	int breed_max;
	bool alive;
public:
	Organism();
	Organism(int x, int y);

	virtual void move(WorldState& world);
	virtual char symbol() const = 0;
	virtual void breed(WorldState& world) = 0;
	virtual OrgTypes get_type() const = 0;
	virtual void die() = 0;

};

class DoodleBug : public Organism
{
public:
	DoodleBug();
	DoodleBug(int x, int y);
	
	void move(WorldState& world) override;
	char symbol() const override;
	void breed(WorldState& world) override;
	OrgTypes get_type() const override;
	void die() override;

	void starve();
public:
	int starve_timer;
	int starve_max;
private:
	OrgTypes type = OrgTypes::TypeDoodleBug;
};

class Ant : public Organism
{
public:
	Ant();
	Ant(int x, int y);

	void move(WorldState& world) override;
	char symbol() const override;
	void breed(WorldState& world) override;
	void die() override;
	OrgTypes get_type() const override;

private:
	OrgTypes type = OrgTypes::TypeAnt;
};

class WorldState
{
public:
	int generation = 0;

public:
	WorldState();
	~WorldState();

	void display_world();
	void run();
	void take_next_step();
	bool is_empty_space(int x, int y) const;
	bool is_beyond_edge(int x, int y) const;
	bool is_space_available(int x, int y) const;
	vector<CellInfo> get_empty_spaces(int x, int y) const;
	vector<CellInfo> get_neighbor_spaces(int x, int y) const;
	void update_position(Organism* org, int prev_x, int prev_y);
	void add_organism(Organism* org);

private:
	static const unsigned int LENGTH = 20;
	static const unsigned int WIDTH = 20;
	static const int INITIAL_ANTS = 100;
	static const int INITIAL_DOODLEBUGS = 5;

	Organism* board[LENGTH][WIDTH];
	vector<Organism*> ants;
	vector<Organism*> doodlebugs;

};

int main()
{
	char wait;
	WorldState world;
	world.run();
	cin >> wait;
	return 0;
}

// Helper Functions
Moves get_random_move()
{
	int selection = rand() % movements.size();
	//cout << "Movement selection: " << selection << '\n';
	return movements[selection];
}

// WorldState Implementations
WorldState::WorldState()
{
	srand(static_cast<unsigned int>(time(0)));
	for (size_t i = 0; i < LENGTH; i++)
	{
		for (size_t j = 0; j < WIDTH; j++)
		{
			board[i][j] = nullptr;
		}
	}

	for (size_t i = 0; i < INITIAL_ANTS; i++)
	{

		bool selected = false;

		while (!selected)
		{
			int x = rand() % LENGTH;
			int y = rand() % WIDTH;

			if (is_empty_space(x, y))
			{
				Organism *temp = new Ant(x, y);
				board[x][y] = temp;
				ants.push_back(temp);
				selected = true;
			}
		}

	}

	for (size_t i = 0; i < INITIAL_DOODLEBUGS; i++)
	{
		bool selected = false;

		while (!selected)
		{
			int x = rand() % LENGTH;
			int y = rand() % WIDTH;

			if (is_empty_space(x, y))
			{
				Organism *temp = new DoodleBug(x, y);
				board[x][y] = temp;
				doodlebugs.push_back(temp);
				selected = true;
			}
		}

	}
}
WorldState::~WorldState()
{
	for (Organism* ant : ants)
	{
		delete ant;
	}
	ants.clear();

	for (Organism* doodlebug : doodlebugs)
	{
		delete doodlebug;
	}
	doodlebugs.clear();
}

void WorldState::display_world()
{
	cout << "\n\n";
	cout << "Generation: " << generation << "\n";
	for (size_t i = 0; i < LENGTH; i++)
	{
		for (size_t j = 0; j < WIDTH; j++)
		{
			char symbol;
			if (board[i][j] == nullptr)
				symbol = '-';
			else
				symbol = board[i][j]->symbol();

			cout << " " << symbol << " ";
		}
		cout << "\n";
	}
}

void WorldState::run()
{
	string command;
	while (true)
	{
		++generation;
		display_world();
		cout << "Enter a command: ";
		getline(cin, command);
		if (command == "e")
		{
			exit(0);
		}
		take_next_step();
	}
}

void WorldState::take_next_step()
{
	for (size_t i = 0; i < doodlebugs.size(); i++)
	{
		Organism* doodlebug = doodlebugs[i];

		if (!doodlebug->alive)
			continue;

		int prev_x = doodlebug->x_pos;
		int prev_y = doodlebug->y_pos;
		doodlebug->move(*this);
		if (doodlebug->x_pos != prev_x || doodlebug->y_pos != prev_y)
		{
			update_position(doodlebug, prev_x, prev_y);
		}
		doodlebug->breed(*this);
	}

	for (size_t i = 0; i < ants.size(); ++i)
	{
		Organism* ant = ants[i];
		if (!ant->alive)
			continue;
		int prev_x = ant->x_pos;
		int prev_y = ant->y_pos;
		ant->move(*this);
		if (ant->x_pos != prev_x || ant->y_pos != prev_y)
		{
			update_position(ant, prev_x, prev_y);
		}
		ant->breed(*this);
	}
}

void WorldState::update_position(Organism* org, int prev_x, int prev_y)
{
	int x = org->x_pos;
	int y = org->y_pos;
	assert(board[prev_x][prev_y] != nullptr);
	board[org->x_pos][org->y_pos] = org;
	board[prev_x][prev_y] = nullptr;
}

bool WorldState::is_empty_space(int x, int y) const
{
	return (board[x][y] == nullptr);
}

bool WorldState::is_beyond_edge(int x, int y) const
{
	return (x >= LENGTH || x < 0 || y >= WIDTH || y < 0);
}

bool WorldState::is_space_available(int x, int y) const
{
	return (is_empty_space(x, y) && !is_beyond_edge(x, y));
}

vector<CellInfo> WorldState::get_empty_spaces(int x, int y) const
{
	vector<CellInfo> cells;
	CellInfo up		= CellInfo(x, y - 1);
	CellInfo down	= CellInfo(x, y + 1);
	CellInfo left	= CellInfo(x - 1, y);
	CellInfo right	= CellInfo(x + 1, y);

	if (is_space_available(up.x, up.y)) cells.push_back(up);
	if (is_space_available(down.x, down.y)) cells.push_back(down);
	if (is_space_available(left.x, left.y)) cells.push_back(left);
	if (is_space_available(right.x, right.y)) cells.push_back(right);

	return cells;
}

vector<CellInfo> WorldState::get_neighbor_spaces(int x, int y) const
{
	vector<CellInfo> cells;
	CellInfo up		= CellInfo(x, y - 1);
	CellInfo down	= CellInfo(x, y + 1);
	CellInfo left	= CellInfo(x - 1, y);
	CellInfo right	= CellInfo(x + 1, y);

	if (!is_beyond_edge(up.x, up.y))
	{
		up.org = board[up.x][up.y];
		cells.push_back(up);
	}
	if (!is_beyond_edge(down.x, down.y))
	{
		down.org = board[down.x][down.y];
		cells.push_back(down);
	}
	if (!is_beyond_edge(left.x, left.y))
	{
		left.org = board[left.x][left.y];
		cells.push_back(left);
	}
	if (!is_beyond_edge(right.x, right.y))
	{
		right.org = board[right.x][right.y];
		cells.push_back(up);
	}

	return cells;

}

void WorldState::add_organism(Organism* org)
{
	assert(is_space_available(org->x_pos, org->y_pos) == true);
	board[org->x_pos][org->y_pos] = org;
	OrgTypes type = org->get_type();

	switch (type)
	{
	case OrgTypes::TypeAnt:
		ants.push_back(org);
		break;
	case OrgTypes::TypeDoodleBug:
		doodlebugs.push_back(org);
		break;
	}
}
// Organism Implementations
Organism::Organism()
	:x_pos(0), y_pos(0), breed_timer(0), breed_max(0), alive(true)
{

}
Organism::Organism(int x, int y)
	:x_pos(x), y_pos(y), breed_timer(0), breed_max(0), alive(true)
{

}

void Organism::move(WorldState& world)
{
	Moves move = get_random_move();
	int x = 0;
	int y = 0;

	switch (move)
	{
	case Moves::Up:
		y = -1;
		break;

	case Moves::Down:
		y = 1;
		break;

	case Moves::Right:
		x = 1;
		break;

	case Moves::Left:
		x = -1;
		break;

	default:
		break;

	}
	if (world.is_empty_space(x_pos + x, y_pos + y) && !world.is_beyond_edge(x_pos + x, y_pos + y))
	{
		x_pos += x;
		y_pos += y;
	}
	breed_timer++;
}

// Ant Implementations
Ant::Ant() :Organism()
{
	breed_max = 3;
}
Ant::Ant(int x, int y)
	:Organism(x, y)
{
	breed_max = 3;
}

void Ant::move(WorldState& world)
{
	Organism::move(world);
}
void Ant::breed(WorldState& world)
{
	if (breed_timer < breed_max)
		return;

	vector<CellInfo> open_cells = world.get_empty_spaces(x_pos, y_pos);
	
	if (open_cells.empty())
	{
		return;
	}

	CellInfo cell = open_cells.back();
	Organism* ant = new Ant(cell.x, cell.y);
	world.add_organism(ant);
	breed_timer = 0;
}
void Ant::die()
{
	x_pos = -1;
	y_pos = -1;
	alive = false;
}
char Ant::symbol() const 
{
	return 'o';
}
OrgTypes Ant::get_type() const 
{
	return type;
}

// DoodleBug Implmentations
DoodleBug::DoodleBug() :Organism()
{
	breed_max = 8;
	starve_timer = 0;
	starve_max = 3;
}
DoodleBug::DoodleBug(int x, int y)
	:Organism(x, y)
{
	breed_max = 8;
	starve_timer = 0;
	starve_max = 3;
}

void DoodleBug::move(WorldState& world) 
{
	vector<CellInfo> cells = world.get_neighbor_spaces(x_pos, y_pos);

	bool has_eaten = false;
	for (CellInfo& cell : cells)
	{
		if (cell.org == nullptr)
			continue;
		if (cell.org->get_type() == OrgTypes::TypeAnt)
		{
			world.update_position(this, cell.org->x_pos, cell.org->y_pos);
			x_pos = cell.org->x_pos;
			y_pos = cell.org->y_pos;
			cell.org->die();
			starve_timer = 0;
			breed_timer++;
			has_eaten = true;
			break;
		}
	}

	if (!has_eaten)
	{
		Organism::move(world);
		starve_timer++;
		if (starve_timer >= starve_max)
			die();
	}

}
void DoodleBug::breed(WorldState& world)
{
	if (breed_timer < breed_max)
		return;

	vector<CellInfo> open_cells = world.get_empty_spaces(x_pos, y_pos);
	
	if (open_cells.empty())
	{
		return;
	}

	CellInfo cell = open_cells.back();
	Organism* doodlebug = new DoodleBug(cell.x, cell.y);
	world.add_organism(doodlebug);
}
void DoodleBug::starve()
{

}
void DoodleBug::die()
{
	x_pos = -1;
	y_pos = -1;
	alive = false;

}

char DoodleBug::symbol() const 
{
	return 'X';
}

OrgTypes DoodleBug::get_type() const 
{
	return type;
}