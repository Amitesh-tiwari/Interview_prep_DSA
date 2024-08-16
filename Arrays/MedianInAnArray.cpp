Given an array arr[] of N integers, calculate the median.

NOTE: Return the floor value of the median.

//code
int find_median(vector<int> v)
		{
		    int n = v.size();
		    sort(v.begin(), v.end());
		    if(n%2 == 0){
		        int index1 = n/2-1;
		        int index2 = n/2;
		        int median = (v[index1] + v[index2])/2;
		        return median;
		    }
		    else{
		        return v[n/2];
		    }
		}
