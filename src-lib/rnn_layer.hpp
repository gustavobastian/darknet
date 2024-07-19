#pragma once

#include "activations.hpp"
#include "layer.hpp"
#include "network.hpp"

/// @todo what is this?
#define USET

#ifdef __cplusplus
extern "C" {
#endif
Darknet::Layer make_rnn_layer(int batch, int inputs, int hidden, int outputs, int steps, ACTIVATION activation, int batch_normalize, int log);

void forward_rnn_layer(Darknet::Layer & l, network_state state);
void backward_rnn_layer(Darknet::Layer & l, network_state state);
void update_rnn_layer(Darknet::Layer & l, int batch, float learning_rate, float momentum, float decay);

#ifdef GPU
void forward_rnn_layer_gpu(Darknet::Layer & l, network_state state);
void backward_rnn_layer_gpu(Darknet::Layer & l, network_state state);
void update_rnn_layer_gpu(Darknet::Layer & l, int batch, float learning_rate, float momentum, float decay, float loss_scale);
void push_rnn_layer(Darknet::Layer /*&*/ l);
void pull_rnn_layer(Darknet::Layer /*&*/ l);
#endif

#ifdef __cplusplus
}
#endif
