// Mono-Code
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Account
{
  std::string name;
  double balance;
};
class Bank
{
private:
  double m_balance{};
  std::string m_fileName{"Text.txt"};
  std::string m_currentUserName{};

  bool m_isLogged{false};

public:
  std::string name{};
  double balance{};
  bool isLogged{false};
  bool is_logged(const std::string &username)
  {
    std::ifstream inFile(m_fileName);

    if (!inFile.is_open())
    {
      std::cout << "Error to opening the file\n";
      return false;
    }

    std::string name{};
    double balance;
    bool found{true};

    while (inFile >> name >> balance)
    {
      if (name == username)
      {
        m_currentUserName = name;
        m_balance = balance;
        m_isLogged = true;
        found = false;
        return true;
      }
    }

    if (!found)
    {
      std::cout << "Error to opening file\n";
    }
    return found;
  }

  void deposit(double &amount)
  {
    if (amount > 0)
    {
      std::cout << "Success! Deposit filled up to " << amount << '\n';
      m_balance += amount;
      write_to_file();
    }
    else
    {
      std::cout << "Error to filling deposit\n";
    }
  }

  bool with_draw(double &amount)
  {
    if (m_balance >= amount)
    {
      std::cout << "Withdraw accepted! " << amount << '\n';
      m_balance -= amount;
      write_to_file();
      return true;
    }
    else
    {
      std::cout << "Withdraw declined\n ";
      return false;
    }
  }

  void show_balance() const
  {
    std::cout << "Your balance: " << m_balance << '\n';
  }

private:
  void write_to_file()
  {
    std::ifstream inFile(m_fileName);
    std::vector<Account> accounts{};

    std::string name{};
    double balance;

    while (inFile >> name >> balance)
    {
      if (name == m_currentUserName)
      {
        accounts.push_back({name, m_balance});
      }
      else
      {
        accounts.push_back({name, balance});
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
  Bank bank{};

  std::string username{};
  std::cout << "Enter your name: ";
  std::cin >> username;

  if (!bank.is_logged(username))
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
      std::cout << "Invalid input\n";
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
      bank.deposit(amount);
      std::cin.ignore(1000, '\n');
      std::cin.get();
      break;
    }
    case 2:
    {
      double amount{};
      std::cout << "Enter amount: ";
      std::cin >> amount;
      bank.with_draw(amount);
      std::cin.ignore(1000, '\n');
      std::cin.get();
      break;
    }
    case 3:
    {
      bank.show_balance();
      std::cin.ignore(1000, '\n');
      std::cin.get();
      break;
    }

    case 4:
    {
      std::cout << "Thank you for using my console bank pet-project!\n";
      return 0;
    }

    default:
    {
      std::cout << "Invalid operation.\n Try again!\n";
      std::cin.ignore(1000, '\n');
      std::cin.get();
      break;
    }
    }
  }
}
