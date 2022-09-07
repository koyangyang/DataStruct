int get_priority(char s)
{
	if(s=='+'||s=='-') return 1;
	else return 2;
}
int get_result(int x,int y,char s)
{
	if(s=='+') return x+y;
	if(s=='-') return x-y;
	if(s=='*') return x*y;
	if(s=='/') return x/y;
}
int compute(string str)
{
	int len=str.length();
	for(int i=0;i<len;i++){
		if(str[i]>='0'&&str[i]<='9')
			stk1.push(str[i]-'0');
		else
		{
			if(get_priority(str[i])>get_priority(stk1.top()))
			{
				stk1.push(str[i]);
			}else
			{
				while(get_priority(str[i])<=get_priority(stk1.top()))
				{
					y=stk2.top();stk2.pop();
					x=stk2.top();stk2.pop();
					int result=get_result(x,y,stk1.top());
					cout<<result<<endl;
					stk2.push(result);
					stk1.pop();
				}
				stk1.push(str[i]);
			}
		}	
	}
	while(!stk1.empty()){
		char c=stk1.top();stk1.pop();
		y=stk2.top();stk2.pop();
		x=stk2.top();stk2.pop();
		int result=get_result(x,y,c);
		stk2.push(result);
	}
	return stk2.top();
}
