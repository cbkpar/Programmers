class Solution {
    public String solution(int[] numbers, String hand) {
        StringBuilder sb = new StringBuilder();
        int lx,ly,rx,ry,sz,i,dl,dr;
        lx = 0;
        ly = 0;
        rx = 2;
        ry = 0;
        int[] x = {1,0,1,2,0,1,2,0,1,2};
        int[] y = {0,3,3,3,2,2,2,1,1,1};
        sz = numbers.length;
        for(i=0;i<sz;i++){
            if((numbers[i]+2)%3==0){
                lx = x[numbers[i]];
                ly = y[numbers[i]];
                sb.append("L");
            }else if(numbers[i]%3==0&&numbers[i]!=0){
                rx = x[numbers[i]];
                ry = y[numbers[i]];
                sb.append("R");
            }else{
                dl = Math.abs(lx-x[numbers[i]])+Math.abs(ly-y[numbers[i]]);
                dr = Math.abs(rx-x[numbers[i]])+Math.abs(ry-y[numbers[i]]);
                if(dl==dr){
                    if(hand.equals("left")){
                        lx = x[numbers[i]];
                        ly = y[numbers[i]];
                        sb.append("L");
                    }else{
                        rx = x[numbers[i]];
                        ry = y[numbers[i]];
                        sb.append("R");
                    }
                }else if(dl<dr){
                    lx = x[numbers[i]];
                    ly = y[numbers[i]];
                    sb.append("L");
                }else{
                    rx = x[numbers[i]];
                    ry = y[numbers[i]];
                    sb.append("R");
                }
            }
        }
        return sb.toString();
        }
}
