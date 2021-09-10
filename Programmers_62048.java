class Solution {
    public long solution(int w, int h) {
        long t = (long)w*h;
        long g = w>h?gcd(h,w):gcd(w,h);
        w /= g;
        h /= g;
        return t-(w+h-1)*g;
    }
    
    public long gcd(long a, long b){
        if(b%a==0) return a;
        return gcd(b%a,a);
    }
}
