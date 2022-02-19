class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int FuelInTank{0},TotalFuelConsumed{0},StartIndex{0};
        for(int i=0;i<gas.size();i++)
        {
            TotalFuelConsumed += gas[i] - cost[i];
            FuelInTank += gas[i]-cost[i];
            if(FuelInTank<0)
            {
                StartIndex=i+1;
                FuelInTank=0;
            }
        }
        if(TotalFuelConsumed < 0) return -1;
        return StartIndex;
    }
};