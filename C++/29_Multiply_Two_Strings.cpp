// https://practice.geeksforgeeks.org/problems/multiply-two-strings/1/?page=1&category[]=Mathematical&sortBy=submissions#

string multiplyStrings(string s1, string s2) {
       
        int l1 = s1.length(), l2 = s2.length();
        int minus = 0;
            
        if(s1[0] == '-')
        {
            minus++;
            s1 = s1.substr(1, --l1);
        }
        
        if(s2[0] == '-')
        {
            minus++;
            s2 = s2.substr(1, --l2);
        }

       int result[l1 + l2] = {0};
       string ans = "";
       
       for(int i = l1 - 1; i >= 0; --i)
       {
           int num1 = s1[i] - '0';
           for(int j = l2 - 1; j >= 0; --j)
           {
               int num2 = s2[j] - '0';
               int product = num1 * num2;
               product += result[i + j + 1];
               result[i + j + 1] = product % 10;
               result[i + j] += product / 10;
           }
        }
       
        int flag = 0;
        for(int i = 0; i < l1 + l2; ++i)
        {
            if(result[i] == 0 && flag == 0)
                continue;
            flag = 1;
            ans += result[i] + '0';
        }
            
        if(ans.length() == 0)
            ans += "0";
        else if(minus == 1)
            ans = "-" + ans;
            
        return ans;
    }
