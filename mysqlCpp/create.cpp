#include <cstring>
#include <exception>
#include <iostream>
#include <mysql/mysql.h>
#include <stdexcept>
#include <stdlib.h>
#include <string>

int main() {
  MYSQL *connect;
  connect = mysql_init(NULL);
  connect = mysql_real_connect(connect, "localhost", "victor", "123", "cpp", 0,
                               NULL, 0);
  std::string create, nome, email;

  try {
    if (!connect) {
      throw connect;
      return 1;
    }

    std::cout << "informe o nome: " << '\n';
    std::getline(std::cin, nome);

    std::cout << "informe o email: " << '\n';
    std::getline(std::cin, email);

    create =
        "INSERT INTO crudcpp VALUES (NULL, '" + nome + "', '" + email + "' )";

    bool query_state = mysql_query(connect, create.c_str());
    if (query_state) {

      std::cout << "Erro ao inserir os dados: " << mysql_error(connect) << '\n';
    }

    mysql_close(connect);
    return 0;

  } catch (...) {
    std::cout << "Falha ao conectar!" << '\n';
  }
}
// g++ create.cpp -L /usr/include/mysql -lmysqlclient -I /usr/include/mysql -o
// create
