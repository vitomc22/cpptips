#include <cstdio>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  {

    sqlite3 *db;
    sqlite3_stmt *stmt;

    // vetor de duas dimensões, vetor interno e string

    if (sqlite3_open("banco_de_dados.db", &db) != SQLITE_OK) {
      std::cout << "Failed to open db\n";
    } else {
      auto rc = sqlite3_prepare_v2(db, "SELECT * from dados;", -1, &stmt, NULL);

      rc = sqlite3_step(stmt);
      if (rc == SQLITE_ROW) {
        std::cout << sqlite3_column_text(stmt, 0) << '\n';
        std::cout << sqlite3_column_text(stmt, 1)<< '\n';
      }

      sqlite3_close(db);
    }
  }
  return 0;
}
// nao funfa, traz uma linha somente, parece que a implementação padrão é por callback mesmo
//  g++ select-statement.cpp -l sqlite3 -o select-statemente.o