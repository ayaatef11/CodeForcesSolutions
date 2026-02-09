#include <iostream>
using namespace std;
int recurr(int i,int j, int isTrue, string & exp ) {
    if (i>j)return 0;
    if (i==j) {
        if (isTrue) return exp[i]=='T';
        else return exp[i]=='F';
    }
    int ways=0;
    for (int idx=i+1;idx<=j-1;idx+=2) {//idx+=2 as expresions are in odd places
        int lt=recurr(i,idx-1,1,exp);
        int lf=recurr(i,idx-1,0,exp);
        int rt=recurr(idx+1,j,1,exp);
        int rf=recurr(idx+1,j,0,exp);
        if (exp[idx]=='&') {
            if (isTrue)ways +=rt*lt;//to make the answer is true the left and right should be 1
            else ways+= rt*lf + rf*lt + rf*lf;
        }else if (exp[idx]=='|') {
            if (isTrue)ways += lt*rt+ lt*rf + lf*rt;
            else ways+= rf*lf;
        }else {
            if (isTrue)ways+= lt*rf + lf*rt;
            else ways += lt*rt + lf*rf;
        }
    }
    return ways;
}
int  main() {
    string exp = "T|F&T^T";

    int n = exp.size();

    int result = recurr(0, n - 1, 1, exp);

    cout << result << endl;
}