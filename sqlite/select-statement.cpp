#include <cstdio>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  {

    sqlite3 *db;
    sqlite3_stmt *stmt;
    std::vector<std::vector<std::string>> result;

    // vetor de duas dimensões, vetor interno e string

    if (sqlite3_open("banco_de_dados.db", &db) != SQLITE_OK) {
      std::cout << "Failed to open db\n";
    } else {
      sqlite3_prepare(db, "SELECT * from dados;", -1, &stmt,
                      NULL); // preparing the statement
      sqlite3_step(stmt);    // executing the statement

      for (int i = 0; i < 2; i++) {
        result.push_back(std::vector<std::string>());
      }

      while (sqlite3_column_text(stmt, 0)) {
        for (int i = 0; i < 2; i++)
          result[i].push_back(
              std::string((char *)sqlite3_column_text(stmt, i)));
        sqlite3_step(stmt);
      }

      sqlite3_close(db);
    }
  }
  return 0;
}
//nao funfa, ta dando segmentation fault
// g++ select-statement.cpp -l sqlite3 -o select-statemente.o