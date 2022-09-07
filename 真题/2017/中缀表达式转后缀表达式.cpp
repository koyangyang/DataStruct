void Trans(string InOrder)
{
    string PostOrder;//存储后缀表达式
    stack<char> sta;
    int len = InOrder.size();
    for (int i = 0; i < len; ++i) {
        char now = InOrder[i];
        if(IsOp(now)){//IsOp函数用于判断当前元素是否为运算符
            int prior=GetPrior(now);//返回当前操作数的优先级
            while(!sta.empty())//当栈非空时
            {
                char top=sta.top();//获取栈顶元素
                //跟栈顶元素优先级进行比较，若优先级小于等于栈顶元素则弹出栈顶元素，加入后缀表达式
                if(prior<=GetPrior(top))
                {
                    PostOrder.pust_back(top);
                    sta.pop();
                }else
                    break;//否则退出循环
            }
            sta.push(now);//将操作数加入栈中
        }
        else//若为操作数直接加入后缀表达式
            PostOrder.push_back(now);
    }
    while(!sta.empty())//结束时栈非空，把剩余元素加入后缀表达式
    {
        char top=sta.top();
        sta.pop();
        PostOrder.push_back(top);
    }
}