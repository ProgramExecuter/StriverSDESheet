vector<int>missing_repeated_number(const vector<int> &A) {
    long long int len = A.size();

    // sum of first 'n' numbers
    long long int S = (len * (len+1) ) /2;
    // sum of squares of first 'n' numbers
    long long int P = (len * (len +1) *(2*len +1) )/6;
    
    long long int mis=0, dup=0;
     
    // Calculate S-S1 = (mis-dup) ,  P-P1 = (mis^2 - dup^2)
    for(int i=0;i<A.size(); i++){
       S -= (long long int)A[i];
       P -= (long long int)A[i]*(long long int)A[i];
    }
    
    mis = (S + P/S)/2;

    dup = mis - S;

    return {dup, mis};
}