#include "InternalConfig.h"
#include "TrainingData.h"
#include "Net.h"
#include "csv.h"

using namespace std;

void showVectorVals(string label, vector<double> &v)
{
    cout << label << " ";
    for(unsigned i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void createTrainingSample(){
    ofstream TrainingSample;
    TrainingSample.open("trainingData.txt");
    TrainingSample << "topology: 2 4 1" << endl;

    for(int i = 2000; i >= 0; --i)
    {
        int n1 = (int)(2.0 * rand() / double(RAND_MAX));
        int n2 = (int)(2.0 * rand() / double(RAND_MAX));
        int t = n1 ^ n2; // should be 0 or 1
        TrainingSample  << "in: " << n1 << ".0 " << n2 << ".0 " << endl;
        TrainingSample  << "out: " << t << ".0" << endl;
    }

}

int main() {

    io::CSVReader<>  in("A:\\dev\\BCI2\\data\\Activity-Chat.csv");
    std::string data;
    while(in.read_row(data)){
        // do stuff with the data
        cout << data << endl;
    }
    createTrainingSample();

    cout << "topology: 2 4 1" << endl;
    TrainingData trainData("trainingData.txt");
    //e.g., {3, 2, 1 }
    vector<unsigned> topology;
    //topology.push_back(3);
    //topology.push_back(2);
    //topology.push_back(1);

    trainData.getTopology(topology);
    Net myNet(topology);

    vector<double> inputVals, targetVals, resultVals;
    int trainingPass = 0;
    while(!trainData.isEof())
    {
        ++trainingPass;
        cout << endl << "Pass" << trainingPass;

        // Get new input data and feed it forward:
        if(trainData.getNextInputs(inputVals) != topology[0])
            break;
        showVectorVals(": Inputs :", inputVals);
        myNet.feedForward(inputVals);

        // Collect the net's actual results:
        myNet.getResults(resultVals);
        showVectorVals("Outputs:", resultVals);

        // Train the net what the outputs should have been:
        trainData.getTargetOutputs(targetVals);
        showVectorVals("Targets:", targetVals);
        assert(targetVals.size() == topology.back());

        myNet.backProp(targetVals);

        // Report how well the training is working, average over recnet
        cout << "Net recent average error: "
             << myNet.getRecentAverageError() << endl;
    }

    cout << endl << "Done" << endl;
    return 0;
}