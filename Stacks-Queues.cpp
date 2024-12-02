#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

// Add class Stack here
class Stack
{
private:
    std::vector<std::pair<char, int>> stack;

    void push(std::vector<std::pair<char, int>>& a, std::pair<char, int> b)
    {
        a.push_back(b);
    }

    std::pair<char, int> top(std::vector<std::pair<char, int>>& a)
    {
        if (a.empty())
        {
            return std::make_pair('\0', -1);
        }
        return a.back();
    }

    void pop(std::vector<std::pair<char, int>>& a)
    {
        if (!a.empty())
        {
            a.pop_back();
        }
    }

    bool match(char a, char b)
    {
        if (a == '(' && b == ')')
        {
            return true;
        }
        else if (a == '[' && b == ']')
        {
            return true;
        }
        else if (a == '{' && b == '}')
        {
            return true;
        }
        return false;
    }

    bool isOpen(char a)
    {
        return a == '(' || a == '[' || a == '{';
    }

    bool isClose(char a)
    {
        return a == ')' || a == ']' || a == '}';
    }

public:
    void validPara(std::string pairs)
    {
        std::vector<std::pair<char, int>> s;
        for (int i = 0; i < pairs.length(); i++)
        {
            if (isOpen(pairs[i]))
            {
                push(s, std::make_pair(pairs[i], i));
            }
            else if (isClose(pairs[i]))
            {
                if (!s.empty() && match(top(s).first, pairs[i]))
                {
                    pop(s);
                }
                else
                {
                    std::cout << "Invalid\n";
                    return;
                }
            }
        }
        if (s.empty())
        {
            std::cout << "Valid\n";
        }
        else
        {
            std::cout << "Invalid\n";
        }
    }

    int indexError(std::string pairs)
    {
        std::vector<std::pair<char, int>> s;
        for (int i = 0; i < pairs.length(); i++)
        {
            if (isOpen(pairs[i]))
            {
                push(s, std::make_pair(pairs[i], i));
            }
            else if (isClose(pairs[i]))
            {
                if (!s.empty() && match(top(s).first, pairs[i]))
                {
                    pop(s);
                }
                else
                {
                    return i;
                }
            }
        }
        if (!s.empty())
        {
            return s.back().second;
        }
        return -1;
    }

    void minPara(std::string pairs)
    {
        int count = 0;
        std::vector<std::pair<char, int>> s;
        for (int i = 0; i < pairs.length(); i++)
        {
            if (isOpen(pairs[i]))
            {
                push(s, std::make_pair(pairs[i], i));
            }
            else if (isClose(pairs[i]))
            {
                if (!s.empty() && match(top(s).first, pairs[i]))
                {
                    pop(s);
                }
                else
                {
                    count++;
                }
            }
        }
        count += s.size();
        std::cout << count << std::endl;
    }

    void scorePara(std::string pairs)
    {
        int score = 0;
        std::vector<std::pair<char, int>> s;
        for (int i = 0; i < pairs.length(); i++)
        {
            if (isOpen(pairs[i]))
            {
                push(s, std::make_pair(pairs[i], i));
            }
            else if (isClose(pairs[i]))
            {
                if (!s.empty() && match(top(s).first, pairs[i]))
                {
                    pop(s);
                    score += 2;
                }
            }
        }
        std::cout << score << std::endl;
    }
};

// Add class Queue here
class Queue
{
private:
    std::vector<std::string> queue;

    std::string pop()
    {
        auto a = queue[0];
        queue.erase(queue.begin());
        return a;
    }

    std::string reverse(std::string s)
    {
        std::string a = "";
        for (int i = s.size() - 1; i >= 0; i--)
        {
            a += s[i];
        }
        return a;
    }

public:
    void enqueue(std::string s)
    {
        queue.push_back(s);
    }

    void processMsg()
    {
        if (!queue.empty())
        {
            std::string msg = pop();
            std::cout << reverse(msg) << std::endl;
        }
    }
};

// Remove comments before testing and do not change anything in main function
int main(){
    Stack s1;
    s1.validPara("(([]))");
    s1.minPara("(([]))");
    s1.scorePara("(([]))");
    s1.validPara("(([])");
    std::cout << s1.indexError("(([))") << std::endl;
    s1.minPara("(([])");
    s1.validPara("(([{}))");
    std::cout << s1.indexError("(([[}])") << std::endl;
    s1.minPara("(([{}))");
    s1.scorePara("(([{}))");
    std::cout << s1.indexError("({}[]()[)") << std::endl;
    s1.validPara("(([))");
    s1.minPara("(([))");
    std::cout << s1.indexError("[({)]") << std::endl;
    s1.validPara("(([{[{({})}]}]))");
    s1.minPara("(([{[{({})}]}]))");
    s1.scorePara("(([{[{({})}]}]))");
    s1.validPara("(([[{[{({})}]))");
    s1.validPara("(([[{[{({})}]}])]))");
    s1.scorePara("(([[{[{({})}]}])]))");
    std::cout << s1.indexError("(([[{{({})]}])]))") << std::endl;
    s1.validPara("(())");
    s1.validPara("(())");
    s1.validPara("void function(){}");
    s1.scorePara("void function(){}");
    s1.validPara("void function(");
    s1.minPara("void function(");
    s1.validPara("void function(std::string expre){if(expre){return 1;}else{return 0;}}");
    s1.scorePara("void function(std::string expre){if(expre){return 1;}else{return 0;}}");
    s1.validPara("void function(std::string expre){if(expre){return 1;}else{return 0;}");
    s1.validPara("void function(std::string expre){if(expre){return 1;else{return 0;");
    s1.minPara("void function(std::string expre){if(expre){return 1;else{return 0;");
    std::cout << s1.indexError("void function(std::string expre){if(expre){return 1;else{return 0;") << std::endl;
    Queue q1;
    q1.enqueue("This is a secure message.");
    q1.processMsg();
    q1.enqueue("The product I received is damaged. What should I do?");
    q1.processMsg();
    q1.enqueue("I need assistance with setting up my new device");
    q1.processMsg();
    q1.enqueue("The website is not loading properly on my browser.");
    q1.processMsg();
    q1.enqueue("I accidentally placed the wrong order. Can it be canceled?");
    q1.processMsg();
    q1.enqueue("This is your project3. Have a happy thanksgiving!!! Hahaha");
    q1.processMsg();
    q1.enqueue("I forgot my password and can't reset it. Help, please! Do you provide technical support for mobile devices?");
    q1.processMsg();
    q1.enqueue("The software update is causing issues on my computer. The response time on your website is very slow.");
    q1.processMsg();
    return 0;
}
