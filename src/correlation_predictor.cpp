#include "correlation_predictor.hpp"

correlation_predictor::correlation_predictor(unsigned int t, unsigned int m) : m(m), n(t), c_predictions(0), c_hits(0) {
    correlation_size = 1 << (m + n);
    max = (1 << n) - 1;
    history.resize(correlation_size, false);
}

bool correlation_predictor::correlation_predict(unsigned int pc) {
    c_predictions++;

    // Obter o valor do registro de histórico para o PC atual
    unsigned int index = (pc << n) | (state & max);
    bool prediction = history[index];

    return prediction;
}

void correlation_predictor::correlation_update_state(unsigned int pc, bool taken, bool hit) {
    c_hits += hit;

    // Atualizar o registro de histórico com o resultado atual
    unsigned int index = (pc << n) | (state & max);
    history[index] = taken;

    // Deslocar o estado do preditor de correlação
    state = (state << 1) | taken;
}

float correlation_predictor::get_correlation_hit_rate() {
    return (float)c_hits / (float)c_predictions * 100;
}