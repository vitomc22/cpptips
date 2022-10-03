#include <iostream>
#include <sqlite3.h>

static int callback(void *, int, char **, char **);

int main(int argc, char const *argv[]) {
  sqlite3 *DB;
  bool connect = sqlite3_open("banco_de_dados.db", &DB);
  std::string data("CALLBACK FUNCTION");
  std::string sql("SELECT * FROM dados");

  if (connect) {
    std::cerr << "Erro ao conectar o banco." << sqlite3_errmsg(DB) << '\n';
    sqlite3_close(DB);
    return 1;

  } else {
    std::cout << "Conectado com SUCESSO!" << '\n';
  }
  int rc = sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

  if (rc != SQLITE_OK) {
    std::cerr << "Erro ao retornar dados: " << sqlite3_errmsg(DB) << '\n';
    std::cerr << "Código do erro: " << sqlite3_errcode(DB) << '\n';
  }
  sqlite3_close(DB);

  return 0;
}
static int callback(void *data, int argc, char **argv, char **az_col_name) {
  for (int i = 0; i < argc; i++) {
    std::cout << argv[i] << " ";
  }
  std::cout << '\n';
  return 0;
}

// g++ select-sqlite.cpp -l sqlite3 -o select-teste.o