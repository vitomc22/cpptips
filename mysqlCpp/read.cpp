#include <iostream>
#include <mysql/mysql.h>
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

    MYSQL_RES *res_set; //typedef struct MYSQL_RES -> coluna, serve estruturar os resultados da query 
    MYSQL_ROW row;   //return data as array of strings

    mysql_query(connect, "SELECT * FROM   crudcpp"); //cria a query

    res_set = mysql_store_result(connect); //Guarda o reslutado da query

    while ((row = mysql_fetch_row(res_set)) != NULL) {
      std::cout << row[0] << " | " << row[1] << " | " << row[2] << " | "
                << '\n';
    }

    mysql_close(connect);
    return 0;

  } catch (...) {
    std::cout << "Falha ao conectar!" << '\n';
  }
}
