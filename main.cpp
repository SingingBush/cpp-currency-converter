#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <vector>

class Currency {
public:
    std::string name;
    std::string symbol;
    long double value;

public:
    Currency(std::string name, std::string symbol, long double value) {
        this->name = name;
        this->symbol = symbol;
        this->value = value;
    }
private:
    friend std::ostream& operator<<(std::ostream&, const Currency&);
};

std::ostream& operator<<(std::ostream &strm, const Currency &c) {
    return strm << "Currency{name: " << c.name
                << ", symbol: " << c.symbol
                << ", value: " << std::fixed
                            << std::setprecision(std::numeric_limits<long double>::max_digits10)
                            << std::to_string(c.value)
                << "}";
}

std::vector<Currency> currencies;

int main() {
    std::cout << "Opening csv file..." << std::endl;
    std::ifstream in;
    in.open("../data.csv");

    if(!in.is_open()) {
        std::cerr << "failed to open file.";
        std::exit(EXIT_FAILURE);
    }

    std::string line;

    std::getline(in, line); // skip 1st line

    while (std::getline(in, line)) {
        //std::cout << line << std::endl;

        std::istringstream lineStream(line);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(lineStream, token, ',')) {
            tokens.push_back(std::move(token));
        }

        char* end;
        long double value = std::strtold(tokens[2].c_str(), &end);
        transform(tokens[1].begin(), tokens[1].end(), tokens[1].begin(), ::toupper); // ensure symbol is uppercase
        Currency currency = Currency(tokens[0], tokens[1], value);
        currencies.push_back(std::move(currency));
    }

    std::for_each(currencies.begin(), currencies.end(), [](Currency& cur) { std::cout << cur << std::endl; });

    std::exit(EXIT_SUCCESS);
}

