struct seg{ ld x; ll m,b;};
 vector<seg>hull;     // for maxima, lines to be inserted in non-dec order, for minima,  non inc.
void insert_to_hull(ll m,ll b){
  while(hull.size()){
    seg s=hull.back();
    if(s.b+s.m*s.x>b+m*s.x){  // for minimum '<' sign will be there.
      if(s.m-m)hull.push_back({(b-s.b)/(ld)(s.m-m),m,b});
      return;
    }
    hull.pop_back(); 
  }
  hull={{LLONG_MIN,m,b}};
}
ll query_hull(ll x){
  seg s=*--upper_bound(hull.begin(),hull.end(),x,[](ll a,seg b){return a<b.x;});
  return s.b+s.m*x;
}
