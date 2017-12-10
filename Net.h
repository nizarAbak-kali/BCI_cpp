//
// Created by Nizar on 10/12/2017.
//

#ifndef BCI2_NET_H
#define BCI2_NET_H

#include "InternalConfig.h"
#include "Neuron.h"

class Net {
public:
    Net(const vector<unsigned> &topology);
    void feedForward(const vector<double> &inputVals);
    void backProp(const vector<double> &targetVals);
    void getResults(vector<double> &resultVals) const;
    double getRecentAverageError(void) const { return m_recentAverageError; }

private:
    vector<Layer> m_layers; //m_layers[layerNum][neuronNum]
    double m_error;
    double m_recentAverageError;
    static double m_recentAverageSmoothingFactor;
};


#endif //BCI2_NET_H
