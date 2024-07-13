Given an integer numRows, return the first numRows 
of Pascal's triangle.

In Pascal's triangle, each number is the sum of the 
two numbers directly above it

//code
vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
            vector<int> row(i+1,1);
            for(int j=1;j<i;j++){
                row[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(row);
        }
        return res;
}