ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}
ll extended_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1,y = 0;
        return a;
    } // finds one (x,y) s.t ax+by = gcd(a,b) 
    ll x1, y1;
    ll d = extended_gcd(b, a % b, x1, y1);
    x = y1,y = x1 - y1 * (a / b);
    return d;
}
