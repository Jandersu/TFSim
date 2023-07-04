#ifndef CORRELATION_PREDICTOR_HPP
#define CORRELATION_PREDICTOR_HPP

#include <vector>

class correlation_predictor {
private:
    unsigned int m;  // Tamanho do histórico do branch predictor buffer
    unsigned int n;  // Tamanho do registro de histórico do preditor de correlação
    unsigned int correlation_size;  // Tamanho total do registro de histórico do preditor de correlação
    unsigned int max;  // Valor máximo para cálculos
    unsigned int state;	
    std::vector<bool> history;  // Registro de histórico do preditor de correlação
    unsigned int c_predictions;  // Contador de previsões feitas
    unsigned int c_hits;  // Contador de acertos nas previsões

public:
    correlation_predictor(unsigned int t, unsigned int m);
    bool correlation_predict(unsigned int pc);
    void correlation_update_state(unsigned int pc, bool taken, bool hit);
    float get_correlation_hit_rate();
};

#endif // CORRELATION_PREDICTOR_HPP
