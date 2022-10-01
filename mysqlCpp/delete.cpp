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
  std::string remove, var_delete;

  try {
    if (!connect) {
      throw connect;
      return 1;
    }

    std::cout << "Vamos Excluir os dados! " << '\n';
    std::cout << "informe o nome ou email que deseja excluir: " << '\n';
    std::getline(std::cin, var_delete);
    if (var_delete.find("@") != std::string::npos) {

      remove = "DELETE FROM crudcpp WHERE mail like '" + var_delete + "'";

      std::cout << "Delete realizado abaixo... " << '\n';
      std::cout << remove << '\n';

    } else {

      remove = "DELETE FROM crudcpp WHERE nome like '" + var_delete + "'";

      std::cout << "Delete realizado abaixo... " << '\n';
      std::cout << remove << '\n';
    }

    bool query_state = mysql_query(connect, remove.c_str());
    if (query_state) {

      std::cout << "Erro ao deletar os dados: " << mysql_error(connect) << '\n';
    }

    mysql_close(connect);
    return 0;

  } catch (...) {
    std::cout << "Falha ao conectar!" << '\n';
  }
}
// g++ delete.cpp -L /usr/include/mysql -lmysqlclient -I /usr/include/mysql -o
// delete
