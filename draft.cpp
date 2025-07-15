struct Turing_Machine
{
	virtual bool test_string(const std::string& input) = 0;
};

class One_Tape_Turing_Machine : public Turing_Machine
{
public:
	bool test_string(const std::string& input)
	{
		if(current() == BLANK)
		{
			return ACCEPT;
		}
		else if(current() == ZERO)
		{
			mark_x();
			go_right();
			search_for_one();
		}
		else if(current() == Y)
		{
			look_for_remaining_numbers();
		}
		else
		{
			return REJECT;
		}
	}

private:
	bool search_for_one()
	{
		if(current() == ONE)
		{
			mark_y();
			go_right();
			search_for_two();
		}
		else if(current() == ZERO || current() == Y)
		{
			go_right();
		}
		else
		{
			return REJECT;
		}
	}

	bool search_for_two()
	{
		if(current() == TWO)
		{
			mark_z();
			go_back();
		}
		else if(current() == ONE || current() == Z)
		{
			go_right();
		}
		else
		{
			return REJECT;
		}
	}

	bool look_for_remaining_numbers()
	{
		if(current() == Y || current() == Z)
		{
			go_right();
		}
		else if(current() == BLANK)
		{
			return ACCEPT;
		}
		else
		{
			return REJECT;
		}
	}

	void go_back()
	{
		while(current() != X)
		{
			go_left();
		}

		go_right();
	}

	inline char current() const
	{
		return tape[cursor];
	}

private:
	std::vector<char> tape;
	size_t cursor;
};

bool match(Turing_Machine& machine, const std::string& input)
{
	return machine.test_string(input);
}


auto tests = {
	{"", true},
	{"012", true},
	{"001122", true},
	{"000111222", true},
	{"0122", false},
	{"0112", false},
	{"0012", false},
	{"01122", false},
	{"00122", false},
	{"00112", false},
	{"0011222", false},
	{"0011122", false},
	{"0001122", false},
	{"00111222", false},
	{"00011222", false},
	{"00011122", false},
	{"011222", false},
	{"011122", false},
	{"001222", false},
	{"001112", false},
	{"000112", false},
	{"000122", false},
	{"001112222", false},
	{"001111222", false},
	{"000112222", false},
	{"000111122", false},
	{"000011122", false},
	{"000011222", false},
	{"122", false},
	{"112", false},
	{"12", false},
	{"1122", false},
	{"11222", false},
	{"11122", false},
	{"111222", false},
	{"1222", false},
	{"1112", false},
	{"1112222", false},
	{"1111222", false},
	{"112222", false},
	{"111122", false},
	{"022", false},
	{"02", false},
	{"002", false},
	{"0022", false},
	{"00222", false},
	{"00022", false},
	{"000222", false},
	{"0222", false},
	{"0002", false},
	{"002222", false},
	{"0002222", false},
	{"000022", false},
	{"0000222", false},
	{"01", false},
	{"011", false},
	{"001", false},
	{"0011", false},
	{"00111", false},
	{"00011", false},
	{"000111", false},
	{"0111", false},
	{"0001", false},
	{"001111", false},
	{"0001111", false},
	{"0000111", false},
	{"000011", false},
	{"2", false},
	{"22", false},
	{"222", false},
	{"2222", false},
	{"1", false},
	{"11", false},
	{"111", false},
	{"1111", false},
	{"0", false},
	{"00", false},
	{"000", false},
	{"0000", false},
};
