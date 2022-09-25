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
  std::string select;
  select = "select * from crudcpp";

  try {
    if (!connect) {
      throw connect;
      return 1;
    }

    MYSQL_RES *res;
    MYSQL_ROW row;

    mysql_query(connect,
                select.c_str()); // fizemos cast da query de string pra char
    res = mysql_store_result(connect); // necessário pra armazenar o resultado

    while ((row = mysql_fetch_row(res)) != NULL) {
      std::cout << row[0] << " | " << row[1] << " | " << row[2] << " | "
                << '\n';
    }

    mysql_close(connect);
    return 0;

  } catch (...) {
    std::cout << "Falha ao conectar!" << '\n';
  }
}
// g++ create.cpp -L /usr/include/mysql -lmysqlclient -I /usr/include/mysql -o
// create
