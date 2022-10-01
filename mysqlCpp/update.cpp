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
  std::string update, var_update,novo_val;

  try {
    if (!connect) {
      throw connect;
      return 1;
    }

    std::cout << "Vamos atualizar os dados! " << '\n';
    std::cout << "informe o nome ou email que deseja atualizar: " << '\n';
    std::getline(std::cin, var_update);
     if(var_update.find("@") != std::string::npos) {
      std::cout << "Digite o novo Email! " << '\n';
      std::getline(std::cin, novo_val);
      update =
        "UPDATE  crudcpp SET mail = '" + novo_val + "' WHERE mail ='" + var_update+"'";

      std::cout << "Update realizado abaixo... " << '\n';
      std::cout << update << '\n';

     } else{
       std::cout << "Digie o novo nome! " << '\n';
      std::getline(std::cin, novo_val);
      update =
        "UPDATE  crudcpp SET nome =  '" + novo_val + "' WHERE nome ='" + var_update+"'";

      std::cout << "Update realizado abaixo... " << '\n';
      std::cout << update << '\n';

     }
    

    bool query_state = mysql_query(connect, update.c_str());
    if (query_state) {

      std::cout << "Erro ao atualizar os dados: " << mysql_error(connect) << '\n';
    }

    mysql_close(connect);
    return 0;

  } catch (...) {
    std::cout << "Falha ao conectar!" << '\n';
  } 
}
// g++ update.cpp -L /usr/include/mysql -lmysqlclient -I /usr/include/mysql -o
// update
