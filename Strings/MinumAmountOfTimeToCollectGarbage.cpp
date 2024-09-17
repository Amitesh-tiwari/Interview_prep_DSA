You are given a 0-indexed array of strings garbage where 
garbage[i] represents the assortment of garbage at the ith
 house. garbage[i] consists only of the characters 'M', 
 'P' and 'G' representing one unit of metal, paper and 
 glass garbage respectively. Picking up one unit of any 
 type of garbage takes 1 minute.

You are also given a 0-indexed integer array travel where 
travel[i] is the number of minutes needed to go from house
 i to house i + 1.

There are three garbage trucks in the city, each 
responsible for picking up one type of garbage. Each 
garbage truck starts at house 0 and must visit each house
 in order; however, they do not need to visit every house.

Only one garbage truck may be used at any given moment. 
While one truck is driving or picking up garbage, the 
other two trucks cannot do anything.

Return the minimum number of minutes needed to pick up 
all the garbage.

//code
int garbageCollection(vector<string>& garbage, vector<int>& travel){
         int garbageCount = garbage.size();
        int travelCount = travel.size();
      
        // Initialize an array to keep track of the last occurrence position of each type of garbage ('A' to 'Z').
        int lastPosition[26] = {};
      
        // Initialize total time taken to collect garbage to 0.
        int totalTime = 0;
      
        // Iterate through all the piles of garbage to perform initial collection and record the last occurrence.
        for (int i = 0; i < garbageCount; ++i) {
            // Add the size of the current pile to the total time (as it represents direct collection time).
            totalTime += garbage[i].size();
            // Update the last occurrence position for each type of garbage found in the current pile.
            for (char& c : garbage[i]) {
                lastPosition[c - 'A'] = i;
            }
        }
      
        // Initialize a prefix sum array to store the cumulative travel time to reach each house.
        int cumulativeTravel[travelCount + 1];
        cumulativeTravel[0] = 0;
      
        for (int i = 1; i <= travelCount; ++i) {
            cumulativeTravel[i] = cumulativeTravel[i - 1] + travel[i - 1];
        }
      
        // Add the necessary travel time for each type of garbage to the total time.
        for (int i : lastPosition) {
            if (i != 0) { // Non-zero position means the garbage type was present and needs to be collected.
                totalTime += cumulativeTravel[i];
            }
        }
      
        // Return the total time taken for garbage collection.
        return totalTime;
}