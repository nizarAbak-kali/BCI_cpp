//
// Created by Nizar on 10/12/2017.
//

#ifndef BCI2_NEURON_H
#define BCI2_NEURON_H

#include "InternalConfig.h"

class Neuron {
public:
    Neuron(unsigned numOutputs, unsigned myIndex);
    void setOutputVal(double val) { m_outputVal = val; }
    double getOutputVal(void) const { return m_outputVal; }
    void feedForward(const Layer &prevLayer);
    void calcOutputGradients(double targetVals);
    void calcHiddenGradients(const Layer &nextLayer);
    void updateInputWeights(Layer &prevLayer);
    static double eta; // [0.0...1.0] overall net training rate
    static double alpha; // [0.0...n] multiplier of last weight change [momentum]
private:
    static double transferFunction(double x);
    static double transferFunctionDerivative(double x);
    // randomWeight: 0 - 1
    static double randomWeight(void) { return rand() / double(RAND_MAX); }
    double sumDOW(const Layer &nextLayer) const;
    double m_outputVal;
    vector<Connection> m_outputWeights;
    unsigned m_myIndex;
    double m_gradient;
};


#endif //BCI2_NEURON_H