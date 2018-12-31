void KL_Algo( vector<int> const& p0 ){

  if(p0.size()%2 == 1){  return; }

  bool isLocked[n+1];
  for(int i=0; i<=n; i++){  isLocked[i] = true;  }
  for(int i=0; i<p0.size(); i++){ isLocked[p0[i]] = false; }

  
  vector<int> p[2];
  for(int i=0; i<p0.size()/2; i++ ){
    p[0].push_back(p0[i]);
  }
  for(int i=p0.size()/2; i<p0.size(); i++ ){
    p[1].push_back(p0[i]);
  }
  int u,v,a,b, Dmax = INT_MIN;
  bool innerLoop= true;

  vector< pair<int,int> > TentativeExchangeIndexPair;
  vector< pair<int, int> > tentativeExchange;
  vector<int> mycutsize;
  vector< int > g, gs; // g, gs
  mycutsize.push_back( getCutSize(p[0], p[1]) );
  g.push_back(0);
  gs.push_back(0);
  TentativeExchangeIndexPair.push_back({0,0});
  tentativeExchange.push_back({0,0});
  int amax, bmax;
  int lowestCutSize = mycutsize[0];
  bool outerLoop = true;
  int lowestCutSizeIndex = 0;

  int outerIterationCount = 0; 
  while(outerLoop){
    outerIterationCount++;
    cout<<"**************************************************\n";
    cout<<"Outer Iteration "<<outerIterationCount<<" : \n";
    cout<<"--------------------------------------------------\n";
    vector<int> temp123[2];
    for(int i=0; i<2; i++){
      for(int j=0; j<p[i].size(); j++){
        temp123[i].push_back(p[i][j]);
      }
    }

  /////
    int innerLoopCount = p[0].size();
    cout<<"line 147: innerLoopCount = "<<innerLoopCount<<" \n";
    for(int i=0; i<p[0].size(); i++){
      cout<<p[0][i]<<" ";
    }cout<<"\n";
    for(int i=0; i<p[1].size(); i++){
      cout<<p[1][i]<<" ";
    }cout<<"\n";
    
    //while(innerLoop){
    while(innerLoopCount--){
    
      cout<<"Inner Iteration\n";
      // setup inedge
      for(int i=0; i<p[0].size(); i++){
        inedge[ p[0][i] ] = 0;
        for(int j=0; j<p[0].size(); j++){
          if(i!=j){
            inedge[ p[0][i] ]+=CE[{ p[0][i] , p[0][j] }];
          }
        }
      }
      // setup outedge
      for(int i=0; i<p[0].size(); i++){
        outedge[ p[0][i] ] = 0;
        for(int j=0; j<p[1].size(); j++){
          outedge[  p[0][i]  ]+=CE[{p[0][i], p[1][j] }];  
        }
      }

          // setup inedge
      for(int i=0; i<p[01].size(); i++){
        inedge[ p[01][i] ] = 0;
        for(int j=0; j<p[01].size(); j++){
          if(i!=j){
            inedge[ p[01][i] ]+=CE[{ p[01][i] , p[01][j] }];
          }
        }
      }
      // setup outedge
      for(int i=0; i<p[01].size(); i++){
        outedge[ p[01][i] ] = 0;
        for(int j=0; j<p[0].size(); j++){
          outedge[p[01][i]]+=CE[{p[1][i], p[0][j] }];  
        }
      }
      int i1,j1;
      for(int i=0; i<p[0].size(); i++){
        a = p[0][i];
        if( isLocked[a] ){}
        else if(!isLocked[a]){
          for(int j=0; j<p[1].size(); j++){
            b = p[1][j];
            if(isLocked[b]){}
            else if(!isLocked[b]){
              cout<<"Dmax "<<Dmax<<" Da+Db "<<(D(a)+D(b))<<"\n";
              if(Dmax < (D(a) + D(b)) ){
                i1 = i; j1 = j;
                amax = a; bmax = b;
                Dmax = (D(a) + D(b)) ;
              }
            }
          }
        }
      }
      TentativeExchangeIndexPair.push_back({i1,j1});
      tentativeExchange.push_back({amax, bmax});
      
      int temp = p[0][i1];
      p[0][i1] = p[1][j1];
      p[1][j1] = temp;
      isLocked[amax] = true;
      isLocked[bmax] = true;

      int c = getCutSize(p[0],p[1]);
      mycutsize.push_back(c);

      outerLoop = false; 
      if(c < lowestCutSize ){ lowestCutSize = c; outerLoop = true; lowestCutSizeIndex = mycutsize[mycutsize.size()-1 ];  }
      int prev_cs = mycutsize[mycutsize.size() - 1 ];
      
      int g_last = prev_cs - c;
      g.push_back(g_last);

      int gs_last = gs[gs.size() - 1];
      gs.push_back(gs_last + g_last);


    innerLoop = false;
  
    isLocked[amax] = true;
    isLocked[bmax] = true;  
    cout<<"amax bmax  :  "<<amax<<" "<<bmax<<"\n";
  
    for(int i=01; i<=n; i++){  if(isLocked[i] == false){ innerLoop = true; } }    
    for(int i=0; i<=n; i++){  cout<<isLocked[i]<<" "; } cout<<"\n";
    }
    /////
    // PRINT TABLE!!!
    cout<<"Step	Pair	G	Sum-G	Cutsize";
    cout<<"  0    -   -    -    "<<mycutsize[0]<<"\n";
    for(int i=1; i<mycutsize.size(); i++){
      cout<<i<<"  <"<<tentativeExchange[i].first<<","<<tentativeExchange[i].second<<"> "<<g[i]<<" "<<gs[i]<<" "<<mycutsize[i]<<"\n";
    }
    // ACTUAL CHANGE!
    if(outerLoop){
      cout<<"Parmanent Exachange: ";
      for(int i=1; i<=lowestCutSizeIndex; i++){
          cout<<" < "<<tentativeExchange[i].first<<" , "<<tentativeExchange[i].second<<" > , "; 

        int ui1 = TentativeExchangeIndexPair[i].first;
        int ui2 = TentativeExchangeIndexPair[i].second;

        int temp = temp123[0][ui1];
        temp123[0][ui1] = temp123[1][ui2];
        temp123[1][ui2] = temp; 

        while(!p[0].empty()){ p[0].pop_back(); }
        while(!p[01].empty()){ p[01].pop_back(); }
      
        for(int i=0; i<2; i++){
          for(int j=0; j<temp123[i].size(); j++){
            p[i].push_back(temp123[i][j]);
          }
        }
      }
      cout<<"\n";
      cout<<"p1 : {";
      for(int i=0; i<p[0].size(); i++){ cout<<p[0][i]<<" "; }
      cout<<"}\n";

      cout<<"p2 : {";
      for(int i=0; i<p[1].size(); i++){ cout<<p[1][i]<<" "; }
      cout<<"}\n";

      cout<<"CutSize:  "<<lowestCutSize<<"\n";
      cout<<"\n---------------------------------------------------\n";
      
    }else{
      cout<<"\nNo Improvement\n";
      partitions.push(temp123[0]);
      partitions.push(temp123[1]);
    }

    while(!mycutsize.empty()){
      mycutsize.pop_back(); g.pop_back(); gs.pop_back(); 
      tentativeExchange.pop_back(); TentativeExchangeIndexPair.pop_back();
    }
  }
  // end of outer loop!
  
  
  
}
