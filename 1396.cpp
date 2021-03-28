class UndergroundSystem {
private:
	      //<der eingang,         <der ausgang, <sum of all times for all trips,
		  //													  no of trips>>>
    unordered_map<string, unordered_map<string, pair<uint64_t, uint32_t>>>
																	processed;
	      //<der eingang,    <id of the pessengar, entry time>>
    unordered_map<uint32_t, pair<string, uint32_t>>
																un_processed;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
		pair<string, uint32_t> elem;
		elem.first = stationName;
		elem.second = t;
		un_processed[id] = elem;
    }
    
    void checkOut(int id, string stationName, int t) {
		pair<string, uint32_t> elem = un_processed[id];
        un_processed.erase(id);
		if (processed.find(elem.first) == processed.end()) {
			unordered_map<string, pair<uint64_t, uint32_t>> ausgang_eintrit;
			ausgang_eintrit[stationName] = make_pair({t - elem.second, 1});
			processed[elem.first] = ausgang_eintrit;
		}
		else {
			// two cases
			// first case is ausgang station not encountered
			if (processed[elem.first].find(stationName) ==
										processed[elem.first].end()) {
				pair<uint64_t, uint32_t> temp;

				temp.first = t - elem.second;
				temp.second = 1;
				processed[elem.first][stationName] = temp;
			}
			// second case is ausgang station encountered
			else {
				processed[elem.first][stationName] = make_pair {
					processed[elem.first][stationName].first + (t - elem.second), 
					processed[elem.first][stationName].second++};
			}
		}
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)processed[startStation][endStation].first/
					(double)processed[startStation][endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
