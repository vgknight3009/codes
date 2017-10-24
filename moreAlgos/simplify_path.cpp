class Solution {
public:
    string simplifyPath(string path) {
        
        string temp,str="";
        vector<string> stk;
        
        int l=path.size();
        stringstream ss(path);
        int c=1;
        while(getline(ss,temp,'/')){
            
          //  cout<<c++<<"--"<<temp<<"\n";
            if(temp=="" || temp==".")
                continue;
            if(temp==".." && !stk.empty())
                stk.pop_back();
            else if(temp!="..")
                stk.push_back(temp);
            
        }
        int k=stk.size();
        for(int i=0;i<k;i++)
        {
            str+='/';
            str+=stk[i];
        }
        if(str=="")
            return "/";
        return str;
        
        
        
    }
};
