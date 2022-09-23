#include <exception>
#include <iostream>
#include <mysql/mysql.h>
#include <stdexcept>
#include <stdlib.h>

int main() {
  MYSQL *connect;
  connect = mysql_init(NULL);
  if (!connect) {
    std::cout << "Deu ruim an inicialização!" << '\n';
    return 1;
  }
  connect = mysql_real_connect(connect, "localhost", "victor", "123", "cpp", 0,
                               NULL, 0);

  if (connect) {
    std::cout << "Deu bom, a versão do server é: " << connect->server_version
              << '\n';
  } else {
    std::cout << "Erro na conexão com o banco de dados!" << '\n';
    std::cout << "Verifique os dados de conexão..." << '\n';
  }
  mysql_close(connect);

  return 0;
}
