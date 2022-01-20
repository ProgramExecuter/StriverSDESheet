class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp(Item a, Item b) {
        return ( (1.0*a.value)/(1.0*a.weight) ) > ( (1.0*b.value)/(1.0*b.weight) );
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Sort the array by value per weight
        sort(arr, arr+n, comp);
        
        double profit = 0.0;
        
        int i = 0;
        while(W>0  &&  i<n) {
            // If W(capacity) is greater than weight then take whole
            if(W > arr[i].weight) {
                profit += arr[i].value;
                
                W -= arr[i].weight;
            }
            else {
                profit += ( W*( (1.0*arr[i].value)/(1.0*arr[i].weight) ) );
                W = 0;
            }
            ++i;
        }
        
        return profit;
    }
};