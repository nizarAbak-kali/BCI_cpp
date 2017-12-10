//
// Created by Nizar on 10/12/2017.
//

#ifndef BCI2_TRAININGDATA_H
#define BCI2_TRAININGDATA_H

#include "InternalConfig.h"

using namespace std;

class TrainingData {
    public:
    TrainingData(const string filename);

    bool isEof(void) {
        return m_trainingDataFile.eof();
    }

    void getTopology(vector<unsigned> &topology);

    // Returns the number of input values read from the file:
    unsigned getNextInputs(vector<double> &inputVals);

    unsigned getTargetOutputs(vector<double> &targetOutputVals);

private:
    ifstream m_trainingDataFile;
};


#endif //BCI2_TRAININGDATA_H
