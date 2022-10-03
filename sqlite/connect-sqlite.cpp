#include <iostream>
#include <sqlite3.h>

int main(int argc, char const *argv[]) {
  sqlite3 *DB;
  bool connect = sqlite3_open("banco_de_dados.db", &DB);

  if (connect) {
    std::cerr << "Erro ao conectar o banco." << sqlite3_errmsg(DB) << '\n';
    return 1;

  } else {
    std::cout << "Conectado com SUCESSO!" << '\n';
    sqlite3_close(DB);
  }

  return 0;
}

//g++ connect-sqlite.cpp -l sqlite3 -o connect-teste.o