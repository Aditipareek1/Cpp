#include<bits/stdc++.h>
#include<fstream>
using namespace std;

multimap<int, string, greater<int>> sort(unordered_map<string, int>& M)
{
    multimap<int, string, greater<int>> MM;
    for (auto& it : M)
    {
        MM.insert({ it.second, it.first });
    }
    return MM;
}

void read(vector<string> &tweets)
{
    ifstream newfile;
    newfile.open("tweets.txt");
    if(!newfile.is_open())
    {
        cout<<"file is not opening";
    }
    else
    {
        string tweet;
        while(getline(newfile, tweet))
        {
            tweets.push_back(tweet);
        }

        newfile.close();
    }
}

int findlikes(string s)
{
    int index = s.find_last_of('\t');
    index++;
    string li = "";
    while(index<s.size())
    {
        li+=s[index];
        index++;
    }
    int likes = stoi(li);
    return likes;
}

void Solution(vector<string> tweets, string r)
{
    unordered_map<string,int> m;
    int n = tweets.size();
    for(int i=1; i<n; i++)
    {

        int pos=1;
        string user= "";
        char ch='@';
        string tweet = tweets[i];
        int likes = findlikes(tweet);
        while(tweet[pos]!='\t')
        {
            pos++;
        }
        user = tweet.substr(0,pos);
        m[user]+=likes*10;
        int index=pos;
        while((index = tweet.find(ch, index+1))!=-1)
        {
            index++;
            string username = "";
            username+='@';
            while(index < tweet.size())
            {
                char c = tweet[index];
                if(c=='_' || (c<='z' && c>='a') || (c<='Z' && c>='A') || (isdigit(c)))
                {
                    username+=c;
                }
                else break;
                index++;
            }
            m[username]+=(5*likes)+50;
        }
    }
    multimap<int, string, greater<int>> mm = sort(m);
    int cnt=1;
    cout<<"                 RANK :"<<endl<<endl;
    for(auto i : mm)
    {
        if(r=="?")
            cout<<"                 "<<cnt<<"      "<<i.second<<"           "<<i.first<<endl<<endl;
        else if(i.second == r)
        {
            cout<<"                 "<<cnt<<"      "<<i.second<<"           "<<i.first<<endl<<endl;
        }
        cnt++;
    }
}

int main()
{

    cout<<"\\<> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <>/"<<endl;
    cout<<" \\<> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> /"<<endl;
    cout<<"  \\<> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <>  / "<<endl;
    cout<<"   --------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                       ||  WELCOME TO PERSON RANK  ||                   "<<endl;
    cout<<"   --------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"  /<> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <>  \\"<<endl;
    cout<<" /<> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> \\"<<endl;
    cout<<"/<> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <> <>\\"<<endl;
    char i=0;

    while(i!='3')
    {
        vector<string> tweets;
        tweets.push_back(" ");
        cout<<"_____________________________________________________________________________________________________________"<<endl<<endl;
        cout<<"                            ||  Press 1 to check the Complete Ranking List     ||"<<endl;
        cout<<"                            ||  Press 2 to see the rank of a Specific username ||"<<endl;
        cout<<"                            ||  Press 3 to exit                                ||"<<endl;
        cout<<"_____________________________________________________________________________________________________________"<<endl<<endl;
        cin>>i;
        switch(i)
        {
        case '1':
            read(tweets);
            Solution(tweets,"?");
            break;
        case '2':
        {
            cout<<"enter the user name in @abc format"<<endl;
            string username;
            cin>>username;
            read(tweets);
            Solution(tweets, username);
        }
        break;
        case '3':
            exit;
        default:
            cout<<endl<<"Invalid input please try again"<<endl;
        }
    }
    cout<<endl<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
    cout<<"                                              || THANK YOU ||"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
}
