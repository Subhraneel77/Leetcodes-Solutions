class CustomStack {
public:
    int s[1000];
    int top, maxSz, sz;
    CustomStack(int maxSize): top(-1), maxSz(maxSize){}
    
    void push(int x) {
        if (top==maxSz-1) return;
        s[++top]=x;
    }
    
    int pop() {
        if (top==-1) return -1;
        return s[top--];
    }
    
    void increment(int k, int val) {
        int k0=min(k, top+1);
        for(int i=0; i<k0; i++)
            s[i]+=val;
    }
};