#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

const string    BEGIN_TOKEN     = "begin";
const string    END_TOKEN       = "end";
const char      OPEN_BEGIN      = 'B';
const char      CLOSED_END      = 'E';
const char      OPEN_PARAN      = '(';
const char      CLOSED_PARAN    = ')';
const char      OPEN_BRACKET    = '[';
const char      CLOSED_BRACKET  = ']';
const char      OPEN_CURL       = '{';
const char      CLOSED_CURL     = '}';
const char      SPACE           = ' ';
const char      TAB             = '\t';
const char      NEWLINE         = '\n';

bool isWhiteSpace(char& symbol);
bool process_character(char& symbol, vector<char>& stack);
bool balance_checker(ifstream& data_file, vector<char>&stack);

int main()
{
    vector<char> stack;
    ifstream pas_file;

    pas_file.open("test.pas");

    if (pas_file.fail())
    {
        cout << "Error opening file.";
        exit(1);
    }

    if (balance_checker(pas_file, stack))
    {
        cout << "Symbols are balanced!\n";
    }
    else
    {
        cout << "Symbols are NOT balanced!\n";
    }
    pas_file.close();

}

bool balance_checker(ifstream &data_file, vector<char> &stack)
{
    char current_character;
    string token = "";
    bool found_begin = false;
    while (data_file.get(current_character))
    {
		if (isWhiteSpace(current_character) || data_file.eof())
		{
			if (found_begin && (token == END_TOKEN))
			{
				if ((stack.size() == 1) &&
					(stack.back() == OPEN_BEGIN))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if (!found_begin && (token == BEGIN_TOKEN))
			{
				stack.push_back(OPEN_BEGIN);
				found_begin = true;
			}
			else
			{
				token = "";
			}
			continue;
		}

        token += current_character;
        if (!process_character(current_character, stack))
        {
            return false;
        }
    }

    // This section of code is reached if end doesn't have a space after it;
    if (data_file.eof())
    {
        if (token == END_TOKEN)
        {
			if ((stack.size() == 1) &&
				(stack.back() == OPEN_BEGIN))
			{
				return true;
			}
			else
			{
				return false;
			}
        }
		else
		{
			cout << "Error: No End Token found.\n";
			return false;
		}
    }
    else
    {
        // This REALLY shouldn't happen!
        cout << "Error: Came out of while loop, but not at end of file.\n";
        exit(1);
    }
}

bool process_character(char& current_character, vector<char>& stack)
{
    char symbol;
    switch(current_character)
    {
        case OPEN_BRACKET:
        case OPEN_PARAN:
        case OPEN_CURL:
            stack.push_back(current_character);
            return true;
        case CLOSED_BRACKET:
            symbol = stack.back();
            stack.pop_back();
            if (symbol == OPEN_BRACKET)
                return true;
            cout << "Error: Last item on stack: " << symbol << '\n';
            return false; 
        case CLOSED_PARAN:
            symbol = stack.back();
            stack.pop_back();
            if (symbol == OPEN_PARAN)
                return true;
            cout << "Error: Last item on stack: " << symbol << '\n';
            return false; 
        case CLOSED_CURL:
            symbol = stack.back();
            stack.pop_back();
            if (symbol == OPEN_CURL)
                return true;
            cout << "Error: Last item on stack: " << symbol << '\n';
            return false; 
        default:
            return true;
    }
}

bool isWhiteSpace(char& symbol)
{
    return ((symbol == SPACE) ||
            (symbol == TAB) ||
            (symbol == NEWLINE));
}
