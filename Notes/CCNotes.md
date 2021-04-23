### DEBUG MISTAKES

1. int ->long long check all the variables.

2. compare functions should be complete.

3. check if else conditions and their order.

   



### Segment Trees



> ```c++
> ll t[MAXN*4];
> ll combine (ll a,ll b)
> {
> 	return a+b;
> }
> 
> void build(vll &arr, ll v, ll tl , ll tr)
> {
> 	if(tl == tr)
> 	{
> 		t[v] = arr[tl];
> 	}
> 	else{
> 		ll tm = (tl+tr)/2;
> 		build(arr, v*2,tl,tm);
> 		build(arr,v*2+1,tm+1, tr);
> 		t[v] = combine(t[v*2] , t[v*2+1]);
> 	}
> }
> 
> ll query(ll v, ll tl, ll tr, ll l, ll r)
> {
> 	if(l>r)
> 	{
> 		return DEF;
> 	}
> 	if(l == tl && r==tr)
> 	{
> 		return t[v];
> 	}
> 	else{
> 		ll tm = (tl+tr)/2;
> 		return combine(query(v*2, tl, tm , l ,min(r,tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
> 	}
> }
> 
> void update(ll v, ll tl, ll tr, ll pos, ll new_val)
> {
> 	if(tl == tr)
> 	{
> 		t[v] = new_val;
> 	}
> 	else{
> 		ll tm = (tl+tr)/2;
> 		if(pos<=tm)
> 		{
> 			update(v*2, tl, tm, pos, new_val);
> 		}
> 		else{
> 			update(v*2+1, tm+1, tr, pos, new_val);
> 		}
> 		t[v] = combine(t[v*2] , t[v*2+1]);
> 	}
> }
> ```



