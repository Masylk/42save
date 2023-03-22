#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : data()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) : data(cpy.data)
{
    *this = cpy;
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    (void)rhs;
    return *this;
}

int     BitcoinExchange::check_open(const std::ifstream &file) const
{
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file.";
        return 1;
    }
    if (file.fail())
    {
        std::cerr << "Error: could not open file.";
        return 1;
    }
    return 0;
}

void    BitcoinExchange::db_display() const
{
    for (std::vector<std::vector<std::string> >::const_iterator it = data.begin(); it != data.end(); ++it) {
        const std::vector<std::string>& row = *it;
        for (std::vector<std::string>::const_iterator it = row.begin(); it != row.end(); ++it) {
            const std::string& cell = *it;

            std::cout << cell << ",";
        }
        std::cout << std::endl;
    }
}

std::string     find_rate(const std::string &date)
{
    std::string res;

    (void)date;
    return res;
}

int     BitcoinExchange::check_date(const std::string &date) const
{
    std::vector<std::string> year_month_day = split(date, "-");
    
    if (year_month_day.size() != 3)
        return 1;
    float   month = std::atof(year_month_day[1].c_str());
    float   day = std::atof(year_month_day[2].c_str());

    if (date.length() != 10)
        return 1;
    else if (day < 0 || day > 31 || month < 0 || month > 12)
        return 1;
    return 0;
}

int     BitcoinExchange::setup(const char *filename)
{
    std::ifstream input(filename);
    
    if (check_open(input))
        return 1;

    //db_display();
    parseInput(input);
    return 0;
}

void    BitcoinExchange::parseInput(std::ifstream &input)
{
    std::vector<std::string>    content;
    std::vector<std::string> values;

    std::string data((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
    if (data.length() == 0)
    {
        return ;
    }
	input.close();

    content = split(data, "\n");
    if (content.size() == 0)
    {
        return ;
    }
    data.append("\0");
    for (size_t i = 1; i < content.size(); i++)
    {
        values = split(content[i], " |");
         // Check the format of the file "date | value"
        //data format : Y-M-D | valid value : a int or float between 0-1000
        if (values.size() != 2)
            output.push_back("Error: bad input => " + content[i]);
        else if (check_date(values[0]))
            output.push_back("Error: bad date format => " + content[i]);
        else if (std::atof(values[1].c_str()) > 1000)
            output.push_back("Error: too large a number");
        else if (std::atof(values[1].c_str()) < 0)
            output.push_back("Error: not a positive number");
        else if (values[1] != "0" && std::atof(values[1].c_str()) == 0)
            output.push_back("Error: value is not a number => " + content[i]);
        else
            output.push_back(getExchangeRate(values[0], std::atof(values[1].c_str())));
    }
}

bool	ft_in_delim(const char c, const char *delimiter)
{
	int	i = 0;
    
	while (delimiter[i])
	{
		if (c == delimiter[i++])
			return true;
	}
	return false;
}

template <typename T>
std::string to_string(const T& value)
{
    std::ostringstream os;
    os << value;
    return os.str();
}

std::string     BitcoinExchange::find_date(std::ifstream &file, const std::string &date)
{
    std::string line;
    std::string res;

    std::vector<std::string>    content;
    std::vector<std::string>    ymd_data;
    std::vector<std::string>    ymd_input;

    int delta_y = 1;
    int delta_m = 1;
    int delta_d = 1;

    while (std::getline(file, line)) 
    {
        content = split(line, ",");
        
        if (check_date(content[0]))
            continue ;
        
        ymd_data = split(content[0],"-");
        ymd_input = split(date,"-");
        
        delta_y = std::atof(ymd_data[0].c_str()) - std::atof(ymd_input[0].c_str());
        if (delta_y <= 0)
        {
            delta_m = std::atof(ymd_data[1].c_str()) - std::atof(ymd_input[1].c_str());
            if (delta_m <= 0 || delta_y < 0)
            {
                delta_d = std::atof(ymd_data[2].c_str()) - std::atof(ymd_input[2].c_str());
                if (delta_d <= 0 || delta_m < 0)
                    res = line;
            }
        }
        else if (res.empty())
            res = line;
    }
    return res;
}

std::string     BitcoinExchange::getExchangeRate(const std::string &date, float count)
{
    std::ifstream file("data.csv");
    if (check_open(file))
        return std::string("Error : System");
    std::string res;
    std::string line = find_date(file, date);

    std::string tmp = line.substr(11, line.length()-11);
    float rate = std::atof(tmp.c_str());
    float fin = count * rate;
    res = (date + " => " + to_string(count) + " = " + to_string(fin));
    file.close();
    return res;
}

std::vector<std::string> BitcoinExchange::split(const std::string &str, const char *delimiter) const
{
    std::vector<std::string> result;
 	std::string		    token;
	unsigned long int   i;

	i = 0;
	while (i < str.length())
	{
		while (i < str.length() && ft_in_delim(str[i], delimiter))
			i++;
		if (i < str.length())
		{
		    token = "";
			while (i < str.length() && !ft_in_delim(str[i], delimiter))
			    token += str[i++];
			result.push_back(token);
		}
	}

    return result;
}

void    BitcoinExchange::display()
{
    for (std::vector<std::string>::const_iterator i = output.begin(); i != output.end(); i++)
    {
        std::cout << *i << std::endl;
    }
}