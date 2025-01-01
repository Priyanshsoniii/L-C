#include <iostream>
#include <string>
#include <map>
#include <vector>

void displayAdjacentCountries(const std::string &countryCode)
{
    std::map<std::string, std::pair<std::string, std::vector<std::string>>> countryMap;

    countryMap["IN"] = {"India", {"Pakistan", "China", "Nepal", "Bhutan", "Bangladesh", "Myanmar"}};
    countryMap["US"] = {"United States", {"Canada", "Mexico"}};
    countryMap["NZ"] = {"New Zealand", {"Australia"}};
    countryMap["CA"] = {"Canada", {"United States"}};
    countryMap["AU"] = {"Australia", {"New Zealand"}};
    countryMap["CN"] = {"China", {"India", "Pakistan", "Nepal", "Bhutan", "Russia", "Mongolia", "North Korea"}};

    if (countryMap.find(countryCode) != countryMap.end())
    {
        std::cout << "Country: " << countryMap[countryCode].first << std::endl;
        std::cout << "Adjacent countries: ";

        for (const std::string &adjacentCountry : countryMap[countryCode].second)
        {
            std::cout << adjacentCountry << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Country code not found!" << std::endl;
    }
}

int main()
{
    int userChoice;
    do
    {
        std::cout << "1. Find Country by Country Code\n";
        std::cout << "2. Exit\n";
        std::cout << "Enter your choice (1 or 2): ";
        std::cin >> userChoice;

        switch (userChoice)
        {
        case 1:
        {
            std::string countryCode;

            std::cout << "Enter country code (e.g., IN/US/NZ/CA/AU/CN): ";
            std::cin >> countryCode;

            for (auto &character : countryCode)
            {
                character = toupper(character);
            }

            displayAdjacentCountries(countryCode);
        }
        break;
        case 2:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice! Please enter 1 or 2." << std::endl;
            break;
        }

    } while (userChoice != 2);
    return 0;
}
