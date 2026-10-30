// Mono-Code
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct AccountData
{
  std::string name{};
  double balance{};
};

class Bank_system
{
private:
  double m_balalnce{0.0};
  std::string m_fileName{"bank_data.txt"};
  std::string m_currentUserName{};
  bool m_isLogged{false};

public:
  bool login(const std::string &username)
  {
    std::ifstream inFile(m_fileName);
    if (!inFile.is_open())
    {
      std::cout << "Error to opening a file";
      return false;
    }

    std::string name{};
    double balance{};
    bool found = false;

    while (inFile >> name >> balance)
    {
      if (name == username)
      {
        m_currentUserName = name;
        m_balalnce = balance;
        m_isLogged = true;
        found = true;
        break;
      }
    }

    if (!found)
    {
      std::cout << "User not found." << '\n';
    }
    return found;
  }

  void fill_deposit(double amount)
  {
    if (amount > 0)
    {
      m_balalnce += amount;
      std::cout << "Success! " << amount << '\n';
    }
    else
    {
      std::cout << "Error" << '\n';
    }
  }
  bool wiht_draw(double amount)
  {
    if (m_balalnce >= amount)
    {
      m_balalnce -= amount;
      std::cout << "Success! " << amount << '\n';
      return true;
    }
    else
    {
      std::cout << "Error" << '\n';
      return false;
    }
  }
  void show_balance()
  {
    std::cout << m_balalnce << '\n';
  }

private:
  void write_to_file()
  {
    std::ifstream inFile("bank_data.txt");
    std::vector<AccountData> accounts{};

    std::string name{};
    double balance{};

    while (inFile >> name >> balance)
    {
      if (name == m_currentUserName)
      {
        accounts.push_back({m_currentUserName, m_balalnce});
      }
      else
      {
        accounts.push_back({m_currentUserName, balance});
      }
    }
    inFile.close();

    std::ofstream outFile(m_fileName);
    for (const auto &acc : accounts)
    {
      outFile << acc.name << " " << acc.balance << '\n';
    }
  }
};

int main()
{
  Bank_system bank{};

  std::string username{};
  std::cout << "Enter your name to login: ";
  std::cin >> username;

  if (!bank.login(username))
  {
    return 0;
  }

  while (true)
  {
    std::system("cls");
    std::cout << "\n==== Menu ====\n"
              << "1. Deposit\n"
              << "2. Withdraw\n"
              << "3. Show balance\n"
              << "4. Exit\n"
              << "Choice: ";

    int operation{};
    if (!(std::cin >> operation))
    {
      std::cout << "Invalid input!\n";
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      continue;
    }

    switch (operation)
    {
    case 1:
    {
      double amount{};
      std::cout << "Enter amount: ";
      std::cin >> amount;
      bank.fill_deposit(amount);
      std::cin.ignore(1000, '\n');
      std::cin.get();
      break;
    }

    case 2:
    {
      double amount{};
      std::cout << "Enter amount: ";
      std::cin >> amount;
      bank.wiht_draw(amount);
      std::cin.ignore(1000, '\n');
      std::cin.get();
      break;
    }

    case 3:
      bank.show_balance();
      std::cin.ignore(1000, '\n');
      std::cin.get();
      break;

    case 4:
      std::cout << "Exited\n";
      return 0;

    default:
      std::cout << "Invalid operation\nTry again!\n";
      break;
    }
  }
}
