/***********************************
 *       Sum of Two Integers
 ***********************************/

//  Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
//  
//  Example:
//  Given a = 1 and b = 2, return 3.

class Solution {
public:
     int getSum( int a, int b) {
        int bmap[] = {0,1,1,2,1,2,2,3 };
        unsigned int c = 0, m,n,o;
        int ua = (unsigned int)a, ub = (unsigned int)b;
        for (int i=0; i<32; i++) {
            m = (ua >> i) & 1 ;
            n = (ub >> i) & 1;
            o = m<<2 | n<<1 | c;
            switch (bmap[o]) {
                case 0: c=0; break;
                case 1: ua |= 1 << i; c=0; break;
                case 2: ua &= ~(1 << i); c=1; break;
                case 3: ua |= 1 << i; c=1; break;
            }
        }
        return (int)ua;
    }
};
