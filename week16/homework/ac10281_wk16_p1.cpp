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

enum class Symbols
{
    OpenParan,
    OpenCurly,
    OpenBracket,
    OpenProgram,
};

bool isOpenSymbol(char& symbol);
bool isClosedSymbol(char& symbol);
bool isWhiteSpace(char& symbol);
void process_symbol(char& symbol, vector<char>& stack);

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

    char current_character;
    string current_token = "";
    while (pas_file.get(current_character))
    {
        if (!isWhiteSpace(current_character))
        {
            current_token += current_character;
            continue;
        }
        else
        {
            if (current_token == BEGIN_TOKEN)
            {
                stack.push_back(OPEN_BEGIN);
                break;
            }
            else
            {
                current_token = "";
            }
        }
    }
    current_token = "";

    while (pas_file.get(current_character))
    {
        if (isOpenSymbol(current_character))
        {
            stack.push_back(current_character);
            continue;
        }
        if (isWhiteSpace(current_character))
        {
            if (current_token == END_TOKEN)
            {
                if ((stack.size() == 1) && (stack[0] == CLOSED_END))
                {
                    cout << "Program is balanced!\n";
                    break;
                }
                else
                {
                    cout << "Error; end token has no matching begin token\n";
                    exit(1);
                }
            }

            current_token = "";
        }
    }
}

bool process_character(char current_character, vector<char>& stack)
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
            return false; 
        case CLOSED_PARAN:
            symbol = stack.back();
            stack.pop_back();
            if (symbol == OPEN_BRACKET)
                return true;
            return false; 
        case CLOSED_CURL:
            symbol = stack.back();
            stack.pop_back();
            if (symbol == OPEN_BRACKET)
                return true;
            return false; 
        default:
            return true;
    }

}

bool isOpenSymbol(char& symbol)
{
    return ((symbol == OPEN_BRACKET) ||
            (symbol == OPEN_PARAN) ||
            (symbol == OPEN_CURL));
}

bool isWhiteSpace(char& symbol)
{
    return ((symbol == SPACE) ||
            (symbol == TAB) ||
            (symbol == NEWLINE));
}

