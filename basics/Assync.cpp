#include <chrono>
#include <future>
#include <iostream>
#include <string>
#include <thread>


std::string get_first_data_api(std::string ret_data) {
  // sleep de dois segundos
  std::this_thread::sleep_for(std::chrono::seconds(2));
  return "FIRST_" + ret_data;
}

std::string get_second_data_api(std::string ret_data) {
  // sleep de dois segundos
  std::this_thread::sleep_for(std::chrono::seconds(2));
  return "SECOND_" + ret_data;
}

int main(int argc, char const *argv[]) {
  // começar a contagem a partidar da hora agora
  auto start = std::chrono::system_clock::now();
  // pegando primeira API
  // AQUI É ESTRANHO MAS A STRING "NUMERO_UM" É PASSADA COMO ARGUMENTO SOMENTE
  // COLOCANDO COMO PROXIMO PARÂMETRO DA ASYNC GET_FISRT_DATA_API <--
  // "NUMERO_UM"
   //executa uma função de forma assíncrona (potencialmente em um novo segmento (THREAD)) e retorna uma std::future que vai segurar o resultado 
  auto result_api_one =
      std::async(std::launch::async, get_first_data_api, "NUMERO_UM");

  // pega dados da segunda API
  std::string second_api = get_second_data_api("NUMERO_DOIS");

  // Bloqueará até que os dados estejam disponíveis no objeto
  // future<std::string>.
  // first_api é uma std::future que vai segurar o resultado de forma assíncrona
  std::string first_api = result_api_one.get();

  // Obtém o final do tempo
  auto end = std::chrono::system_clock::now();

  auto diff =
      std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

  std::cout << "Tempo gasto para a requisição: " << diff << " Segundos" << '\n';

  // Imprime a saída
  std::cout << "Primeira API: " << first_api << "\nSegunda  API: " << second_api
            << '\n';

  return 0;
}


// g++ -std=c++11  Assync.cpp -lpthread -o  Assync