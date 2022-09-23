#include <exception>
#include <iostream>
#include <mysql/mysql.h>
#include <stdexcept>
#include <stdlib.h>

int main() {
  MYSQL *connect;
  connect = mysql_init(NULL);
  connect = mysql_real_connect(connect, "localhost", "victor", "123", "cpp", 0,
                               NULL, 0);

  try {
    if (!connect) {
      throw connect;
      return 1;
    }

    MYSQL_RES * res_set;
    MYSQL_ROW row;

    mysql_query(connect, "SELECT * FROM   crudcpp");
    unsigned int i = 0;
    res_set = mysql_store_result(connect);
    unsigned int numrows = mysql_num_rows(res_set);

    while ( (row = mysql_fetch_row(res_set)) != NULL)    {  
      std::cout <<row[0] <<" | " << row[1] <<" | " << row[2] <<" | " << '\n';
      
    }

    mysql_close(connect);
    return 0;

  } catch (...) {
    std::cout << "Falha ao conectar!" << '\n';
  }

  
}
