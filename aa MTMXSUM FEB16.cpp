
        mapB[ B[i] ].insert(i);
    }
 
    vector<ll> v;
    
    FOR(i,1,n) {
        while( !v.empty() && A[v.back()] < A[i] ) {
            RA[v.back()] = i-1;
             v.pop_back();
        }
        v.pb(i);
    }
    
    while(!v.empty()) {
        RA[v.back()] = n;
        v.pop_back();
    }
 
    ROF(i,n,1) {
        while( !v.empty() && A[v.back()] <= A[i] ) {
            LA[v.back()] = i+1;
            v.pop_back();
        }
        v.pb(i);
    }
 
    while(!v.empty()) {
        LA[v.back()] = 1;
        v.pop_back();
    }
 
    FOR(i,1,n) {
        while( !v.empty() && B[v.back()] < B[i] ) {
            RB[v.back()] = i-1;
            v.pop_back();
        }
        v.pb(i);
    }
    
    while(!v.empty()) {
        RB[v.back()] = n;
        v.pop_back();
    }
 
    ROF(i,n,1) {
        while( !v.empty() && B[v.back()] <= B[i] ) {
            LB[v.back()] = i+1;
            v.pop_back();
        }
        v.pb(i);
    }
 
    while(!v.empty()) {
        LB[v.back()] = 1;
        v.pop_back();
    }
 
    set< pair< ll, pair<ll,ll> > > setA, setB;
        
    FOR(i,1,n) {
        //~ cerr << "P: " << A[i] << ' ' << LA[i] << ' ' << RA[i] << '\n';
        if( setA.count( { A[i], { LA[i], RA[i] } } ) ) continue;
        setA.insert( { A[i], { LA[i], RA[i] } } );
        ll l = 1, r = RA[i] - LA[i] + 1, pos = i - LA[i] + 1;
        ll span = min( r-pos, pos-l );
        inA[l] += A[i];
        inA[l+span+1] += -A[i];
        inA[r-span+1] += -A[i];
        inA[r+2] += A[i];
    }
    
    FOR(i,1,n) {
        if( setB.count( { B[i], { LB[i], RB[i] } } ) ) continue;
        setB.insert( { B[i], { LB[i], RB[i] } } );
        ll l = 1, r = RB[i] - LB[i] + 1, pos = i - LB[i] + 1;
        ll span = min( r-pos, pos-l );
        inB[l] += B[i];
        inB[l+span+1] += -B[i];
        inB[r-span+1] += -B[i];
        inB[r+2] += B[i];
    }
    
    ll sumA = 0, sumB = 0, addA = 0, addB = 0;
    FOR(i,1,n) {
        addA += inA[i];
        sumA += addA;
        
        addB += inB[i];
        sumB += addB;
        
        //~ cerr << "\nU: " << inA[i] << ' ' << inB[i] << '\n';
        //~ cerr << "\nR: " << sumA << ' ' << sumB << '\n';
        
        cout << (sumA%MOD)*(sumB%MOD) % MOD << ' ';
    }
}