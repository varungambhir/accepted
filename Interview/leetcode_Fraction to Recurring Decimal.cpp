
#define ll long long int
class Solution {
public:
    string num2str(long int a) {
        if(!a) return "0";
        //cout << a << " ";
        a = abs(a);
        string c = "";
        while(a > 0) {
            c += (char)(a%10+'0');
            a /= 10;
        }
        reverse(c.begin(), c.end());
        c+="";
        //cout << c << endl;
        return c;
    }

     string num2str_2(long a){
        if (a<0){a = -a;}
        ostringstream os;
        os << a;
        return os.str();
    }

    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator || !denominator)
            return "0";
        bool pos;
        ll nums = (ll)numerator * (ll)denominator;
        if(nums >=0 ) pos = true;
        else pos = false;

        long  int n = abs(numerator);
        long  int d = abs(denominator);
        int l = -1;
        vector<string> res;
        vector<string> mod;
        int maxlen = 1000;
        
        while(mod.size() < 1000) {
            
            long int t = n/d;
            res.push_back(num2str(t));
            long int m = n%d;
            if(m == 0)break;
            
            for(int i = 0; i < mod.size() ;i++) {
                if(mod[i] == num2str(m)) {
                    l = i;
                    break;
                }
            }
            
            if(l == -1) {
                mod.push_back(num2str(m));
                n = m * 10;
            } else {
                break;
            }
            
        }
        
        string r = "";
        
        if(res.size() == 1) {
            r = res[0];
        } else {
            r = res[0] + ".";
            
            for(int i = 1; i < res.size(); i++) {
                if(i == l+1) {
                    r += "(";
                }
                r += res[i];
            }
            if(l != -1) {
                r += ")";
            }
        }
        
        if(pos) {
            return r;
        } else {
            return "-"+r;
        }
        
    }
};