double power(double x, int n) {
    double ans = 1.0;
    for(int i=1; i<=n; ++i)
        ans = ans * x;
    return ans;
}
double findNthRootOfM(int n, long long m) {
    double low = 1.0, high = m+1;
    
    // Since we want our result to precise till 6th decimal place
    double sp = 1e-7;

    // While high and low are far apart
    while(high-low > sp) {
        double mid = (low+high)/2.0;
        
        if(power(mid, n) > double(m))
            high = mid;
        else
            low = mid;
    }
    
    return low;
}