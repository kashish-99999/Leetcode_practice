class Solution {
    public String removeOuterParentheses(String s) {
        int l=s.length();
        int c=0;
        String str="";
        for(int i=0;i<l;i++)
        {
            char ch=s.charAt(i);
            if(ch=='(')
            {
                if(c>0)
                str=str+ch;
            c++;
            }
            else
            {
                c--;
                if(c>0)
                str=str+ch;

        }
       
    }
    return str;
}
};