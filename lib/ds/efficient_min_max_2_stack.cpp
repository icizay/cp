struct Stack{
	stack<ll> items, mx, mn;
	Stack(){ mx.push(0), mn.push(1e18); } 
	void push(ll x){
		items.push(x);
		mx.push(std::max(mx.top(), x));
		mn.push(std::min(mn.top(), x));
	}
	void pop(){
		if(items.empty()) return;
		items.pop();
		mx.pop();
		mn.pop();
	}
	ll top(){ return items.top(); }
	ll max(){ return mx.top(); }
	ll min(){ return mn.top(); }
	ll empty(){ return items.empty(); }
};

struct Queue{
	Stack s1, s2;
	void push(ll x){ s1.push(x); }
	void pour(){
		if(s2.empty()){
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
		}
	}
	ll front(){
		if(s2.empty()) pour();
		if(s2.empty()) return -1;
		return s2.top();
	}
	void pop(){
		if(s2.empty()) pour();
		if(!s2.empty()) s2.pop();
	}
	ll max(){ return std::max(s1.max(), s2.max()); }
	ll min(){ return std::min(s1.min(), s2.min()); }
};
