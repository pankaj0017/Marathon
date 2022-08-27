// https://leetcode.com/problems/interleaving-string/

class Solution {
public:
    int flag[101][101][201];
    bool rec(string s1, string s2, string s3, int s1p, int s2p, int s3p) {
        if (s1p < s1.length() && s1[s1p] == s3[s3p]) {
            if (s3p == s3.length()-1) return true;
            
            if (flag[s1p+1][s2p][s3p+1] == 1) return true;
            
            if(flag[s1p+1][s2p][s3p+1] == -1 && rec(s1, s2, s3, s1p+1, s2p, s3p+1)) {
                flag[s1p+1][s2p][s3p+1] = 1;
                return true;
            } else {
                flag[s1p+1][s2p][s3p+1] = 0;
            }
        }
        if (s2p < s2.length() && s2[s2p] == s3[s3p]) {
            if (s3p == s3.length()-1) return true;
            
            if (flag[s1p][s2p+1][s3p+1] == 1) return true;
            
            if(flag[s1p][s2p+1][s3p+1] == -1 && rec(s1, s2, s3, s1p, s2p+1, s3p+1)) {
                flag[s1p][s2p+1][s3p+1] = 1;
                return true;
            } else {
                flag[s1p][s2p+1][s3p+1] = 0;
            }
        }
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() == 0 && s2.length() == 0 && s3.length() == 0) return true;
        if (s1.length() + s2.length() != s3.length()) return false;
        for (int i = 0; i < 101 ; i++)
            for (int j = 0; j < 101 ; j++)
                for (int k = 0; k < 201 ; k++) flag[i][j][k] = -1;
        return rec(s1, s2, s3, 0, 0, 0);
    }
};
