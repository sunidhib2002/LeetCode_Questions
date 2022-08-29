class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> idTracker;
    map<pair<string, string>, pair<int, int>> avg;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        idTracker[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string start = idTracker[id].first;
        int t2 = idTracker[id].second;
        avg[{start, stationName}].first += t - t2;
        avg[{start, stationName}].second += 1;
        idTracker.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double sum = avg[{startStation, endStation}].first;
        int size = avg[{startStation, endStation}].second;
        return (sum / size);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */